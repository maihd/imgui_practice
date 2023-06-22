@echo off

set CC=clang++

set CFLAGS=-Wno-reorder-init-list -std=c++14 -Iimgui
set LFLAGS=-fuse-ld=lld -lUser32 -lOpenGL32

set IMGUI=imgui/imgui.cpp imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
set IMGUI_BACKENDS=-Iimgui/backends imgui/backends/imgui_impl_win32.cpp imgui/backends/imgui_impl_opengl3.cpp