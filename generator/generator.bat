:: this script must be executed in this directory
:: all the output goes to generator/output folder
:: .cpp and .h files:
:: cimplot.h and cimplot.cpp with gcc preprocess
:: lua and json files:
:: definitions.lua for function definitions
:: structs_and_enums.lua with struct and enum information-definitions
:: impl_definitions.lua for implementation function definitions

:: set your PATH if necessary for LuaJIT or Lua5.1 or luajit with: (for example)
set PATH=%PATH%;C:\anima;C:\mingws\i686-7.2.0-release-posix-dwarf-rt_v5-rev1\mingw32\bin;
:: set PATH=%PATH%;C:\luaGL;C:\i686-7.2.0-release-posix-dwarf-rt_v5-rev1\mingw32\bin;
:: set PATH=%PATH%;C:\luaGL\sources\luajit-master\luajit-master\bin\mingw32;C:\mingw32\bin;
::process  files
:: arg[1] compiler name g++, gcc, clang or cl
:: arg[2] "" or "comments"
:: arg[3] module name
:: arg[4..] headers 
luajit ./generator.lua g++ "" cimgui_extra ../extra/imgui_extra.h
luajit ./generator.lua g++ "" cimgui_knobs ../imgui-knobs/imgui_knobs.h

::leave console open
cmd /k

