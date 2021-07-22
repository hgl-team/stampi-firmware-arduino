#ifndef APP_STAMPI_H_
#define APP_STAMPI_H_

#include <sfctypes.h>
#include <NonStoredAction.h>
#include <StoredAction.h>
#include <Application.h>

#include "globaldef.h"
#include "hardwaredef.h"
#include "macros.h"
#include "microhal.h"

#define APP_INJECTOR_STEP_COUNT         4
#define APP_INJECTOR_TRANSITION_COUNT   6
#define APP_INJECTOR_ACTION_COUNT       7

namespace stampi {
    namespace injector {
        bool transition_0();
        bool transition_1();
        bool transition_2();
        bool transition_3();
        bool transition_4();
        bool transition_5();

        extern sfc::Step steps[];
        extern sfc::Transition transitions[];
        extern sfc::Action* actions[];

        extern sfc::StoredAction S0_pump;
        extern sfc::NonStoredAction R0_saut;
        extern sfc::NonStoredAction R0_manual;
        extern sfc::StoredAction S0_saut;
        extern sfc::StoredAction S0_manual;

        void setup_app_injector();

        void S0_pump_activating_handler(const sfc::stateful_state_t &state);
        void S0_pump_deactivating_handler(const sfc::stateful_state_t &state);
        void R0_saut_activating_handler(const sfc::stateful_state_t &state);
        void R0_manual_activating_handler(const sfc::stateful_state_t &state);
        void S0_saut_activating_handler(const sfc::stateful_state_t &state);
        void S0_saut_deactivating_handler(const sfc::stateful_state_t &state);
        void S0_manual_activating_handler(const sfc::stateful_state_t &state);
        void S0_manual_deactivating_handler(const sfc::stateful_state_t &state);
    }
}

#endif