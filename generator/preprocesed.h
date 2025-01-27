
namespace ImGuiTheme
{
    enum ImGuiThemeType_
    {
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
    };
    const char* ImGuiTheme_Name(ImGuiThemeType_ theme);
    ImGuiThemeType_ ImGuiTheme_FromName(const char* themeName);
    ImGuiStyle ThemeToStyle(ImGuiThemeType_ theme);
    void ApplyTheme(ImGuiThemeType_ theme);
    struct ImGuiThemeTweaks
    {
        float Rounding = -1.f;
        float RoundingScrollbarRatio = 4.f;
        float AlphaMultiplier = -1.f;
        float Hue = -1.f;
        float SaturationMultiplier = -1.f;
        float ValueMultiplierFront = -1.f;
        float ValueMultiplierBg = -1.f;
        float ValueMultiplierText = -1.f;
        float ValueMultiplierFrameBg = -1.f;
        ImGuiThemeTweaks() {}
    };
    struct ImGuiTweakedTheme
    {
        ImGuiThemeType_ Theme = ImGuiThemeType_DarculaDarker;
        ImGuiThemeTweaks Tweaks = ImGuiThemeTweaks();
        ImGuiTweakedTheme(ImGuiThemeType_ theme = ImGuiThemeType_DarculaDarker, const ImGuiThemeTweaks& tweaks = ImGuiThemeTweaks())
            : Theme(theme), Tweaks(tweaks) {}
    };
    ImGuiStyle TweakedThemeThemeToStyle(const ImGuiTweakedTheme& tweaked_theme);
    void ApplyTweakedTheme(const ImGuiTweakedTheme& tweaked_theme);
    void PushTweakedTheme(const ImGuiTweakedTheme& tweaked_theme);
    void PopTweakedTheme();
    bool ShowThemeTweakGui(ImGuiTweakedTheme *tweaked_theme);
    ImGuiStyle SoDark(float hue);
    ImGuiStyle ShadesOfGray(float rounding=0.f, float value_multiplier_front=1.f, float value_multiplier_bg=1.f);
    ImGuiStyle Darcula(
        float rounding=1.f,
        float hue=-1.f,
        float saturation_multiplier=1.f,
        float value_multiplier_front=1.f,
        float value_multiplier_bg=1.f,
        float alpha_bg_transparency=1.f
    );
}