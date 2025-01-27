#include "imgui_notify.h"
#include "imgui.h"

namespace ImGui
{
    std::vector<ImGuiToast> notifications{};

    /**
     * Inserts a new notification into the notification queue.
     * @param toast The notification to be inserted.
     */
    void InsertNotification(const ImGuiToast& toast)
    {
        notifications.push_back(toast);
        IM_ASSERT(notifications.size() > 0);
    }

    void InsertNotification(ImGuiToastType type, int dismissTime, const char* title, const char* buttonLabel, const void* onButtonPress,
        const char* fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        ImGuiToast toast(type, dismissTime, buttonLabel, reinterpret_cast<std::function<void()>&>(onButtonPress), fmt, args);
        toast.setTitle(title);
        va_end(args);
        InsertNotification(toast);
    }

    void InsertNotificationV(ImGuiToastType type, int dismissTime, const char* title, const char* buttonLabel, const void* onButtonPress,
        const char* fmt, va_list args)
    {
        ImGuiToast toast(type, dismissTime, buttonLabel, reinterpret_cast<std::function<void()>&>(onButtonPress), fmt, args);
        toast.setTitle(title);
        InsertNotification(toast);
    }

    /**
     * @brief Removes a notification from the list of notifications.
     *
     * @param index The index of the notification to remove.
     */
    void RemoveNotification(int index)
    {
        notifications.erase(notifications.begin() + index);
    }

