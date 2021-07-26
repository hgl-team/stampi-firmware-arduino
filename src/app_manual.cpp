#include "../include/app_manual.h"
#include "../include/globaldef.h"

namespace stampi {
    namespace manual {
        sfc::Step steps[] = {
            sfc::Step(true)
            , sfc::Step()
            , sfc::Step()
            , sfc::Step()
            , sfc::Step()
            , sfc::Step()
            , sfc::Step()
            , sfc::Step()
        };
        sfc::Transition transitions[] = {
              sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 1), transition_0)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 2), transition_1)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 3), transition_2)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 4), transition_3)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 5), transition_4)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 6), transition_5)
            , sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 7), transition_6)
            , sfc::Transition(ARRAY(int, 1, 1), ARRAY(int, 1, 0), transition_7)
            , sfc::Transition(ARRAY(int, 1, 2), ARRAY(int, 1, 0), transition_8)
            , sfc::Transition(ARRAY(int, 1, 3), ARRAY(int, 1, 0), transition_9)
            , sfc::Transition(ARRAY(int, 1, 4), ARRAY(int, 1, 0), transition_10)
            , sfc::Transition(ARRAY(int, 1, 5), ARRAY(int, 1, 0), transition_11)
            , sfc::Transition(ARRAY(int, 1, 6), ARRAY(int, 1, 0), transition_12)
            , sfc::Transition(ARRAY(int, 1, 7), ARRAY(int, 1, 0), transition_13)
        };

        // 01C
        sfc::NonStoredAction N_mold_close = sfc::NonStoredAction(1, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_close))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_close))
        ));
        sfc::NonStoredAction N_mold_low_press = sfc::NonStoredAction(1, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_low_press))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_low_press))
        ));
        sfc::NonStoredAction N_mold_soft_move = sfc::NonStoredAction(1, N_mold_close_soft_move_activation, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_soft_move))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_soft_move))
        ));

        // 02C
        sfc::NonStoredAction N_mold_open = sfc::NonStoredAction(2, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_open))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_open))
        ));
        sfc::NonStoredAction N_mold_low_press_1 = sfc::NonStoredAction(2, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_low_press))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_low_press))
        ));
        sfc::NonStoredAction N_mold_soft_move_1 = sfc::NonStoredAction(2, N_mold_open_soft_move_activation, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_soft_move))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_soft_move))
        ));

        // 03C
        sfc::NonStoredAction N_inject = sfc::NonStoredAction(3, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_inject))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_inject))
        ));
        sfc::NonStoredAction N_inject_press = sfc::NonStoredAction(3, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_inject_press))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_inject_press))
        ));
        sfc::NonStoredAction N_mold_close_1 = sfc::NonStoredAction(3, N_inject_mold_close_activation, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_close))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_close))
        ));

        // 04C
        sfc::NonStoredAction N_load = sfc::NonStoredAction(4, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_load))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_load))
        ));

        // 05C
        sfc::NonStoredAction N_screw_return = sfc::NonStoredAction(5, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_screw_return))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_screw_return))
        ));

        // 06D
        sfc::NonStoredAction N_carrier_move_l = sfc::NonStoredAction(6, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_carrier_move_l))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_carrier_move_l))
        ));
        sfc::NonStoredAction N_mold_close_2 = sfc::NonStoredAction(6, N_inject_mold_close_activation, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_close))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_close))
        ));

        // 07D
        sfc::NonStoredAction N_carrier_move_r = sfc::NonStoredAction(7, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_carrier_move_r))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_carrier_move_r))
        ));
        sfc::NonStoredAction N_mold_close_3 = sfc::NonStoredAction(7, N_inject_mold_close_activation, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_close))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_close))
        ));

        sfc::Action * actions[] = {
            // 01D
              &N_mold_close 
            , &N_mold_low_press
            , &N_mold_soft_move
            // 02C
            , &N_mold_open
            , &N_mold_low_press_1
            , &N_mold_soft_move_1
            // 03C
            , &N_inject
            , &N_inject_press
            , &N_mold_close_1
            // 04C
            , &N_load
            // 05C
            , &N_screw_return
            // 06D
            , &N_carrier_move_l
            , &N_mold_close_2 
            // 07D
            , &N_carrier_move_r
            , &N_mold_close_3
        };

        sfc::Application app_manual = sfc::Application({
            { steps, APP_MANUAL_STEP_COUNT },
            { actions, APP_MANUAL_ACTION_COUNT},
            { transitions, APP_MANUAL_TRANSITION_COUNT }
        });

        void setup_app_manual() {
            
        }

        bool transition_0() { 
            return !hal_digital_read(IN_ES2) && hal_digital_read(IN_BTN_MC)
                && hal_digital_read(IN_DOOR);
        }
        bool transition_1() {
            return !hal_digital_read(IN_ES1) && hal_digital_read(IN_BTN_MO)
                && hal_digital_read(IN_DOOR);
         }
        bool transition_2() {
            return !hal_digital_read(IN_ES5) && hal_digital_read(IN_BTN_INJECT);
         }
        bool transition_3() { 
            return !hal_digital_read(IN_ES4) && !hal_digital_read(IN_ES3)
                && hal_digital_read(IN_BTN_LOAD);
        }
        bool transition_4() { 
            return !hal_digital_read(IN_ES3) && hal_digital_read(IN_BTN_SR);
        }
        bool transition_5() {
            return !hal_digital_read(IN_ES8) && hal_digital_read(IN_BTN_CL)
                && !hal_digital_read(IN_BTN_CR);
        }
        bool transition_6() { 
            return !hal_digital_read(IN_ES9) && hal_digital_read(IN_BTN_CR)
                && !hal_digital_read(IN_BTN_CL);
        }
        bool transition_7() { 
            return hal_digital_read(IN_ES2) || !hal_digital_read(IN_DOOR) 
                || !hal_digital_read(IN_BTN_MC);
        }
        bool transition_8() { 
            return hal_digital_read(IN_ES1) || !hal_digital_read(IN_DOOR) 
                || !hal_digital_read(IN_BTN_MO);
        }
        bool transition_9() { 
            return hal_digital_read(IN_ES5) || !hal_digital_read(IN_BTN_INJECT);
        }
        bool transition_10() { 
            return hal_digital_read(IN_ES4) || !hal_digital_read(IN_BTN_LOAD);
        }
        bool transition_11() { 
            return hal_digital_read(IN_ES3) || !hal_digital_read(IN_BTN_SR);
        }
        bool transition_12() { 
            return hal_digital_read(IN_ES8) || !hal_digital_read(IN_BTN_CL);
        }
        bool transition_13() { 
            return hal_digital_read(IN_ES9) || !hal_digital_read(IN_BTN_CR);
        }

        bool N_mold_close_soft_move_activation(const sfc::predicate_state_t &state) {
            return hal_digital_read(IN_MSC);
        }
        bool N_mold_open_soft_move_activation(const sfc::predicate_state_t &state) {
            return hal_digital_read(IN_MSO);
        }
        bool N_inject_mold_close_activation(const sfc::predicate_state_t &state) {
            return hal_digital_read(IN_ES2);
        }

        // 01D
        HANDLER_ACTIVATING(N_mold_close, state) { hal_digital_write(OUT_MOLD_CLOSE, true); }
        HANDLER_DEACTIVATING(N_mold_close, state) { hal_digital_write(OUT_MOLD_CLOSE, false); }
        HANDLER_ACTIVATING(N_mold_low_press, state) { hal_digital_write(OUT_MOLD_LOW_PRESS, true); }
        HANDLER_DEACTIVATING(N_mold_low_press, state) { hal_digital_write(OUT_MOLD_LOW_PRESS, false); }
        HANDLER_ACTIVATING(N_mold_soft_move, state) { hal_digital_write(OUT_MOLD_SOFT_MOVE, true); }
        HANDLER_DEACTIVATING(N_mold_soft_move, state) { hal_digital_write(OUT_MOLD_SOFT_MOVE, false); }

        // 02D
        HANDLER_ACTIVATING(N_mold_open, state) { hal_digital_write(OUT_MOLD_OPEN, true); }
        HANDLER_DEACTIVATING(N_mold_open, state) { hal_digital_write(OUT_MOLD_OPEN, false); }

        // 03D
        HANDLER_ACTIVATING(N_inject, state) { hal_digital_write(OUT_INJECT, true); }
        HANDLER_DEACTIVATING(N_inject, state) { hal_digital_write(OUT_INJECT, false); }
        HANDLER_ACTIVATING(N_inject_press, state) { hal_digital_write(OUT_INJECT_PRESS, true); }
        HANDLER_DEACTIVATING(N_inject_press, state) { hal_digital_write(OUT_INJECT_PRESS, false); }

        // 04D
        HANDLER_ACTIVATING(N_load, state) { hal_digital_write(OUT_LOAD, true); }
        HANDLER_DEACTIVATING(N_load, state) { hal_digital_write(OUT_LOAD, false); }

        // 05D
        HANDLER_ACTIVATING(N_screw_return, state) { hal_digital_write(OUT_SCREW_RET, true); }
        HANDLER_DEACTIVATING(N_screw_return, state) { hal_digital_write(OUT_SCREW_RET, false); }

        // 06D
        HANDLER_ACTIVATING(N_carrier_move_l, state) { hal_digital_write(OUT_CARRIER_MOVE_L, true); }
        HANDLER_DEACTIVATING(N_carrier_move_l, state) { hal_digital_write(OUT_CARRIER_MOVE_L, false); }

        // 07D
        HANDLER_ACTIVATING(N_carrier_move_r, state) { hal_digital_write(OUT_CARRIER_MOVE_R, true); }
        HANDLER_DEACTIVATING(N_carrier_move_r, state) { hal_digital_write(OUT_CARRIER_MOVE_R, false); }
    }
}