@echo off

call config.bat
call build_imgui.bat

%CC% main.cpp %IMGUI_BACKENDS% imgui.lib %CFLAGS% %LFLAGS% -DIMGUI_API=__declspec(dllimport) -DIMGUI_IMPL_API=""