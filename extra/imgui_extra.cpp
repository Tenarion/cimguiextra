﻿#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_extra.h"

#include <cmath>

namespace IMGUIEXTRA_NAMESPACE
{
    // implementation
    namespace test
    {
        static double ease(int easetype, double t)
        {
            const double d = 1.f;
            const double pi = 3.1415926535897932384626433832795;
            const double pi2 = 3.1415926535897932384626433832795 / 2;

            double p = t / d;

            switch (easetype)
            {
                // Modeled after the line y = x
            default:
            case LINEAR:
                {
                    return p;
                }

                // Modeled after the parabola y = x^2
            case QUADIN:
                {
                    return p * p;
                }

                // Modeled after the parabola y = -x^2 + 2x
            case QUADOUT:
                {
                    return -(p * (p - 2));
                }

                // Modeled after the piecewise quadratic
                // y = (1/2)((2x)^2)             ; [0, 0.5)
                // y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
            case QUADINOUT:
                {
                    if (p < 0.5)
                    {
                        return 2 * p * p;
                    }
                    else
                    {
                        return (-2 * p * p) + (4 * p) - 1;
                    }
                }

                // Modeled after the cubic y = x^3
            case CUBICIN:
                {
                    return p * p * p;
                }

                // Modeled after the cubic y = (x - 1)^3 + 1
            case CUBICOUT:
                {
                    double f = (p - 1);
                    return f * f * f + 1;
                }

                // Modeled after the piecewise cubic
                // y = (1/2)((2x)^3)       ; [0, 0.5)
                // y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
            case CUBICINOUT:
                {
                    if (p < 0.5)
                    {
                        return 4 * p * p * p;
                    }
                    else
                    {
                        double f = ((2 * p) - 2);
                        return 0.5 * f * f * f + 1;
                    }
                }

                // Modeled after the quartic x^4
            case QUARTIN:
                {
                    return p * p * p * p;
                }

                // Modeled after the quartic y = 1 - (x - 1)^4
            case QUARTOUT:
                {
                    double f = (p - 1);
                    return f * f * f * (1 - p) + 1;
                }

                // Modeled after the piecewise quartic
                // y = (1/2)((2x)^4)        ; [0, 0.5)
                // y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
            case QUARTINOUT:
                {
                    if (p < 0.5)
                    {
                        return 8 * p * p * p * p;
                    }
                    else
                    {
                        double f = (p - 1);
                        return -8 * f * f * f * f + 1;
                    }
                }

                // Modeled after the quintic y = x^5
            case QUINTIN:
                {
                    return p * p * p * p * p;
                }

                // Modeled after the quintic y = (x - 1)^5 + 1
            case QUINTOUT:
                {
                    double f = (p - 1);
                    return f * f * f * f * f + 1;
                }

                // Modeled after the piecewise quintic
                // y = (1/2)((2x)^5)       ; [0, 0.5)
                // y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
            case QUINTINOUT:
                {
                    if (p < 0.5)
                    {
                        return 16 * p * p * p * p * p;
                    }
                    else
                    {
                        double f = ((2 * p) - 2);
                        return 0.5 * f * f * f * f * f + 1;
                    }
                }

                // Modeled after quarter-cycle of sine wave
            case SINEIN:
                {
                    return sin((p - 1) * pi2) + 1;
                }

                // Modeled after quarter-cycle of sine wave (different phase)
            case SINEOUT:
                {
                    return sin(p * pi2);
                }

                // Modeled after half sine wave
            case SINEINOUT:
                {
                    return 0.5 * (1 - cos(p * pi));
                }

                // Modeled after shifted quadrant IV of unit circle
            case CIRCIN:
                {
                    return 1 - sqrt(1 - (p * p));
                }

                // Modeled after shifted quadrant II of unit circle
            case CIRCOUT:
                {
                    return sqrt((2 - p) * p);
                }

                // Modeled after the piecewise circular function
                // y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5)
                // y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1]
            case CIRCINOUT:
                {
                    if (p < 0.5)
                    {
                        return 0.5 * (1 - sqrt(1 - 4 * (p * p)));
                    }
                    else
                    {
                        return 0.5 * (sqrt(-((2 * p) - 3) * ((2 * p) - 1)) + 1);
                    }
                }

                // Modeled after the exponential function y = 2^(10(x - 1))
            case EXPOIN:
                {
                    return (p == 0.0) ? p : pow(2, 10 * (p - 1));
                }

                // Modeled after the exponential function y = -2^(-10x) + 1
            case EXPOOUT:
                {
                    return (p == 1.0) ? p : 1 - pow(2, -10 * p);
                }

                // Modeled after the piecewise exponential
                // y = (1/2)2^(10(2x - 1))         ; [0,0.5)
                // y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1]
            case EXPOINOUT:
                {
                    if (p == 0.0 || p == 1.0)
                        return p;

                    if (p < 0.5)
                    {
                        return 0.5 * pow(2, (20 * p) - 10);
                    }
                    else
                    {
                        return -0.5 * pow(2, (-20 * p) + 10) + 1;
                    }
                }

                // Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))
            case ELASTICIN:
                {
                    return sin(13 * pi2 * p) * pow(2, 10 * (p - 1));
                }

                // Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
            case ELASTICOUT:
                {
                    return sin(-13 * pi2 * (p + 1)) * pow(2, -10 * p) + 1;
                }

                // Modeled after the piecewise exponentially-damped sine wave:
                // y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5)
                // y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1]
            case ELASTICINOUT:
                {
                    if (p < 0.5)
                    {
                        return 0.5 * sin(13 * pi2 * (2 * p)) * pow(2, 10 * ((2 * p) - 1));
                    }
                    else
                    {
                        return 0.5 * (sin(-13 * pi2 * ((2 * p - 1) + 1)) * pow(2, -10 * (2 * p - 1)) + 2);
                    }
                }

                // Modeled (originally) after the overshooting cubic y = x^3-x*sin(x*pi)
            case BACKIN:
                {
                    /*
                           return p * p * p - p * sin(p * pi); */
                    double s = 1.70158f;
                    return p * p * ((s + 1) * p - s);
                }

                // Modeled (originally) after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi))
            case BACKOUT:
                {
                    /*
                           double f = (1 - p);
                           return 1 - (f * f * f - f * sin(f * pi)); */
                    double s = 1.70158f;
                    return --p, 1.f * (p * p * ((s + 1) * p + s) + 1);
                }

                // Modeled (originally) after the piecewise overshooting cubic function:
                // y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5)
                // y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1]
            case BACKINOUT:
                {
                    /*
                           if(p < 0.5) {
                               double f = 2 * p;
                               return 0.5 * (f * f * f - f * sin(f * pi));
                           }
                           else {
                               double f = (1 - (2*p - 1));
                               return 0.5 * (1 - (f * f * f - f * sin(f * pi))) + 0.5;
                           } */
                    double s = 1.70158f * 1.525f;
                    if (p < 0.5)
                    {
                        return p *= 2, 0.5 * p * p * (p * s + p - s);
                    }
                    else
                    {
                        return p = p * 2 - 2, 0.5 * (2 + p * p * (p * s + p + s));
                    }
                }

#define tween$bounceout(p)                                                                                             \
((p) < 4 / 11.0   ? (121 * (p) * (p)) / 16.0                                                                       \
: (p) < 8 / 11.0 ? (363 / 40.0 * (p) * (p)) - (99 / 10.0 * (p)) + 17 / 5.0                                        \
: (p) < 9 / 10.0 ? (4356 / 361.0 * (p) * (p)) - (35442 / 1805.0 * (p)) + 16061 / 1805.0                           \
: (54 / 5.0 * (p) * (p)) - (513 / 25.0 * (p)) + 268 / 25.0)

            case BOUNCEIN:
                {
                    return 1 - tween$bounceout(1 - p);
                }

            case BOUNCEOUT:
                {
                    return tween$bounceout(p);
                }

            case BOUNCEINOUT:
                {
                    if (p < 0.5)
                    {
                        return 0.5 * (1 - tween$bounceout(1 - p * 2));
                    }
                    else
                    {
                        return 0.5 * tween$bounceout((p * 2 - 1)) + 0.5;
                    }
                }

#undef tween$bounceout

            case SINESQUARE:
                {
                    double A = sin((p) * pi2);
                    return A * A;
                }

            case EXPONENTIAL:
                {
                    return 1 / (1 + exp(6 - 12 * (p)));
                }

            case SCHUBRING1:
                {
                    return 2 * (p + (0.5f - p) * abs(0.5f - p)) - 0.5f;
                }

            case SCHUBRING2:
                {
                    double p1pass = 2 * (p + (0.5f - p) * abs(0.5f - p)) - 0.5f;
                    double p2pass = 2 * (p1pass + (0.5f - p1pass) * abs(0.5f - p1pass)) - 0.5f;
                    double pAvg = (p1pass + p2pass) / 2;
                    return pAvg;
                }

            case SCHUBRING3:
                {
                    double p1pass = 2 * (p + (0.5f - p) * abs(0.5f - p)) - 0.5f;
                    double p2pass = 2 * (p1pass + (0.5f - p1pass) * abs(0.5f - p1pass)) - 0.5f;
                    return p2pass;
                }

            case SWING:
                {
                    return ((-cos(pi * p) * 0.5) + 0.5);
                }

            case SINPI2:
                {
                    return sin(p * pi2);
                }
            }
        }
    }

