#include "main.hpp"
#include "plugin.hpp"
#include "config.hpp"

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    
    modInfo = info;

    getPeripheralHUDConfig().Init(modInfo);
}

extern "C" void load() {
    il2cpp_functions::Init();

    g_Plugin = new peripheral_hud::plugin;
}
