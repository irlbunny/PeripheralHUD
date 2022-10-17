#pragma once
#include "main.hpp"

namespace peripheral_hud {

namespace hooks {
    void EnvironmentSceneSetup();
}

class plugin {
public:
    plugin();

private:
    void InstallHooks();
};

}

extern peripheral_hud::plugin* g_Plugin;
