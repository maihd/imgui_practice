#include "cr.h"
#include "imgui.h"

#include <assert.h>

static int OnLoad(void);
static int OnUnload(void);
static int OnUpdate(void);

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
    return 0;
}

int OnUnload(void)
{
    return 0;
}

int OnUpdate(void)
{
    // ImGui::ShowDemoWindow(nullptr);
    return 0;    
}
