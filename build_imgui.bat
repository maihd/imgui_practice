@echo off

call config.bat

%CC% -shared -o imgui.dll %IMGUI% -DIMGUI_API=__declspec(dllexport)