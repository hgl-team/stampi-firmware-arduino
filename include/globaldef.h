#ifndef STAMPI_GLOBAL_H_
#define STAMPI_GLOBAL_H_

#include <Application.h>
#include <Timer.h>

#define TIMER_COUNT         3

namespace stampi {
    extern bool stop;

    extern sfc::Timer timers[];
    
    // Grafcet applications
    namespace main {
        extern sfc::Application app_main;
    }
    namespace injector {
        extern sfc::Application app_injector;
        extern sfc::Timer timer_2s;
        extern sfc::Timer timer_inject_delay;
        extern sfc::Timer timer_cooling_delay;
        extern sfc::Timer timer_auto_delay;
    }
    namespace sauto {
        extern sfc::Application app_sauto;
    }
    namespace manual {
        extern sfc::Application app_manual;
    }
}

#endif