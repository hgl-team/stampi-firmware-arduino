#ifndef STAMPI_GLOBAL_H_
#define STAMPI_GLOBAL_H_

#include <stdint.h>
#include <Application.h>
#include <Timer.h>
#include <Clock.h>

#define TIMER_COUNT                     3
#define CLOCK_EVENT_LISTENER_COUNT      7

namespace stampi {
    extern uint16_t stop;
    extern uint32_t piece_count;
    extern uint8_t mac_address[];

    extern sfc::Timer timers[];
    extern sfc::Clock clock;

    void application_setup();
    void application_loop(const sfc::time_t & time);
    
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