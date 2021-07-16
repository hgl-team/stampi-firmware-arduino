#include "../include/app_main.h"

namespace stampi {
    namespace main {
        sfc::Step steps[] = {
            sfc::Step(true),    // [0] = 00A
            sfc::Step(),        // [1] = 01A
            sfc::Step(),        // [2] = 02A
            sfc::Step(),        // [3] = 03A
            sfc::Step(),        // [4] = 04A
            sfc::Step(),        // [5] = 05A
        };

        sfc::Transition transitions[] = {
            sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1,  1), transition_0),
            sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1,  2), transition_1),
            sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1,  3), transition_2),
            sfc::Transition(ARRAY(int, 1, 1), ARRAY(int, 1,  3), transition_3),
            sfc::Transition(ARRAY(int, 1, 2), ARRAY(int, 1,  3), transition_4),
            sfc::Transition(ARRAY(int, 1, 3), ARRAY(int, 1,  4), transition_5),
            sfc::Transition(ARRAY(int, 1, 3), ARRAY(int, 1,  5), transition_6),
            sfc::Transition(ARRAY(int, 1, 3), ARRAY(int, 1,  0), transition_7),
            sfc::Transition(ARRAY(int, 1, 4), ARRAY(int, 1,  0), transition_8),
            sfc::Transition(ARRAY(int, 1, 5), ARRAY(int, 1,  0), transition_9)
        };
        
        sfc::NonStoredAction    R0_stampi = sfc::NonStoredAction(1, ARRAY(sfc::state_handler_t, 1,
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING,     R0_stampi_activating_handler)
        ));
        sfc::StoredAction       S0_stampi = sfc::StoredAction(2, ARRAY(sfc::state_handler_t, 2,
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING,     S0_stampi_activating_handler),
            ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING,   S0_stampi_deactivating_handler)
        ));
        sfc::NonStoredAction    P_toggle_stop = sfc::NonStoredAction(4, ARRAY(sfc::state_handler_t, 1,
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING,     P_toggle_stop_activating_handler)
        ));
        sfc::StoredAction       S0_hold = sfc::StoredAction(4);
        sfc::NonStoredAction    R0_hold = sfc::NonStoredAction(5, ARRAY(sfc::state_handler_t, 1,
            ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING,     R0_hold_activating_handler)
        ));

        sfc::Action* actions[] = {
            &R0_stampi, 
            &S0_stampi, 
            &P_toggle_stop, 
            &S0_hold, 
            &R0_stampi
        };
        
        sfc::Application app_main = sfc::Application({ 
            { steps, 6 }, 
            { actions, 5 },
            { transitions, 10 }
        });

        // Implementation
        void setup_app_main() {
        }

        bool transition_0() {
            return stampi::stop && (stampi::injector::app_injector.getState()->active);
        }
        bool transition_1() {
            return !stampi::stop && !(stampi::injector::app_injector.getState()->active);
        }
        bool transition_2() {
            return stampi::stop ^ (stampi::injector::app_injector.getState()->active);
        }
        bool transition_3() {
            return !(stampi::injector::app_injector.getState()->active);
        }
        bool transition_4() {
            return stampi::injector::app_injector.getState()->active;
        }
        bool transition_5() {
            return hal_digital_read(IN_START) && !S0_hold.getState()->active;
        }
        bool transition_6() {
            return !hal_digital_read(IN_START);
        }
        bool transition_7() {
            return hal_digital_read(IN_START) && S0_hold.getState()->active;
        }
        bool transition_8() {
            return S0_hold.getState()->active;
        }
        bool transition_9() {
            return !S0_hold.getState()->active;
        }

        void R0_stampi_activating_handler(const sfc::stateful_state_t &state) {
            S0_stampi.shutdown();
        }
        void S0_stampi_activating_handler(const sfc::stateful_state_t &state) {
            stampi::injector::app_injector.activate();
        }
        void S0_stampi_deactivating_handler(const sfc::stateful_state_t &state) {
            stampi::injector::app_injector.shutdown();
        }
        void P_toggle_stop_activating_handler(const sfc::stateful_state_t &state) {
            stampi::stop = !stampi::stop;
        }
        void R0_hold_activating_handler(const sfc::stateful_state_t &state) {
            S0_hold.shutdown();
        }
    }
}