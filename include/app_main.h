#ifndef STAMPI_MAIN_APP__
#define STAMPI_MAIN_APP__

#include <sfctypes.h>
#include <Application.h>
#include <NonStoredAction.h>
#include <StoredAction.h>
#include "macros.h"
#include "microhal.h"
#include "globaldef.h"
#include "hardwaredef.h"

namespace stampi {
    namespace main {
        bool transition_0();
        bool transition_1();
        bool transition_2();
        bool transition_3();
        bool transition_4();
        bool transition_5();
        bool transition_6();
        bool transition_7();
        bool transition_8();
        bool transition_9();

        void R0_stampi_activating_handler(const sfc::stateful_state_t &state);
        void S0_stampi_activating_handler(const sfc::stateful_state_t &state);
        void S0_stampi_deactivating_handler(const sfc::stateful_state_t &state);
        void P_toggle_stop_activating_handler(const sfc::stateful_state_t &state);
        void R0_hold_activating_handler(const sfc::stateful_state_t &state);
        
        void setup_app_main();
    }
};


#endif