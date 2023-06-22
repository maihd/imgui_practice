@echo off

set IMGUI=imgui/imgui.cpp imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
set IMGUI_BACKENDS=-Iimgui -Iimgui/backends imgui/backends/imgui_impl_win32.cpp imgui/backends/imgui_impl_opengl3.cpp

set CFLAGS=-Wno-reorder-init-list -std=c++14
set LFLAGS=-fuse-ld=lld -lUser32 -lOpenGL32

clang++ main.cpp %IMGUI% %IMGUI_BACKENDS% %CFLAGS% %LFLAGS%