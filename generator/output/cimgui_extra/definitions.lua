local t={
  ImGuiExtra_Curve={
    [1]={
      args="(const char* label,const ImVec2 size,const int maxpoints,ImVec2* points,int* selection,const ImVec2 rangeMin,const ImVec2 rangeMax)",
      argsT={
        [1]={
          name="label",
          type="const char*"},
        [2]={
          name="size",
          type="const ImVec2"},
        [3]={
          name="maxpoints",
          type="const int"},
        [4]={
          name="points",
          type="ImVec2*"},
        [5]={
          name="selection",
          type="int*"},
        [6]={
          name="rangeMin",
          type="const ImVec2"},
        [7]={
          name="rangeMax",
          type="const ImVec2"}},
      argsoriginal="(const char* label,const ImVec2& size,const int maxpoints,ImVec2* points,int* selection=nullptr,const ImVec2& rangeMin=ImVec2(0,0),const ImVec2& rangeMax=ImVec2(1,1))",
      call_args="(label,size,maxpoints,points,selection,rangeMin,rangeMax)",
      cimguiname="ImGuiExtra_Curve",
      defaults={
        rangeMax="ImVec2(1,1)",
        rangeMin="ImVec2(0,0)",
        selection="nullptr"},
      funcname="Curve",
      location="imgui_extra:72",
      namespace="ImGuiExtra",
      ov_cimguiname="ImGuiExtra_Curve",
      ret="int",
      signature="(const char*,const ImVec2,const int,ImVec2*,int*,const ImVec2,const ImVec2)",
      stname=""},
    ["(const char*,const ImVec2,const int,ImVec2*,int*,const ImVec2,const ImVec2)"]=nil},
  ImGuiExtra_CurveValue={
    [1]={
      args="(float p,int maxpoints,const ImVec2* points)",
      argsT={
        [1]={
          name="p",
          type="float"},
        [2]={
          name="maxpoints",
          type="int"},
        [3]={
          name="points",
          type="const ImVec2*"}},
      argsoriginal="(float p,int maxpoints,const ImVec2* points)",
      call_args="(p,maxpoints,points)",
      cimguiname="ImGuiExtra_CurveValue",
      defaults={},
      funcname="CurveValue",
      location="imgui_extra:73",
      namespace="ImGuiExtra",
      ov_cimguiname="ImGuiExtra_CurveValue",
      ret="float",
      signature="(float,int,const ImVec2*)",
      stname=""},
    ["(float,int,const ImVec2*)"]=nil},
  ImGuiExtra_CurveValueSmooth={
    [1]={
      args="(float p,int maxpoints,const ImVec2* points)",
      argsT={
        [1]={
          name="p",
          type="float"},
        [2]={
          name="maxpoints",
          type="int"},
        [3]={
          name="points",
          type="const ImVec2*"}},
      argsoriginal="(float p,int maxpoints,const ImVec2* points)",
      call_args="(p,maxpoints,points)",
      cimguiname="ImGuiExtra_CurveValueSmooth",
      defaults={},
      funcname="CurveValueSmooth",
      location="imgui_extra:74",
      namespace="ImGuiExtra",
      ov_cimguiname="ImGuiExtra_CurveValueSmooth",
      ret="float",
      signature="(float,int,const ImVec2*)",
      stname=""},
    ["(float,int,const ImVec2*)"]=nil},
  ImGuiExtra_DrawRowsBackground={
    [1]={
      args="(int row_count,float line_height,float x1,float x2,float y_offset,ImU32 col_even,ImU32 col_odd)",
      argsT={
        [1]={
          name="row_count",
          type="int"},
        [2]={
          name="line_height",
          type="float"},
        [3]={
          name="x1",
          type="float"},
        [4]={
          name="x2",
          type="float"},
        [5]={
          name="y_offset",
          type="float"},
        [6]={
          name="col_even",
          type="ImU32"},
        [7]={
          name="col_odd",
          type="ImU32"}},
      argsoriginal="(int row_count,float line_height,float x1,float x2,float y_offset,ImU32 col_even,ImU32 col_odd)",
      call_args="(row_count,line_height,x1,x2,y_offset,col_even,col_odd)",
      cimguiname="ImGuiExtra_DrawRowsBackground",
      defaults={},
      funcname="DrawRowsBackground",
      location="imgui_extra:76",
      namespace="ImGuiExtra",
      ov_cimguiname="ImGuiExtra_DrawRowsBackground",
      ret="void",
      signature="(int,float,float,float,float,ImU32,ImU32)",
      stname=""},
    ["(int,float,float,float,float,ImU32,ImU32)"]=nil},
  ImGuiExtra_SanityCheck={
    [1]={
      args="(const char* text)",
      argsT={
        [1]={
          name="text",
          type="const char*"}},
      argsoriginal="(const char* text)",
      call_args="(text)",
      cimguiname="ImGuiExtra_SanityCheck",
      defaults={},
      funcname="SanityCheck",
      location="imgui_extra:75",
      namespace="ImGuiExtra",
      ov_cimguiname="ImGuiExtra_SanityCheck",
      ret="void",
      signature="(const char*)",
      stname=""},
    ["(const char*)"]=nil}}
t.ImGuiExtra_Curve["(const char*,const ImVec2,const int,ImVec2*,int*,const ImVec2,const ImVec2)"]=t.ImGuiExtra_Curve[1]
t.ImGuiExtra_CurveValue["(float,int,const ImVec2*)"]=t.ImGuiExtra_CurveValue[1]
t.ImGuiExtra_CurveValueSmooth["(float,int,const ImVec2*)"]=t.ImGuiExtra_CurveValueSmooth[1]
t.ImGuiExtra_DrawRowsBackground["(int,float,float,float,float,ImU32,ImU32)"]=t.ImGuiExtra_DrawRowsBackground[1]
t.ImGuiExtra_SanityCheck["(const char*)"]=t.ImGuiExtra_SanityCheck[1]
 return t