    // [src] http://iquilezles.org/www/articles/minispline/minispline.htm
    // key format (for dim == 1) is (t0,x0,t1,x1 ...)
    // key format (for dim == 2) is (t0,x0,y0,t1,x1,y1 ...)
    // key format (for dim == 3) is (t0,x0,y0,z0,t1,x1,y1,z1 ...)
    template <int DIM>
    void spline(const float* key, int num, float t, float* v)
    {
        static float coefs[16] = {
            -1.0f, 2.0f, -1.0f, 0.0f,
            3.0f, -5.0f, 0.0f, 2.0f,
            -3.0f, 4.0f, 1.0f, 0.0f,
            1.0f, -1.0f, 0.0f, 0.0f
        };

        const int size = DIM + 1;

        // find key
        int k = 0;
        while (key[k * size] < t)
            k++;

        const float key0 = key[(k - 1) * size];
        const float key1 = key[k * size];

        // interpolant
        const float h = (t - key0) / (key1 - key0);

        // init result
        for (int i = 0; i < DIM; i++)
            v[i] = 0.0f;

        // add basis functions
        for (int i = 0; i < 4; ++i)
        {
            const float* co = &coefs[4 * i];
            const float b = 0.5f * (((co[0] * h + co[1]) * h + co[2]) * h + co[3]);

            const int kn = ImClamp(k + i - 2, 0, num - 1);
            for (int j = 0; j < DIM; j++)
                v[j] += b * key[kn * size + j + 1];
        }
    }

