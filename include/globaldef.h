#ifndef STAMPI_GLOBAL_H_
#define STAMPI_GLOBAL_H_

#include <Application.h>

namespace stampi {
    extern bool stop;
    
    // Grafcet applications
    namespace main {
        extern sfc::Application app_main;
    }
    namespace injector {
        extern sfc::Application app_injector;
    }
    namespace sauto {
        extern sfc::Application app_sauto;
    }
    namespace manual {
        extern sfc::Application app_manual;
    }
}

#endif