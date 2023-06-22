@echo off

call config.bat

%CC% -shared -o lib.dll lib.cpp imgui.lib %CFLAGS% %LFLAGS% -DIMGUI_API=__declspec(dllimport)