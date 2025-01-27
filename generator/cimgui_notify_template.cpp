#include <chrono>
#include <functional>

#include "imgui.h"
#include "imgui_internal.h"
#include "./imgui_notify/imgui_notify.h"
#include "cimgui_notify.h"
#include <cassert>
#include <cstdarg>


ImGuiToast* ImGuiToast_Create(ImGuiToastType type, int dismissTime,
                              const char* buttonLabel,
                              const void* onButtonPress,
                              const char* format, ...)
{
    return new ImGuiToast(type, dismissTime, buttonLabel, reinterpret_cast<std::function<void()>&>(onButtonPress), format);
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

void ImGuiToast_setOnButtonPress(ImGuiToast* self, const void* onButtonPress)
{
    self->setOnButtonPress(reinterpret_cast<std::function<void()>&>(onButtonPress));
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

int ImGuiToast_getElapsedTime(ImGuiToast* self)
{
    return self->getElapsedTime().count();
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

void* ImGuiToast_getOnButtonPress(ImGuiToast* self)
{
    auto fun = self->getOnButtonPress();
    return fun.target<void(*)>();
}

const char* ImGuiToast_getButtonLabel(ImGuiToast* self)
{
    return self->getButtonLabel();
}

#include "auto_funcs.cpp"
