local t={
  ImGuiThemeTweaks_ImGuiThemeTweaks={
    [1]={
      args="()",
      argsT={},
      argsoriginal="()",
      call_args="()",
      cimguiname="ImGuiThemeTweaks_ImGuiThemeTweaks",
      constructor=true,
      defaults={},
      funcname="ImGuiThemeTweaks",
      location="imgui_theme:66",
      ov_cimguiname="ImGuiThemeTweaks_ImGuiThemeTweaks",
      signature="()",
      stname="ImGuiThemeTweaks"},
    ["()"]=nil},
  ImGuiThemeTweaks_destroy={
    [1]={
      args="(ImGuiThemeTweaks* self)",
      argsT={
        [1]={
          name="self",
          type="ImGuiThemeTweaks*"}},
      call_args="(self)",
      cimguiname="ImGuiThemeTweaks_destroy",
      defaults={},
      destructor=true,
      location="imgui_theme:66",
      ov_cimguiname="ImGuiThemeTweaks_destroy",
      ret="void",
      signature="(ImGuiThemeTweaks*)",
      stname="ImGuiThemeTweaks"},
    ["(ImGuiThemeTweaks*)"]=nil},
  ImGuiTheme_ApplyTheme={
    [1]={
      args="(ImGuiThemeType_ theme)",
      argsT={
        [1]={
          name="theme",
          type="ImGuiThemeType_"}},
      argsoriginal="(ImGuiThemeType_ theme)",
      call_args="(theme)",
      cimguiname="ImGuiTheme_ApplyTheme",
      defaults={},
      funcname="ApplyTheme",
      location="imgui_theme:37",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ApplyTheme",
      ret="void",
      signature="(ImGuiThemeType_)",
      stname=""},
    ["(ImGuiThemeType_)"]=nil},
  ImGuiTheme_ApplyTweakedTheme={
    [1]={
      args="(const ImGuiTweakedTheme tweaked_theme)",
      argsT={
        [1]={
          name="tweaked_theme",
          type="const ImGuiTweakedTheme"}},
      argsoriginal="(const ImGuiTweakedTheme& tweaked_theme)",
      call_args="(tweaked_theme)",
      cimguiname="ImGuiTheme_ApplyTweakedTheme",
      defaults={},
      funcname="ApplyTweakedTheme",
      location="imgui_theme:79",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ApplyTweakedTheme",
      ret="void",
      signature="(const ImGuiTweakedTheme)",
      stname=""},
    ["(const ImGuiTweakedTheme)"]=nil},
  ImGuiTheme_Darcula={
    [1]={
      args="(float rounding,float hue,float saturation_multiplier,float value_multiplier_front,float value_multiplier_bg,float alpha_bg_transparency)",
      argsT={
        [1]={
          name="rounding",
          type="float"},
        [2]={
          name="hue",
          type="float"},
        [3]={
          name="saturation_multiplier",
          type="float"},
        [4]={
          name="value_multiplier_front",
          type="float"},
        [5]={
          name="value_multiplier_bg",
          type="float"},
        [6]={
          name="alpha_bg_transparency",
          type="float"}},
      argsoriginal="(float rounding=1.f,float hue=-1.f,float saturation_multiplier=1.f,float value_multiplier_front=1.f,float value_multiplier_bg=1.f,float alpha_bg_transparency=1.f)",
      call_args="(rounding,hue,saturation_multiplier,value_multiplier_front,value_multiplier_bg,alpha_bg_transparency)",
      cimguiname="ImGuiTheme_Darcula",
      defaults={
        alpha_bg_transparency="1.f",
        hue="-1.f",
        rounding="1.f",
        saturation_multiplier="1.f",
        value_multiplier_bg="1.f",
        value_multiplier_front="1.f"},
      funcname="Darcula",
      location="imgui_theme:107",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_Darcula",
      ret="ImGuiStyle",
      signature="(float,float,float,float,float,float)",
      stname=""},
    ["(float,float,float,float,float,float)"]=nil},
  ImGuiTheme_ImGuiTheme_FromName={
    [1]={
      args="(const char* themeName)",
      argsT={
        [1]={
          name="themeName",
          type="const char*"}},
      argsoriginal="(const char* themeName)",
      call_args="(themeName)",
      cimguiname="ImGuiTheme_ImGuiTheme_FromName",
      defaults={},
      funcname="ImGuiTheme_FromName",
      location="imgui_theme:35",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ImGuiTheme_FromName",
      ret="ImGuiThemeType_",
      signature="(const char*)",
      stname=""},
    ["(const char*)"]=nil},
  ImGuiTheme_ImGuiTheme_Name={
    [1]={
      args="(ImGuiThemeType_ theme)",
      argsT={
        [1]={
          name="theme",
          type="ImGuiThemeType_"}},
      argsoriginal="(ImGuiThemeType_ theme)",
      call_args="(theme)",
      cimguiname="ImGuiTheme_ImGuiTheme_Name",
      defaults={},
      funcname="ImGuiTheme_Name",
      location="imgui_theme:34",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ImGuiTheme_Name",
      ret="const char*",
      signature="(ImGuiThemeType_)",
      stname=""},
    ["(ImGuiThemeType_)"]=nil},
  ImGuiTheme_PopTweakedTheme={
    [1]={
      args="()",
      argsT={},
      argsoriginal="()",
      call_args="()",
      cimguiname="ImGuiTheme_PopTweakedTheme",
      defaults={},
      funcname="PopTweakedTheme",
      location="imgui_theme:99",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_PopTweakedTheme",
      ret="void",
      signature="()",
      stname=""},
    ["()"]=nil},
  ImGuiTheme_PushTweakedTheme={
    [1]={
      args="(const ImGuiTweakedTheme tweaked_theme)",
      argsT={
        [1]={
          name="tweaked_theme",
          type="const ImGuiTweakedTheme"}},
      argsoriginal="(const ImGuiTweakedTheme& tweaked_theme)",
      call_args="(tweaked_theme)",
      cimguiname="ImGuiTheme_PushTweakedTheme",
      defaults={},
      funcname="PushTweakedTheme",
      location="imgui_theme:98",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_PushTweakedTheme",
      ret="void",
      signature="(const ImGuiTweakedTheme)",
      stname=""},
    ["(const ImGuiTweakedTheme)"]=nil},
  ImGuiTheme_ShadesOfGray={
    [1]={
      args="(float rounding,float value_multiplier_front,float value_multiplier_bg)",
      argsT={
        [1]={
          name="rounding",
          type="float"},
        [2]={
          name="value_multiplier_front",
          type="float"},
        [3]={
          name="value_multiplier_bg",
          type="float"}},
      argsoriginal="(float rounding=0.f,float value_multiplier_front=1.f,float value_multiplier_bg=1.f)",
      call_args="(rounding,value_multiplier_front,value_multiplier_bg)",
      cimguiname="ImGuiTheme_ShadesOfGray",
      defaults={
        rounding="0.f",
        value_multiplier_bg="1.f",
        value_multiplier_front="1.f"},
      funcname="ShadesOfGray",
      location="imgui_theme:106",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ShadesOfGray",
      ret="ImGuiStyle",
      signature="(float,float,float)",
      stname=""},
    ["(float,float,float)"]=nil},
  ImGuiTheme_ShowThemeTweakGui={
    [1]={
      args="(ImGuiTweakedTheme* tweaked_theme)",
      argsT={
        [1]={
          name="tweaked_theme",
          type="ImGuiTweakedTheme*"}},
      argsoriginal="(ImGuiTweakedTheme* tweaked_theme)",
      call_args="(tweaked_theme)",
      cimguiname="ImGuiTheme_ShowThemeTweakGui",
      defaults={},
      funcname="ShowThemeTweakGui",
      location="imgui_theme:102",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ShowThemeTweakGui",
      ret="bool",
      signature="(ImGuiTweakedTheme*)",
      stname=""},
    ["(ImGuiTweakedTheme*)"]=nil},
  ImGuiTheme_SoDark={
    [1]={
      args="(float hue)",
      argsT={
        [1]={
          name="hue",
          type="float"}},
      argsoriginal="(float hue)",
      call_args="(hue)",
      cimguiname="ImGuiTheme_SoDark",
      defaults={},
      funcname="SoDark",
      location="imgui_theme:105",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_SoDark",
      ret="ImGuiStyle",
      signature="(float)",
      stname=""},
    ["(float)"]=nil},
  ImGuiTheme_ThemeToStyle={
    [1]={
      args="(ImGuiThemeType_ theme)",
      argsT={
        [1]={
          name="theme",
          type="ImGuiThemeType_"}},
      argsoriginal="(ImGuiThemeType_ theme)",
      call_args="(theme)",
      cimguiname="ImGuiTheme_ThemeToStyle",
      defaults={},
      funcname="ThemeToStyle",
      location="imgui_theme:36",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_ThemeToStyle",
      ret="ImGuiStyle",
      signature="(ImGuiThemeType_)",
      stname=""},
    ["(ImGuiThemeType_)"]=nil},
  ImGuiTheme_TweakedThemeThemeToStyle={
    [1]={
      args="(const ImGuiTweakedTheme tweaked_theme)",
      argsT={
        [1]={
          name="tweaked_theme",
          type="const ImGuiTweakedTheme"}},
      argsoriginal="(const ImGuiTweakedTheme& tweaked_theme)",
      call_args="(tweaked_theme)",
      cimguiname="ImGuiTheme_TweakedThemeThemeToStyle",
      defaults={},
      funcname="TweakedThemeThemeToStyle",
      location="imgui_theme:78",
      namespace="ImGuiTheme",
      ov_cimguiname="ImGuiTheme_TweakedThemeThemeToStyle",
      ret="ImGuiStyle",
      signature="(const ImGuiTweakedTheme)",
      stname=""},
    ["(const ImGuiTweakedTheme)"]=nil},
  ImGuiTweakedTheme_ImGuiTweakedTheme={
    [1]={
      args="(ImGuiThemeType_ theme,const ImGuiThemeTweaks tweaks)",
      argsT={
        [1]={
          name="theme",
          type="ImGuiThemeType_"},
        [2]={
          name="tweaks",
          type="const ImGuiThemeTweaks"}},
      argsoriginal="(ImGuiThemeType_ theme=ImGuiThemeType_DarculaDarker,const ImGuiThemeTweaks& tweaks=ImGuiThemeTweaks())",
      call_args="(theme,tweaks)",
      cimguiname="ImGuiTweakedTheme_ImGuiTweakedTheme",
      constructor=true,
      defaults={
        theme="ImGuiThemeType_DarculaDarker",
        tweaks="ImGuiThemeTweaks()"},
      funcname="ImGuiTweakedTheme",
      location="imgui_theme:74",
      ov_cimguiname="ImGuiTweakedTheme_ImGuiTweakedTheme",
      signature="(ImGuiThemeType_,const ImGuiThemeTweaks)",
      stname="ImGuiTweakedTheme"},
    ["(ImGuiThemeType_,const ImGuiThemeTweaks)"]=nil},
  ImGuiTweakedTheme_destroy={
    [1]={
      args="(ImGuiTweakedTheme* self)",
      argsT={
        [1]={
          name="self",
          type="ImGuiTweakedTheme*"}},
      call_args="(self)",
      cimguiname="ImGuiTweakedTheme_destroy",
      defaults={},
      destructor=true,
      location="imgui_theme:74",
      ov_cimguiname="ImGuiTweakedTheme_destroy",
      ret="void",
      signature="(ImGuiTweakedTheme*)",
      stname="ImGuiTweakedTheme"},
    ["(ImGuiTweakedTheme*)"]=nil}}
