
static const ImGuiWindowFlags NOTIFY_DEFAULT_TOAST_FLAGS = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoFocusOnAppearing;
enum class ImGuiToastType : uint8_t
{
    None,
    Success,
    Warning,
    Error,
    Info,
    COUNT
};
enum class ImGuiToastPhase : uint8_t
{
    FadeIn,
    Wait,
    FadeOut,
    Expired,
    COUNT
};
enum class ImGuiToastPos : uint8_t
{
    TopLeft,
    TopCenter,
    TopRight,
    BottomLeft,
    BottomCenter,
    BottomRight,
    Center,
    COUNT
};
class ImGuiToast
{
private:
    ImGuiWindowFlags flags = NOTIFY_DEFAULT_TOAST_FLAGS;
    ImGuiToastType type = ImGuiToastType::None;
    char title[4096];
    char content[4096];
    int dismissTime = 3000;
    std::chrono::system_clock::time_point creationTime = std::chrono::system_clock::now();
    std::function<void()> onButtonPress = nullptr;
    char buttonLabel[4096];
private:
    inline void setTitle(const char* format, va_list args)
    {
        vsnprintf(this->title, sizeof(this->title), format, args);
    }
    inline void setContent(const char* format, va_list args)
    {
        vsnprintf(this->content, sizeof(this->content), format, args);
    }
    inline void setButtonLabel(const char* format, va_list args)
    {
        vsnprintf(this->buttonLabel, sizeof(this->buttonLabel), format, args);
    }
public:
    inline void setTitle(const char* format, ...)
    {
        if (format) {va_list args; va_start(args, format); this->setTitle(format, args); va_end(args);};
    }
    inline void setContent(const char* format, ...)
    {
        if (format) {va_list args; va_start(args, format); this->setContent(format, args); va_end(args);};
    }
    inline void setType(const ImGuiToastType& type)
    {
        IM_ASSERT(type < ImGuiToastType::COUNT);
        this->type = type;
    };
    inline void setWindowFlags(const ImGuiWindowFlags& flags)
    {
        this->flags = flags;
    }
    inline void setOnButtonPress(const std::function<void()>& onButtonPress)
    {
        this->onButtonPress = onButtonPress;
    }
    inline void setButtonLabel(const char* format, ...)
    {
        if (format) {va_list args; va_start(args, format); this->setButtonLabel(format, args); va_end(args);};
    }
public:
    inline const char* getTitle()
    {
        return this->title;
    };
    inline const char* getDefaultTitle()
    {
        if (!strlen(this->title))
        {
            switch (this->type)
            {
            case ImGuiToastType::None:
                return nullptr;
            case ImGuiToastType::Success:
                return "Success";
            case ImGuiToastType::Warning:
                return "Warning";
            case ImGuiToastType::Error:
                return "Error";
            case ImGuiToastType::Info:
                return "Info";
            default:
                return nullptr;
            }
        }
        return this->title;
    };
    inline ImGuiToastType getType()
    {
        return this->type;
    };
    inline ImVec4 getColor()
    {
        switch (this->type)
        {
        case ImGuiToastType::None:
            return {255, 255, 255, 255};
        case ImGuiToastType::Success:
            return {0, 255, 0, 255};
        case ImGuiToastType::Warning:
            return {255, 255, 0, 255};
        case ImGuiToastType::Error:
            return {255, 0, 0, 255};
        case ImGuiToastType::Info:
            return {0, 157, 255, 255};
        default:
            return {255, 255, 255, 255};
        }
    }
    inline const char* getIcon()
    {
        switch (this->type)
        {
        case ImGuiToastType::None:
            return nullptr;
        case ImGuiToastType::Success:
            return "\xef\x81\x98";
        case ImGuiToastType::Warning:
            return "\xef\x81\xb1";
        case ImGuiToastType::Error:
            return "\xef\x81\xaa";
        case ImGuiToastType::Info:
            return "\xef\x81\x9a";
        default:
            return nullptr;
        }
    }
    inline char* getContent()
    {
        return this->content;
    };
    inline std::chrono::nanoseconds getElapsedTime()
    {
        return std::chrono::system_clock::now() - this->creationTime;
    }
    inline ImGuiToastPhase getPhase()
    {
        const int64_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(getElapsedTime()).count();
        if (elapsed > 150 + this->dismissTime + 150)
        {
            return ImGuiToastPhase::Expired;
        } else
        if (elapsed > 150 + this->dismissTime)
        {
            return ImGuiToastPhase::FadeOut;
        } else
        if (elapsed > 150)
        {
            return ImGuiToastPhase::Wait;
        } else
        {
            return ImGuiToastPhase::FadeIn;
        }
    }
    inline float getFadePercent()
    {
        const ImGuiToastPhase phase = getPhase();
        const int64_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(getElapsedTime()).count();
        if (phase == ImGuiToastPhase::FadeIn)
        {
            return ((float)elapsed / (float)150) * 0.8f;
        } else
        if (phase == ImGuiToastPhase::FadeOut)
        {
            return (1.f - (((float)elapsed - (float)150 - (float)this->dismissTime) / (float)150)) * 0.8f;
        }
        return 1.f * 0.8f;
    }
    inline ImGuiWindowFlags getWindowFlags()
    {
        return this->flags;
    }
    inline std::function<void()> getOnButtonPress()
    {
        return this->onButtonPress;
    }
    inline const char* getButtonLabel()
    {
        return this->buttonLabel;
    }
public:
    ImGuiToast(ImGuiToastType type, int dismissTime = 3000)
    {
        IM_ASSERT(type < ImGuiToastType::COUNT);
        this->type = type;
        this->dismissTime = dismissTime;
        this->creationTime = std::chrono::system_clock::now();
        memset(this->title, 0, sizeof(this->title));
        memset(this->content, 0, sizeof(this->content));
    }
    ImGuiToast(ImGuiToastType type, const char* format, ...) : ImGuiToast(type)
    {
        if (format) {va_list args; va_start(args, format); this->setContent(format, args); va_end(args);};
    }
    ImGuiToast(ImGuiToastType type, int dismissTime, const char* format, ...) : ImGuiToast(type, dismissTime)
    {
        if (format) {va_list args; va_start(args, format); this->setContent(format, args); va_end(args);};
    }
    ImGuiToast(ImGuiToastType type, int dismissTime, const char* buttonLabel, const std::function<void()>& onButtonPress, const char* format, ...) : ImGuiToast(type, dismissTime)
    {
        if (format) {va_list args; va_start(args, format); this->setContent(format, args); va_end(args);};
        this->onButtonPress = onButtonPress;
        this->setButtonLabel(buttonLabel);
    }
};
namespace ImGui
{
    inline std::vector<ImGuiToast> notifications;
    inline void InsertNotification(const ImGuiToast& toast)
    {
        notifications.push_back(toast);
    }
    inline void RemoveNotification(int index)
    {
        notifications.erase(notifications.begin() + index);
    }
    inline void RenderNotifications()
    {
        const ImVec2 mainWindowSize = GetMainViewport()->Size;
        float height = 0.f;
        for (size_t i = 0; i < notifications.size(); ++i)
        {
            ImGuiToast* currentToast = &notifications[i];
            if (currentToast->getPhase() == ImGuiToastPhase::Expired)
            {
                RemoveNotification(i);
                continue;
            }
                if (i > 5)
                {
                    continue;
                }
            const char* icon = currentToast->getIcon();
            const char* title = currentToast->getTitle();
            const char* content = currentToast->getContent();
            const char* defaultTitle = currentToast->getDefaultTitle();
            const float opacity = currentToast->getFadePercent();
            ImVec4 textColor = currentToast->getColor();
            textColor.w = opacity;
            char windowName[50];
                sprintf_s(windowName, "##TOAST%d", (int)i);
            SetNextWindowBgAlpha(opacity);
                short mainMonitorId = static_cast<ImGuiViewportP*>(GetMainViewport())->PlatformMonitor;
                ImGuiPlatformIO& platformIO = GetPlatformIO();
                ImGuiPlatformMonitor& monitor = platformIO.Monitors[mainMonitorId];
                SetNextWindowPos(ImVec2(monitor.WorkPos.x + monitor.WorkSize.x - 20.f, monitor.WorkPos.y + monitor.WorkSize.y - 20.f - height), ImGuiCond_Always, ImVec2(1.0f, 1.0f));
            if (!true && currentToast->getOnButtonPress() == nullptr)
            {
                currentToast->setWindowFlags(NOTIFY_DEFAULT_TOAST_FLAGS | ImGuiWindowFlags_NoInputs);
            }
            Begin(windowName, nullptr, currentToast->getWindowFlags());
            BringWindowToDisplayFront(GetCurrentWindow());
            {
                PushTextWrapPos(mainWindowSize.x / 3.f);
                bool wasTitleRendered = false;
                if (!(!icon || !strlen(icon)))
                {
                    TextColored(textColor, "%s", icon);
                    wasTitleRendered = true;
                }
                if (!(!title || !strlen(title)))
                {
                    if (!(!icon || !strlen(icon)))
                        SameLine();
                    Text("%s", title);
                    wasTitleRendered = true;
                } else
                if (!(!defaultTitle || !strlen(defaultTitle)))
                {
                    if (!(!icon || !strlen(icon)))
                        SameLine();
                    Text("%s", defaultTitle);
                    wasTitleRendered = true;
                }
                if (true)
                {
                    if (wasTitleRendered || !(!content || !strlen(content)))
                    {
                        SameLine();
                    }
                    float scale = 0.8f;
                    if (CalcTextSize(content).x > GetContentRegionAvail().x)
                    {
                        scale = 0.8f;
                    }
                    SetCursorPosX(GetCursorPosX() + (GetWindowSize().x - GetCursorPosX()) * scale);
                    if (Button("\xef\x80\x8d"))
                    {
                        RemoveNotification(i);
                    }
                }
                if (wasTitleRendered && !(!content || !strlen(content)))
                {
                    SetCursorPosY(GetCursorPosY() + 5.f);
                }
                if (!(!content || !strlen(content)))
                {
                    if (wasTitleRendered)
                    {
                    }
                    Text("%s", content);
                }
                if (currentToast->getOnButtonPress() != nullptr)
                {
                    if (Button(currentToast->getButtonLabel()))
                    {
                        currentToast->getOnButtonPress()();
                    }
                }
                PopTextWrapPos();
            }
            height += GetWindowHeight() + 10.f;
            End();
        }
    }
}