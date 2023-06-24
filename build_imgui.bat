@echo off

call config.bat

set IMGUI_FREETYPE=imgui/misc/freetype/imgui_freetype.cpp -DIMGUI_ENABLE_FREETYPE

%CC% -shared -o imgui.dll %IMGUI% -DIMGUI_API=__declspec(dllexport)