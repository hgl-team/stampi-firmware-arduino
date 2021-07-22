#include "../include/app_injector.h"
#include "../include/globaldef.h"

namespace stampi {
    namespace injector {
        sfc::Step steps[] = {
              sfc::Step(true)   // 00B
            , sfc::Step()       // 01B
            , sfc::Step()       // 02B
            , sfc::Step()       // 03B
        };
        sfc::Transition transitions[] = {
              sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 1), transition_0)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 2), transition_1)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 3), transition_2)
            , sfc::Transition(ARRAY(int, 1, 1), ARRAY(int, 1, 0), transition_3)
            , sfc::Transition(ARRAY(int, 1, 2), ARRAY(int, 1, 0), transition_4)
            , sfc::Transition(ARRAY(int, 1, 3), ARRAY(int, 1, 0), transition_5)
        };

        sfc::StoredAction S0_pump = sfc::StoredAction(0, ARRAY(sfc::state_handler_t, 2, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, S0_pump_activating_handler),
            ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, S0_pump_deactivating_handler)
        ));
        sfc::NonStoredAction R0_saut = sfc::NonStoredAction(1, ARRAY(sfc::state_handler_t, 1, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, R0_saut_activating_handler)
        ));
        sfc::NonStoredAction R0_manual = sfc::NonStoredAction(2, ARRAY(sfc::state_handler_t, 1, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, R0_manual_activating_handler)
        ));
        sfc::StoredAction S0_saut = sfc::StoredAction(2, ARRAY(sfc::state_handler_t, 2, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, S0_saut_activating_handler),
            ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, S0_saut_deactivating_handler)
        ));
        sfc::StoredAction S0_manual = sfc::StoredAction(1, ARRAY(sfc::state_handler_t, 2, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, S0_manual_activating_handler),
            ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, S0_manual_deactivating_handler)
        ));
        sfc::NonStoredAction R0_saut_2 = sfc::NonStoredAction(3, ARRAY(sfc::state_handler_t, 1, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, R0_saut_activating_handler)
        ));
        sfc::NonStoredAction R0_manual_2 = sfc::NonStoredAction(3, ARRAY(sfc::state_handler_t, 1, 
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, R0_manual_activating_handler)
        ));

        sfc::Action * actions[] = {
            &S0_pump
            , &R0_saut
            , &R0_manual
            , &S0_saut
            , &S0_manual
            , &R0_saut_2
            , &R0_manual_2
        };

        sfc::Application app_injector = sfc::Application({
            { steps, APP_INJECTOR_STEP_COUNT }, 
            { actions, APP_INJECTOR_ACTION_COUNT },
            { transitions, APP_INJECTOR_TRANSITION_COUNT }
        });

        void setup_app_injector() { }

        bool transition_0() {
            bool in_manual  = hal_digital_read(IN_MANUAL);
            bool in_saut    = hal_digital_read(IN_SAUTO);
            bool in_aut     = hal_digital_read(IN_AUTO);

            return in_manual && !(in_saut || in_aut);
        }
        bool transition_1() {
            bool in_manual  = hal_digital_read(IN_MANUAL);
            bool in_saut    = hal_digital_read(IN_SAUTO);
            bool in_aut     = hal_digital_read(IN_AUTO);

            return !in_manual && (in_saut || in_aut);
        }
        bool transition_2() {
            bool in_manual  = hal_digital_read(IN_MANUAL);
            bool in_saut    = hal_digital_read(IN_SAUTO);
            bool in_aut     = hal_digital_read(IN_AUTO);

            return in_manual && (in_saut || in_aut);
        }
        bool transition_3() {
            return S0_manual.getState()->active && !S0_saut.getState()->active;
        }
        bool transition_4() {
            return !S0_manual.getState()->active && S0_saut.getState()->active;
        }
        bool transition_5() {
            return !S0_manual.getState()->active && !S0_saut.getState()->active;
        }

        void S0_pump_activating_handler(const sfc::stateful_state_t &state) {
            hal_digital_write(OUT_PUMP, true);
        }
        void S0_pump_deactivating_handler(const sfc::stateful_state_t &state) {
            hal_digital_write(OUT_PUMP, false);
        }
        void R0_saut_activating_handler(const sfc::stateful_state_t &state) {
            S0_saut.shutdown();
        }
        void R0_manual_activating_handler(const sfc::stateful_state_t &state) {
            S0_manual.shutdown();
        }
        void S0_saut_activating_handler(const sfc::stateful_state_t &state) {
            stampi::sauto::app_sauto.activate();
        }
        void S0_saut_deactivating_handler(const sfc::stateful_state_t &state) {
            stampi::sauto::app_sauto.shutdown();
        }
        void S0_manual_activating_handler(const sfc::stateful_state_t &state) {
            stampi::manual::app_manual.activate();
        }
        void S0_manual_deactivating_handler(const sfc::stateful_state_t &state) {
            stampi::manual::app_manual.shutdown();
        }
    }
}