    float CurveValueSmooth(float p, int maxpoints, const ImVec2* points)
    {
        if (maxpoints < 2 || points == 0)
            return 0;
        if (p < 0)
            return points[0].y;

        float* input = new float[maxpoints * 2];
        float output[4];

        for (int i = 0; i < maxpoints; ++i)
        {
            input[i * 2 + 0] = points[i].x;
            input[i * 2 + 1] = points[i].y;
        }

        spline<1>(input, maxpoints, p, output);

        delete[] input;
        return output[0];
    }

    void SanityCheck(const char* text)
    {
        if(ImGui::CollapsingHeader("Hey! Listen!"))
        {
            ImGui::Text("%s", text);
        }
    }

    float CurveValue(float p, int maxpoints, const ImVec2* points)
    {
        if (maxpoints < 2 || points == 0)
            return 0;
        if (p < 0)
            return points[0].y;

        int left = 0;
        while (left < maxpoints && points[left].x < p && points[left].x != -1)
            left++;
        if (left)
            left--;

        if (left == maxpoints - 1)
            return points[maxpoints - 1].y;

        float d = (p - points[left].x) / (points[left + 1].x - points[left].x);

        return points[left].y + (points[left + 1].y - points[left].y) * d;
    }

    static float ImRemap(float v, float a, float b, float c, float d)
    {
        return (c + (d - c) * (v - a) / (b - a));
    }

    static ImVec2 ImRemap(const ImVec2& v, const ImVec2& a, const ImVec2& b, const ImVec2& c, const ImVec2& d)
    {
        return ImVec2(ImRemap(v.x, a.x, b.x, c.x, d.x), ImRemap(v.y, a.y, b.y, c.y, d.y));
    }

