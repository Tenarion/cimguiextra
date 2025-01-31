//This file is automatically generated by generator.lua from https://github.com/Tenarion/cimguiextra
//based on distinct headers files made for imgui
#ifndef CIMGUITHEME_INCLUDED
#define CIMGUITHEME_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS

typedef enum {
        ImGuiThemeType_ImGuiColorsClassic = 0,
        ImGuiThemeType_ImGuiColorsDark,
        ImGuiThemeType_ImGuiColorsLight,
        ImGuiThemeType_MaterialFlat,
        ImGuiThemeType_PhotoshopStyle,
        ImGuiThemeType_GrayVariations,
        ImGuiThemeType_GrayVariations_Darker,
        ImGuiThemeType_MicrosoftStyle,
        ImGuiThemeType_Cherry,
        ImGuiThemeType_Darcula,
        ImGuiThemeType_DarculaDarker,
        ImGuiThemeType_LightRounded,
        ImGuiThemeType_SoDark_AccentBlue,
        ImGuiThemeType_SoDark_AccentYellow,
        ImGuiThemeType_SoDark_AccentRed,
        ImGuiThemeType_BlackIsBlack,
        ImGuiThemeType_WhiteIsWhite,
        ImGuiThemeType_Count
    }ImGuiThemeType_;
typedef struct ImGuiThemeTweaks ImGuiThemeTweaks;
struct ImGuiThemeTweaks
{
        float Rounding;
        float RoundingScrollbarRatio;
        float AlphaMultiplier;
        float Hue;
        float SaturationMultiplier;
        float ValueMultiplierFront;
        float ValueMultiplierBg;
        float ValueMultiplierText;
        float ValueMultiplierFrameBg;
};
typedef struct ImGuiTweakedTheme ImGuiTweakedTheme;
struct ImGuiTweakedTheme
{
        ImGuiThemeType_ Theme;
        ImGuiThemeTweaks Tweaks;
};
#else
#endif // CIMGUI_DEFINE_ENUMS_AND_STRUCTS

#ifndef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
typedef ImGuiTheme::ImGuiThemeTweaks ImGuiThemeTweaks;
typedef ImGuiTheme::ImGuiTweakedTheme ImGuiTweakedTheme;
typedef ImGuiTheme::ImGuiThemeType_ ImGuiThemeType_;
#endif //CIMGUI_DEFINE_ENUMS_AND_STRUCTS
CIMGUI_API const char* ImGuiTheme_ImGuiTheme_Name(ImGuiThemeType_ theme);
CIMGUI_API ImGuiThemeType_ ImGuiTheme_ImGuiTheme_FromName(const char* themeName);
CIMGUI_API ImGuiStyle ImGuiTheme_ThemeToStyle(ImGuiThemeType_ theme);
CIMGUI_API void ImGuiTheme_ApplyTheme(ImGuiThemeType_ theme);
CIMGUI_API ImGuiThemeTweaks* ImGuiThemeTweaks_ImGuiThemeTweaks(void);
CIMGUI_API void ImGuiThemeTweaks_destroy(ImGuiThemeTweaks* self);
CIMGUI_API ImGuiTweakedTheme* ImGuiTweakedTheme_ImGuiTweakedTheme(ImGuiThemeType_ theme,const ImGuiThemeTweaks tweaks);
CIMGUI_API void ImGuiTweakedTheme_destroy(ImGuiTweakedTheme* self);
CIMGUI_API ImGuiStyle ImGuiTheme_TweakedThemeThemeToStyle(const ImGuiTweakedTheme tweaked_theme);
CIMGUI_API void ImGuiTheme_ApplyTweakedTheme(const ImGuiTweakedTheme tweaked_theme);
CIMGUI_API void ImGuiTheme_PushTweakedTheme(const ImGuiTweakedTheme tweaked_theme);
CIMGUI_API void ImGuiTheme_PopTweakedTheme(void);
CIMGUI_API bool ImGuiTheme_ShowThemeTweakGui(ImGuiTweakedTheme* tweaked_theme);
CIMGUI_API ImGuiStyle ImGuiTheme_SoDark(float hue);
CIMGUI_API ImGuiStyle ImGuiTheme_ShadesOfGray(float rounding,float value_multiplier_front,float value_multiplier_bg);
CIMGUI_API ImGuiStyle ImGuiTheme_Darcula(float rounding,float hue,float saturation_multiplier,float value_multiplier_front,float value_multiplier_bg,float alpha_bg_transparency);



#endif //CIMGUIKNOBS_INCLUDED
