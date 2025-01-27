#ifndef CIMGUINOTIFY_INCLUDED
#define CIMGUINOTIFY_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "imgui_structs.h"
#else
#endif // CIMGUI_DEFINE_ENUMS_AND_STRUCTS

#include <chrono>
#include <functional>
#include "auto_funcs.h"

typedef struct ImVec4 ImVec4;

// We have to convert ImGuiToast class to something manageable by C:

CIMGUI_API ImGuiToast* ImGuiToast_Create(
    ImGuiToastType type, int dismissTime, const char* buttonLabel, const void* onButtonPress,
    const char* format, ...);
CIMGUI_API void ImGuiToast_Destroy(ImGuiToast* self);
CIMGUI_API void ImGuiToast_setTitle(ImGuiToast* self, const char* format, ...);
CIMGUI_API void ImGuiToast_setContent(ImGuiToast* self, const char* format, ...);
CIMGUI_API void ImGuiToast_setType(ImGuiToast * self, ImGuiToastType & type);
CIMGUI_API void ImGuiToast_setWindowFlags(ImGuiToast * self, ImGuiWindowFlags & flags);
CIMGUI_API void ImGuiToast_setOnButtonPress(ImGuiToast* self, const void* onButtonPress);
CIMGUI_API void ImGuiToast_setButtonLabel(ImGuiToast* self, const char* format, ...);

CIMGUI_API const char* ImGuiToast_getTitle(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getDefaultTitle(ImGuiToast * self);
CIMGUI_API ImGuiToastType ImGuiToast_getType(ImGuiToast * self);
CIMGUI_API ImVec4 ImGuiToast_getColor(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getIcon(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getContent(ImGuiToast * self);
CIMGUI_API int ImGuiToast_getElapsedTime(ImGuiToast * self);
CIMGUI_API ImGuiToastPhase ImGuiToast_getPhase(ImGuiToast * self);
CIMGUI_API float ImGuiToast_getFadePercent(ImGuiToast * self);
CIMGUI_API ImGuiWindowFlags ImGuiToast_getWindowFlags(ImGuiToast * self);
CIMGUI_API void* ImGuiToast_getOnButtonPress(ImGuiToast * self);
CIMGUI_API const char* ImGuiToast_getButtonLabel(ImGuiToast * self);

#endif //CIMGUIKNOBS_INCLUDED
