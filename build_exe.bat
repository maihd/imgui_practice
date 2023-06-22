@echo off

call config.bat

:: Build imgui
set BUILD_IMGUI=false
if not exist imgui.dll (
set BUILD_IMGUI=true
)

if not exist imgui.lib (
set BUILD_IMGUI=true
)

if %BUILD_IMGUI%==true (
call build_imgui.bat
)

:: CR need lib.dll exist to run (unlike HotDylib)
if not exist lib.dll (
call build_lib.bat
)

:: Build resource to attach icon to .exe
if not exist main.res (
call build_res.bat
)

:: Actually build the .exe
%CC% main.cpp main.res imgui.lib %IMGUI_BACKENDS% %CFLAGS% %LFLAGS% -DIMGUI_API=__declspec(dllimport) -DIMGUI_IMPL_API=""