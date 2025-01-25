#ifndef CIMGUIKNOBS_INCLUDED
#define CIMGUIKNOBS_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "imgui_structs.h"
#else
#endif // CIMGUI_DEFINE_ENUMS_AND_STRUCTS

#include <chrono>
#include <functional>
#include "auto_funcs.h"

// We have to convert ImGuiToast class to something manageable by C:

CIMGUI_API ImGuiToast* ImGuiToast_Create();
CIMGUI_API ImGuiToast* ImGuiToast_CreateType(ImGuiToastType& type);
CIMGUI_API ImGuiToast* ImGuiToast_CreateTypeDismissTime(ImGuiToastType& type, int dismissTime);
CIMGUI_API ImGuiToast* ImGuiToast_CreateTypeFormat(ImGuiToastType& type, const char* format, ...);
CIMGUI_API ImGuiToast* ImGuiToast_CreateTypeDismissTimeFormat(ImGuiToastType& type, int dismissTime, const char* format, ...);
CIMGUI_API ImGuiToast* ImGuiToast_CreateTypeDismissTimeButtonLabelOnButtonPressFormat(
    ImGuiToastType& type, int dismissTime, const char* buttonLabel, const std::function<void()>& onButtonPress,
    const char* format, ...);
CIMGUI_API void ImGuiToast_Destroy(ImGuiToast* self);
CIMGUI_API void ImGuiToast_setTitle(ImGuiToast* self, const char* format, ...);
CIMGUI_API void ImGuiToast_setContent(ImGuiToast* self, const char* format, ...);
CIMGUI_API void ImGuiToast_setType(ImGuiToast * self, ImGuiToastType & type);
CIMGUI_API void ImGuiToast_setWindowFlags(ImGuiToast * self, ImGuiWindowFlags & flags);
CIMGUI_API void ImGuiToast_setOnButtonPress(ImGuiToast* self, const std::function<void()>& onButtonPress);
CIMGUI_API void ImGuiToast_setButtonLabel(ImGuiToast* self, const char* format, ...);

CIMGUI_API const char* ImGuiToast_getTitle(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getDefaultTitle(ImGuiToast * self);
CIMGUI_API ImGuiToastType ImGuiToast_getType(ImGuiToast * self);
CIMGUI_API ImVec4 ImGuiToast_getColor(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getIcon(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getContent(ImGuiToast * self);
CIMGUI_API std::chrono::nanoseconds ImGuiToast_getElapsedTime(ImGuiToast * self);
CIMGUI_API ImGuiToastPhase ImGuiToast_getPhase(ImGuiToast * self);
CIMGUI_API float ImGuiToast_getFadePercent(ImGuiToast * self);
CIMGUI_API ImGuiWindowFlags ImGuiToast_getWindowFlags(ImGuiToast * self);
CIMGUI_API std::function<void()> ImGuiToast_getOnButtonPress(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getButtonLabel(ImGuiToast * self);

#endif //CIMGUIKNOBS_INCLUDED