    int Curve(const char* label, const ImVec2& size, const int maxpoints, ImVec2* points, int* selection,
              const ImVec2& rangeMin, const ImVec2& rangeMax)
    {
        int modified = 0;
        int i;
        if (maxpoints < 2 || points == nullptr)
            return 0;

        if (points[0].x <= CurveTerminator)
        {
            points[0] = rangeMin;
            points[1] = rangeMax;
            points[2].x = CurveTerminator;
        }

        ImGuiWindow* window = ImGui::GetCurrentWindow();
        ImGuiContext& g = *GImGui;

        const ImGuiID id = window->GetID(label);
        if (window->SkipItems)
            return 0;

        ImRect bb(window->DC.CursorPos, window->DC.CursorPos + size);
        ImGui::ItemSize(bb);
        if (!ImGui::ItemAdd(bb, NULL))
            return 0;

        ImGui::PushID(label);

        int currentSelection = selection ? *selection : -1;

        const bool hovered = ImGui::ItemHoverable(bb, id, ImGuiItemFlags_None);

        int pointCount = 0;
        while (pointCount < maxpoints && points[pointCount].x >= rangeMin.x)
            pointCount++;

        const ImGuiStyle& style = g.Style;
        ImGui::RenderFrame(bb.Min, bb.Max, ImGui::GetColorU32(ImGuiCol_FrameBg, 1), true, style.FrameRounding);

        const float ht = bb.Max.y - bb.Min.y;
        const float wd = bb.Max.x - bb.Min.x;

        int hoveredPoint = -1;

        const float pointRadiusInPixels = 5.0f;

        // Handle point selection
        if (hovered)
        {
            ImVec2 hoverPos = (g.IO.MousePos - bb.Min) / (bb.Max - bb.Min);
            hoverPos.y = 1.0f - hoverPos.y;

            ImVec2 pos = ImRemap(hoverPos, ImVec2(0, 0), ImVec2(1, 1), rangeMin, rangeMax);

            int left = 0;
            while (left < pointCount && points[left].x < pos.x)
                left++;
            if (left)
                left--;

            const ImVec2 hoverPosScreen = ImRemap(hoverPos, ImVec2(0, 0), ImVec2(1, 1), bb.Min, bb.Max);
            const ImVec2 p1s = ImRemap(points[left], rangeMin, rangeMax, bb.Min, bb.Max);
            const ImVec2 p2s = ImRemap(points[left + 1], rangeMin, rangeMax, bb.Min, bb.Max);

            const float p1d = ImSqrt(ImLengthSqr(p1s - hoverPosScreen));
            const float p2d = ImSqrt(ImLengthSqr(p2s - hoverPosScreen));

            if (p1d < pointRadiusInPixels)
                hoveredPoint = left;

            if (p2d < pointRadiusInPixels)
                hoveredPoint = left + 1;

            if (g.IO.MouseDown[0])
            {
                if (currentSelection == -1)
                    currentSelection = hoveredPoint;
            }
            else
                currentSelection = -1;

            enum
            {
                action_none,
                action_add_point,
                action_delete_point
            };

            int action = action_none;

            if (currentSelection == -1)
            {
                if (g.IO.MouseDoubleClicked[0] || ImGui::IsMouseDragging(0))
                    action = action_add_point;
            }
            else if (g.IO.MouseDoubleClicked[0])
                action = action_delete_point;

            if (action == action_add_point)
            {
                if (pointCount < maxpoints)
                {
                    // select
                    currentSelection = left + 1;

                    ++pointCount;
                    for (i = pointCount; i > left; --i)
                        points[i] = points[i - 1];

                    points[left + 1] = pos;

                    if (pointCount < maxpoints)
                        points[pointCount].x = CurveTerminator;
                }
            }
            else if (action == action_delete_point)
            {
                // delete point
                if (currentSelection > 0 && currentSelection < maxpoints - 1)
                {
                    for (i = currentSelection; i < maxpoints - 1; ++i)
                        points[i] = points[i + 1];

                    --pointCount;
                    points[pointCount].x = CurveTerminator;
                    currentSelection = -1;
                }
            }
        }

        // handle point dragging
        const bool draggingPoint = ImGui::IsMouseDragging(0) && currentSelection != -1;

        if (draggingPoint)
        {
            if (selection)
                ImGui::SetActiveID(id, window);

            ImGui::SetFocusID(id, window);
            ImGui::FocusWindow(window);

            modified = 1;

            ImVec2 pos = (g.IO.MousePos - bb.Min) / (bb.Max - bb.Min);

            // constrain Y to min/max
            pos.y = 1.0f - pos.y;
            pos = ImRemap(pos, ImVec2(0, 0), ImVec2(1, 1), rangeMin, rangeMax);

            // constrain X to the min left/ max right
            const float pointXRangeMin = (currentSelection > 0) ? points[currentSelection - 1].x : rangeMin.x;
            const float pointXRangeMax = (currentSelection + 1 < pointCount)
                                             ? points[currentSelection + 1].x
                                             : rangeMax.x;

            pos = ImClamp(pos, ImVec2(pointXRangeMin, rangeMin.y), ImVec2(pointXRangeMax, rangeMax.y));

            points[currentSelection] = pos;

            // snap X first/last to min/max
            if (points[0].x < points[pointCount - 1].x)
            {
                points[0].x = rangeMin.y;
                points[pointCount - 1].x = rangeMax.x;
            }
            else
            {
                points[0].x = rangeMax.x;
                points[pointCount - 1].x = rangeMin.y;
            }
        }

        if (!ImGui::IsMouseDragging(0) && ImGui::GetActiveID() == id && selection && *selection != -1 &&
            currentSelection == -1)
        {
            ImGui::ClearActiveID();
        }

        const ImU32 gridColor1 = ImGui::GetColorU32(ImGuiCol_TextDisabled, 0.5f);
        const ImU32 gridColor2 = ImGui::GetColorU32(ImGuiCol_TextDisabled, 0.25f);

        ImDrawList* drawList = window->DrawList;

        // bg grid
        drawList->AddLine(ImVec2(bb.Min.x, bb.Min.y + ht / 2), ImVec2(bb.Max.x, bb.Min.y + ht / 2), gridColor1, 3);

        drawList->AddLine(ImVec2(bb.Min.x, bb.Min.y + ht / 4), ImVec2(bb.Max.x, bb.Min.y + ht / 4), gridColor1);

        drawList->AddLine(ImVec2(bb.Min.x, bb.Min.y + ht / 4 * 3), ImVec2(bb.Max.x, bb.Min.y + ht / 4 * 3), gridColor1);

        for (i = 0; i < 9; i++)
        {
            drawList->AddLine(ImVec2(bb.Min.x + (wd / 10) * (i + 1), bb.Min.y),
                              ImVec2(bb.Min.x + (wd / 10) * (i + 1), bb.Max.y), gridColor2);
        }

        drawList->PushClipRect(bb.Min, bb.Max);

        // smooth curve
        enum
        {
            smoothness = 256
        }; // the higher the smoother
        for (i = 0; i <= (smoothness - 1); ++i)
        {
            float px = (i + 0) / float(smoothness);
            float qx = (i + 1) / float(smoothness);

            px = ImRemap(px, 0, 1, rangeMin.x, rangeMax.x);
            qx = ImRemap(qx, 0, 1, rangeMin.x, rangeMax.x);

            const float py = CurveValueSmooth(px, maxpoints, points);
            const float qy = CurveValueSmooth(qx, maxpoints, points);

            ImVec2 p = ImRemap(ImVec2(px, py), rangeMin, rangeMax, ImVec2(0, 0), ImVec2(1, 1));
            ImVec2 q = ImRemap(ImVec2(qx, qy), rangeMin, rangeMax, ImVec2(0, 0), ImVec2(1, 1));
            p.y = 1.0f - p.y;
            q.y = 1.0f - q.y;

            p = ImRemap(p, ImVec2(0, 0), ImVec2(1, 1), bb.Min, bb.Max);
            q = ImRemap(q, ImVec2(0, 0), ImVec2(1, 1), bb.Min, bb.Max);

            drawList->AddLine(p, q, ImGui::GetColorU32(ImGuiCol_PlotHistogram));
        }

        // lines
        for (i = 1; i < pointCount; i++)
        {
            ImVec2 a = ImRemap(points[i - 1], rangeMin, rangeMax, ImVec2(0, 0), ImVec2(1, 1));
            ImVec2 b = ImRemap(points[i], rangeMin, rangeMax, ImVec2(0, 0), ImVec2(1, 1));

            a.y = 1.0f - a.y;
            b.y = 1.0f - b.y;

            a = ImRemap(a, ImVec2(0, 0), ImVec2(1, 1), bb.Min, bb.Max);
            b = ImRemap(b, ImVec2(0, 0), ImVec2(1, 1), bb.Min, bb.Max);

            drawList->AddLine(a, b, ImGui::GetColorU32(ImGuiCol_PlotLines, 0.5f));
        }

        if (hovered || draggingPoint)
        {
            // control points
            for (i = 0; i < pointCount; i++)
            {
                ImVec2 p = ImRemap(points[i], rangeMin, rangeMax, ImVec2(0, 0), ImVec2(1, 1));
                p.y = 1.0f - p.y;
                p = ImRemap(p, ImVec2(0, 0), ImVec2(1, 1), bb.Min, bb.Max);

                ImVec2 a = p - ImVec2(4, 4);
                ImVec2 b = p + ImVec2(4, 4);
                if (hoveredPoint == i)
                    drawList->AddRect(a, b, ImGui::GetColorU32(ImGuiCol_PlotLinesHovered));
                else
                    drawList->AddCircle(p, pointRadiusInPixels, ImGui::GetColorU32(ImGuiCol_PlotLinesHovered));
            }
        }

        drawList->PopClipRect();

        // draw the text at mouse position
        char buf[128];
        const char* str = label;

        if (hovered || draggingPoint)
        {
            ImVec2 pos = (g.IO.MousePos - bb.Min) / (bb.Max - bb.Min);
            pos.y = 1.0f - pos.y;

            pos = ImLerp(rangeMin, rangeMax, pos);

            snprintf(buf, sizeof(buf), "%s (%.2f,%.2f)", label, pos.x, pos.y);
            str = buf;
        }

        ImGui::RenderTextClipped(ImVec2(bb.Min.x, bb.Min.y + style.FramePadding.y), bb.Max, str, NULL, NULL,
                                 ImVec2(0.5f, 0.5f));

        // curve selector
        static const char* items[] = {
            "Custom",

            "Linear", "Quad in", "Quad out", "Quad in  out", "Cubic in", "Cubic out",
            "Cubic in  out", "Quart in", "Quart out", "Quart in  out", "Quint in", "Quint out",
            "Quint in  out", "Sine in", "Sine out", "Sine in  out", "Expo in", "Expo out",
            "Expo in  out", "Circ in", "Circ out", "Circ in  out", "Elastic in", "Elastic out",
            "Elastic in  out", "Back in", "Back out", "Back in  out", "Bounce in", "Bounce out",
            "Bounce in out",

            "Sine square", "Exponential",

            "Schubring1", "Schubring2", "Schubring3",

            "SinPi2", "Swing"
        };

        // buttons; @todo: mirror, smooth, tessellate
        if (ImGui::BeginPopupContextItem(label))
        {
            if (ImGui::Selectable("Reset"))
            {
                points[0] = rangeMin;
                points[1] = rangeMax;
                points[2].x = CurveTerminator;
            }
            if (ImGui::Selectable("Flip"))
            {
                for (i = 0; i < pointCount; ++i)
                {
                    const float yVal = 1.0f - ImRemap(points[i].y, rangeMin.y, rangeMax.y, 0, 1);
                    points[i].y = ImRemap(yVal, 0, 1, rangeMin.y, rangeMax.y);
                }
            }
            if (ImGui::Selectable("Mirror"))
            {
                for (int i = 0, j = pointCount - 1; i < j; i++, j--)
                {
                    ImSwap(points[i], points[j]);
                }
                for (i = 0; i < pointCount; ++i)
                {
                    const float xVal = 1.0f - ImRemap(points[i].x, rangeMin.x, rangeMax.x, 0, 1);
                    points[i].x = ImRemap(xVal, 0, 1, rangeMin.x, rangeMax.x);
                }
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Presets"))
            {
                ImGui::PushID("curve_items");
                for (int row = 0; row < IM_ARRAYSIZE(items); ++row)
                {
                    if (ImGui::MenuItem(items[row]))
                    {
                        for (i = 0; i < maxpoints; ++i)
                        {
                            const float px = i / float(maxpoints - 1);
                            const float py = float(test::ease(row - 1, px));

                            points[i] = ImRemap(ImVec2(px, py), ImVec2(0, 0), ImVec2(1, 1), rangeMin, rangeMax);
                        }
                    }
                }
                ImGui::PopID();
                ImGui::EndMenu();
            }


            ImGui::EndPopup();
        }

        ImGui::PopID();

        if (selection)
        {
            *selection = currentSelection;
        }

        return modified;
    }

    void DrawRowsBackground(int row_count, float line_height, float x1, float x2, float y_offset, ImU32 col_even, ImU32 col_odd)
    {
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        float y0 = ImGui::GetCursorScreenPos().y + (float)(int)y_offset;

        const auto pos = ImGui::GetCursorPos();
        ImGuiListClipper clipper;
        clipper.Begin(row_count, line_height);
        while (clipper.Step())
        {
            for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; ++row_n)
            {
                ImU32 col = (row_n & 1) ? col_odd : col_even;
                if ((col & IM_COL32_A_MASK) == 0)
                    continue;
                float y1 = y0 + (line_height * static_cast<float>(row_n));
                float y2 = y1 + line_height;
                draw_list->AddRectFilled(ImVec2(x1, y1), ImVec2(x2, y2), col);
            }
        }
        ImGui::SetCursorPos(pos);
    }

}
