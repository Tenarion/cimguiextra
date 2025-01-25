#include <chrono>
#include <functional>

#include "imgui.h"
#include "imgui_internal.h"
#include "./imgui_notify.h"
#include "./IconsFontAwesome6.h"
#include "cimgui_notify.h"

ImGuiToast* ImGuiToast_Create()
{
    return new ImGuiToast(ImGuiToastType::Info, 3000);
}

ImGuiToast* ImGuiToast_CreateTypeDismissTime(ImGuiToastType& type, int dismissTime)
{
    return new ImGuiToast(type, dismissTime, "");
}

ImGuiToast* ImGuiToast_CreateTypeFormat(ImGuiToastType& type, const char* format, ...)
{
    return new ImGuiToast(type, format);
}

ImGuiToast* ImGuiToast_CreateTypeDismissTimeFormat(ImGuiToastType& type, int dismissTime, const char* format,
    ...)
{
    return new ImGuiToast(type, dismissTime, format);
}

ImGuiToast* ImGuiToast_CreateTypeDismissTimeButtonLabelOnButtonPressFormat(ImGuiToastType& type, int dismissTime,
    const char* buttonLabel, const std::function<void()>& onButtonPress, const char* format, ...)
{
    return new ImGuiToast(type, dismissTime, buttonLabel, onButtonPress, format);
}

void ImGuiToast_Destroy(ImGuiToast* self)
{
    delete self;
}

void ImGuiToast_setTitle(ImGuiToast* self, const char* format, ...)
{
    self->setTitle(format);
}

void ImGuiToast_setContent(ImGuiToast* self, const char* format, ...)
{
    self->setContent(format);
}

void ImGuiToast_setOnButtonPress(ImGuiToast* self, const std::function<void()>& onButtonPress)
{
    self->setOnButtonPress(onButtonPress);
}

void ImGuiToast_setButtonLabel(ImGuiToast* self, const char* format, ...)
{
    self->setButtonLabel(format);
}

const char* ImGuiToast_getTitle(ImGuiToast* self)
{
    return self->getTitle();
}

const char* ImGuiToast_getDefaultTitle(ImGuiToast* self)
{
    return self->getDefaultTitle();
}

ImGuiToastType ImGuiToast_getType(ImGuiToast* self)
{
    return self->getType();
}

ImVec4 ImGuiToast_getColor(ImGuiToast* self)
{
    return self->getColor();
}

const char* ImGuiToast_getIcon(ImGuiToast* self)
{
    return self->getIcon();
}

const char* ImGuiToast_getContent(ImGuiToast* self)
{
    return self->getContent();
}

std::chrono::nanoseconds ImGuiToast_getElapsedTime(ImGuiToast* self)
{
    return self->getElapsedTime();
}

ImGuiToastPhase ImGuiToast_getPhase(ImGuiToast* self)
{
    return self->getPhase();
}

float ImGuiToast_getFadePercent(ImGuiToast* self)
{
    return self->getFadePercent();
}

ImGuiWindowFlags ImGuiToast_getWindowFlags(ImGuiToast* self)
{
    return self->getWindowFlags();
}

std::function<void()> ImGuiToast_getOnButtonPress(ImGuiToast* self)
{
    return self->getOnButtonPress();
}

const char* ImGuiToast_getButtonLabel(ImGuiToast* self)
{
    return self->getButtonLabel();
}

#include "auto_funcs.cpp"