    /**
     * Renders all notifications in the notifications vector.
     * Each notification is rendered as a toast window with a title, content and an optional icon.
     * If a notification is expired, it is removed from the vector.
     */
    void RenderNotifications()
    {
        const ImVec2 mainWindowSize = GetMainViewport()->Size;

        float height = 0.f;

        for (size_t i = 0; i < notifications.size(); ++i)
        {
            ImGuiToast* currentToast = &notifications[i];

            IM_ASSERT(currentToast != nullptr);

            // Remove toast if expired
            if (currentToast->getPhase() == ImGuiToastPhase::Expired)
            {
                RemoveNotification(i);
                continue;
            }

#if NOTIFY_RENDER_LIMIT > 0
            if (i > NOTIFY_RENDER_LIMIT)
            {
                continue;
            }
#endif

            // Get icon, title and other data
            const char* icon = currentToast->getIcon();
            const char* title = currentToast->getTitle();
            const char* content = currentToast->getContent();
            const char* defaultTitle = currentToast->getDefaultTitle();
            const float opacity = currentToast->getFadePercent(); // Get opacity based of the current phase

            // Window rendering
            ImVec4 textColor = currentToast->getColor();
            textColor.w = opacity;

            // Generate new unique name for this toast
            char windowName[50];
#ifdef _WIN32
            sprintf_s(windowName, "##TOAST%d", (int)i);
#elif defined(__linux__) || defined(__EMSCRIPTEN__)
                std::sprintf(windowName, "##TOAST%d", (int)i);
#elif defined (__APPLE__)
                std::snprintf(windowName, 50, "##TOAST%d", (int)i);
#else
                throw "Unsupported platform";
#endif

            //PushStyleColor(ImGuiCol_Text, textColor);
            SetNextWindowBgAlpha(opacity);

#if NOTIFY_RENDER_OUTSIDE_MAIN_WINDOW
            short mainMonitorId = static_cast<ImGuiViewportP*>(GetMainViewport())->PlatformMonitor;

            ImGuiPlatformIO& platformIO = GetPlatformIO();
            ImGuiPlatformMonitor& monitor = platformIO.Monitors[mainMonitorId];

            // Set notification window position to bottom right corner of the monitor

            SetNextWindowPos(
                ImVec2(monitor.WorkPos.x + monitor.WorkSize.x - NOTIFY_PADDING_X,
                       monitor.WorkPos.y + monitor.WorkSize.y - NOTIFY_PADDING_Y - height), ImGuiCond_Always,
                ImVec2(1.0f, 1.0f));
#else
                // Set notification window position to bottom right corner of the main window, considering the main window size and location in relation to the display
                ImVec2 mainWindowPos = GetMainViewport()->Pos;
                SetNextWindowPos(ImVec2(mainWindowPos.x + mainWindowSize.x - NOTIFY_PADDING_X, mainWindowPos.y + mainWindowSize.y - NOTIFY_PADDING_Y - height), ImGuiCond_Always, ImVec2(1.0f, 1.0f));
#endif

            // Set notification window flags
            if (!NOTIFY_USE_DISMISS_BUTTON && currentToast->getOnButtonPress() == nullptr)
            {
                currentToast->setWindowFlags(NOTIFY_DEFAULT_TOAST_FLAGS | ImGuiWindowFlags_NoInputs);
            }

            Begin(windowName, nullptr, currentToast->getWindowFlags());

            // Render over all other windows
            BringWindowToDisplayFront(GetCurrentWindow());

            // Here we render the toast content
            {
                PushTextWrapPos(mainWindowSize.x / 3.f);
                // We want to support multi-line text, this will wrap the text after 1/3 of the screen width

                bool wasTitleRendered = false;

                // If an icon is set
                if (!NOTIFY_NULL_OR_EMPTY(icon))
                {
                    //Text(icon); // Render icon text
                    TextColored(textColor, "%s", icon);
                    wasTitleRendered = true;
                }

                // If a title is set
                if (!NOTIFY_NULL_OR_EMPTY(title))
                {
                    // If a title and an icon is set, we want to render on same line
                    if (!NOTIFY_NULL_OR_EMPTY(icon))
                        SameLine();

                    Text("%s", title); // Render title text
                    wasTitleRendered = true;
                }
                else if (!NOTIFY_NULL_OR_EMPTY(defaultTitle))
                {
                    if (!NOTIFY_NULL_OR_EMPTY(icon))
                        SameLine();

                    Text("%s", defaultTitle); // Render default title text (ImGuiToastType_Success -> "Success", etc...)
                    wasTitleRendered = true;
                }

                // If a dismiss button is enabled
                if (NOTIFY_USE_DISMISS_BUTTON)
                {
                    // If a title or content is set, we want to render the button on the same line
                    if (wasTitleRendered || !NOTIFY_NULL_OR_EMPTY(content))
                    {
                        SameLine();
                    }

                    // Render the dismiss button on the top right corner
                    // NEEDS TO BE REWORKED
                    float scale = 0.8f;

                    if (CalcTextSize(content).x > GetContentRegionAvail().x)
                    {
                        scale = 0.8f;
                    }

                    SetCursorPosX(GetCursorPosX() + (GetWindowSize().x - GetCursorPosX()) * scale);

                    // If the button is pressed, we want to remove the notification
                    if (Button(ICON_FA_XMARK))
                    {
                        RemoveNotification(i);
                    }
                }

                // In case ANYTHING was rendered in the top, we want to add a small padding so the text (or icon) looks centered vertically
                if (wasTitleRendered && !NOTIFY_NULL_OR_EMPTY(content))
                {
                    SetCursorPosY(GetCursorPosY() + 5.f); // Must be a better way to do this!!!!
                }

                // If a content is set
                if (!NOTIFY_NULL_OR_EMPTY(content))
                {
                    if (wasTitleRendered)
                    {
#if NOTIFY_USE_SEPARATOR
                            Separator();
#endif
                    }

                    Text("%s", content); // Render content text
                }

                // If a button is set
                if (currentToast->getOnButtonPress() != nullptr)
                {
                    // If the button is pressed, we want to execute the lambda function
                    if (Button(currentToast->getButtonLabel()))
                    {
                        currentToast->getOnButtonPress()();
                    }
                }

                PopTextWrapPos();
            }

            // Save height for next toasts
            height += GetWindowHeight() + NOTIFY_PADDING_MESSAGE_Y;

            // End
            End();
        }
    }
}
