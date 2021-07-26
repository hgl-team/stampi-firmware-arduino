#include "../include/globaldef.h"
#include "../include/app_main.h"
#include "../include/app_injector.h"
#include "../include/app_manual.h"
#include "../include/app_sauto.h"
#include "../include/comm.h"

namespace stampi {
    uint16_t stop = 0;
    uint32_t piece_count = 0;
    uint8_t mac_address[] = { 123, 245, 6, 21, 107, 4 };

    sfc::Timer timers[] = {
        // app_sauto
          sfc::Timer(0, false)
        , sfc::Timer(0, false)
        , sfc::Timer(0, false)
    };
    sfc::ClockListener * listeners[] {
        &timers[0]
      , &timers[1]
      , &timers[2]
      , &stampi::main::app_main
      , &stampi::injector::app_injector
      , &stampi::manual::app_manual
      , &stampi::sauto::app_sauto
    };

    sfc::Clock clock = sfc::Clock({ listeners, CLOCK_EVENT_LISTENER_COUNT });

    void application_setup() {
      stampi::comm::comm_setup();
      stampi::main::setup_app_main();
      stampi::injector::setup_app_injector();
      stampi::manual::setup_app_manual();
      stampi::sauto::setup_app_sauto();
    }

    void application_loop(const sfc::time_t & time) {
      clock.tick(time);
      stampi::comm::comm_loop();
    }
}