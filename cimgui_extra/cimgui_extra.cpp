//This file is automatically generated by generator.lua from https://github.com/Tenarion/cimguiextra
//based on distinct headers files made for imgui
#include "imgui.h"
#include "imgui_internal.h"
#include "./extra/imgui_extra.h"
#include "cimgui_extra.h"



CIMGUI_API int ImGuiExtra_Curve(const char* label,const ImVec2 size,const int maxpoints,ImVec2* points,int* selection,const ImVec2 rangeMin,const ImVec2 rangeMax)
{
    return ImGuiExtra::Curve(label,size,maxpoints,points,selection,rangeMin,rangeMax);
}
CIMGUI_API float ImGuiExtra_CurveValue(float p,int maxpoints,const ImVec2* points)
{
    return ImGuiExtra::CurveValue(p,maxpoints,points);
}
CIMGUI_API float ImGuiExtra_CurveValueSmooth(float p,int maxpoints,const ImVec2* points)
{
    return ImGuiExtra::CurveValueSmooth(p,maxpoints,points);
}
CIMGUI_API void ImGuiExtra_SanityCheck(const char* text)
{
    return ImGuiExtra::SanityCheck(text);
}
CIMGUI_API void ImGuiExtra_DrawRowsBackground(int row_count,float line_height,float x1,float x2,float y_offset,ImU32 col_even,ImU32 col_odd)
{
    return ImGuiExtra::DrawRowsBackground(row_count,line_height,x1,x2,y_offset,col_even,col_odd);
}

