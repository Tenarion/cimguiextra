// [src] https://github.com/ocornut/imgui/issues/123
// [src] https://github.com/ocornut/imgui/issues/55

// v1.23 - selection index track, value range, context menu, improve manipulation controls (D.Click to add/delete, drag to add)
// v1.22 - flip button; cosmetic fixes
// v1.21 - oops :)
// v1.20 - add iq's interpolation code
// v1.10 - easing and colors
// v1.00 - jari komppa's original

#pragma once
#ifdef USE_IMGUI_API
#include "imconfig.h"
#endif
#ifndef IMGUI_API
#define IMGUI_API
#endif

#ifndef IMGUIEXTRA_NAMESPACE
#define IMGUIEXTRA_NAMESPACE ImGuiExtra
#endif

namespace IMGUIEXTRA_NAMESPACE
{
    static const float CurveTerminator = -10000;

    enum TYPE
    {
        LINEAR,

        QUADIN, // t^2
        QUADOUT,
        QUADINOUT,
        CUBICIN, // t^3
        CUBICOUT,
        CUBICINOUT,
        QUARTIN, // t^4
        QUARTOUT,
        QUARTINOUT,
        QUINTIN, // t^5
        QUINTOUT,
        QUINTINOUT,
        SINEIN, // sin(t)
        SINEOUT,
        SINEINOUT,
        EXPOIN, // 2^t
        EXPOOUT,
        EXPOINOUT,
        CIRCIN, // sqrt(1-t^2)
        CIRCOUT,
        CIRCINOUT,
        ELASTICIN, // exponentially decaying sine wave
        ELASTICOUT,
        ELASTICINOUT,
        BACKIN, // overshooting cubic easing: (s+1)*t^3 - s*t^2
        BACKOUT,
        BACKINOUT,
        BOUNCEIN, // exponentially decaying parabolic bounce
        BOUNCEOUT,
        BOUNCEINOUT,

        SINESQUARE, // gapjumper's
        EXPONENTIAL, // gapjumper's
        SCHUBRING1, // terry schubring's formula 1
        SCHUBRING2, // terry schubring's formula 2
        SCHUBRING3, // terry schubring's formula 3

        SINPI2, // tomas cepeda's
        SWING, // tomas cepeda's & lquery's
    };

    IMGUI_API int Curve(const char* label, const ImVec2& size, const int maxpoints, ImVec2* points, int* selection = nullptr, const ImVec2& rangeMin = ImVec2(0, 0), const ImVec2& rangeMax = ImVec2(1, 1));
    IMGUI_API float CurveValue(float p, int maxpoints, const ImVec2* points);
    IMGUI_API float CurveValueSmooth(float p, int maxpoints, const ImVec2* points);
    IMGUI_API void SanityCheck(const char* text);
}; // namespace ImGuiExtra