t.ImGuiThemeTweaks_ImGuiThemeTweaks["()"]=t.ImGuiThemeTweaks_ImGuiThemeTweaks[1]
t.ImGuiThemeTweaks_destroy["(ImGuiThemeTweaks*)"]=t.ImGuiThemeTweaks_destroy[1]
t.ImGuiTheme_ApplyTheme["(ImGuiThemeType_)"]=t.ImGuiTheme_ApplyTheme[1]
t.ImGuiTheme_ApplyTweakedTheme["(const ImGuiTweakedTheme)"]=t.ImGuiTheme_ApplyTweakedTheme[1]
t.ImGuiTheme_Darcula["(float,float,float,float,float,float)"]=t.ImGuiTheme_Darcula[1]
t.ImGuiTheme_ImGuiTheme_FromName["(const char*)"]=t.ImGuiTheme_ImGuiTheme_FromName[1]
t.ImGuiTheme_ImGuiTheme_Name["(ImGuiThemeType_)"]=t.ImGuiTheme_ImGuiTheme_Name[1]
t.ImGuiTheme_PopTweakedTheme["()"]=t.ImGuiTheme_PopTweakedTheme[1]
t.ImGuiTheme_PushTweakedTheme["(const ImGuiTweakedTheme)"]=t.ImGuiTheme_PushTweakedTheme[1]
t.ImGuiTheme_ShadesOfGray["(float,float,float)"]=t.ImGuiTheme_ShadesOfGray[1]
t.ImGuiTheme_ShowThemeTweakGui["(ImGuiTweakedTheme*)"]=t.ImGuiTheme_ShowThemeTweakGui[1]
t.ImGuiTheme_SoDark["(float)"]=t.ImGuiTheme_SoDark[1]
t.ImGuiTheme_ThemeToStyle["(ImGuiThemeType_)"]=t.ImGuiTheme_ThemeToStyle[1]
t.ImGuiTheme_TweakedThemeThemeToStyle["(const ImGuiTweakedTheme)"]=t.ImGuiTheme_TweakedThemeThemeToStyle[1]
t.ImGuiTweakedTheme_ImGuiTweakedTheme["(ImGuiThemeType_,const ImGuiThemeTweaks)"]=t.ImGuiTweakedTheme_ImGuiTweakedTheme[1]
t.ImGuiTweakedTheme_destroy["(ImGuiTweakedTheme*)"]=t.ImGuiTweakedTheme_destroy[1]
 return t