#include "cr.h"
#include "imgui.h"

#include <assert.h>

static int OnLoad(void);
static int OnUnload(void);
static int OnUpdate(void);

static void LoadStyle_Windows10(void);
static void LoadStyle_Windows11(void);

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation)
{
    assert(ctx);
    switch (operation)
    {
        case CR_LOAD:   return OnLoad(); // loading back from a reload
        case CR_UNLOAD: return OnUnload(); // preparing to a new reload
        case CR_CLOSE:  // the plugin will close and not reload anymore
        default:
        break;
    }
    
    // CR_STEP
    return OnUpdate();
}

int OnLoad(void)
{
    bool isWindows11 = false;
    if (!isWindows11)
    {
        LoadStyle_Windows10();
    }
    else
    {
        LoadStyle_Windows11();
    }
    
    return 0;
}

int OnUnload(void)
{
    return 0;
}

int OnUpdate(void)
{
    // Style editor
    static bool show_style_editor = true;
    
    // Demo window
    // ImGui::ShowDemoWindow(nullptr);
    
    // Make ImGui window full-fill with OS window
#if 0 // MAIN_WINDOW WILL SWALLOW OTHER WINDOW?
#ifdef IMGUI_HAS_VIEWPORT
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->GetWorkPos());
    ImGui::SetNextWindowSize(viewport->GetWorkSize());
    ImGui::SetNextWindowViewport(viewport->ID);
#else
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
#endif
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    
    // Begin main window
    if (ImGui::Begin("Main Window",
                     nullptr,
                     ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize))
    {
        // Main menu
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Close"))
                {
                    // close here
                }
                
                ImGui::EndMenu();
            }
            
            if (ImGui::BeginMenu("Window"))
            {
                if (ImGui::MenuItem("Style Editor"))
                {
                    show_style_editor = !show_style_editor;
                }
                
                ImGui::EndMenu();
            }
            
            ImGui::EndMainMenuBar();
        }
        
        // Other widgets
        
        // End main window
        ImGui::End();
    }
    
    ImGui::PopStyleVar(1);
#endif
    
    // Show style editor window
    if (show_style_editor)
    {
        ImGui::ShowStyleEditor();
    }
    
    return 0;    
}

// Styling

void LoadStyle_Windows10(void)
{
    ImGuiStyle& style = ImGui::GetStyle();
    style.FramePadding = ImVec2(8.0f, 8.0f);
    style.ScrollbarSize = 12.0f;
    style.GrabMinSize = 16.0f;
    style.WindowRounding = 0.0f;
    style.TabRounding = 0.0f;
    
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_TitleBgActive] = colors[ImGuiCol_WindowBg];
}

void LoadStyle_Windows11(void)
{
    ImGuiStyle& style = ImGui::GetStyle();
    //style.FramePadding = ImVec2(8.0f, 8.0f);
    //style.ScrollbarSize = 12.0f;
    //style.GrabMinSize = 16.0f;
    //style.WindowRounding = 0.0f;
    
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_TitleBgActive] = colors[ImGuiCol_WindowBg];
}

//! End of file, newline required by GCC
