#include "../include/app_sauto.h"

namespace stampi {
    namespace sauto {

        sfc::Step steps[] { 
            sfc::Step(true)     // 00C
            , sfc::Step()       // 01C
            , sfc::Step()       // 02C
            , sfc::Step()       // 03C
            , sfc::Step()       // 04C
            , sfc::Step()       // 05C
            , sfc::Step()       // 06C
            , sfc::Step()       // 07C
            , sfc::Step()       // 08C
            , sfc::Step()       // 09C
        };
        sfc::Transition transitions[] = {
              sfc::Transition(ARRAY(int, 1, 0), ARRAY(int, 1, 1), transition_0)
            , sfc::Transition(ARRAY(int, 1, 1), ARRAY(int, 1, 9), transition_1)
            , sfc::Transition(ARRAY(int, 1, 1), ARRAY(int, 1, 2), transition_2)
            , sfc::Transition(ARRAY(int, 1, 9), ARRAY(int, 1, 1), transition_3)
            , sfc::Transition(ARRAY(int, 1, 2), ARRAY(int, 1, 3), transition_4)
            , sfc::Transition(ARRAY(int, 1, 3), ARRAY(int, 1, 4), transition_5)
            , sfc::Transition(ARRAY(int, 1, 4), ARRAY(int, 1, 5), transition_6)
            , sfc::Transition(ARRAY(int, 1, 5), ARRAY(int, 1, 6), transition_7)
            , sfc::Transition(ARRAY(int, 1, 6), ARRAY(int, 1, 7), transition_8)
            , sfc::Transition(ARRAY(int, 1, 7), ARRAY(int, 1, 8), transition_9)
            , sfc::Transition(ARRAY(int, 1, 8), ARRAY(int, 1, 0), transition_10)
        };

        // 01C
        sfc::StoredAction S0_mold_close = sfc::StoredAction(1, HANDLER_ARRAY(2, 
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(S0_mold_close))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(S0_mold_close))
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
        sfc::StoredAction S0_inject = sfc::StoredAction(2, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(S0_inject))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(S0_inject))
        ));
        sfc::StoredAction S0_inject_press = sfc::StoredAction(2, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(S0_inject_press))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(S0_inject_press))
        ));

        // 03C
        sfc::NonStoredAction N_inject_low_press = sfc::NonStoredAction(3, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_inject_low_press))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_inject_low_press))
        ));
        sfc::NonStoredAction R0_mold_close_1 = sfc::NonStoredAction(3, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(R0_mold_close))
        ));
        sfc::NonStoredAction N_timer_inject_delay = sfc::NonStoredAction(3, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_timer_inject_delay))
        ));
        
        // 04C
        sfc::NonStoredAction R0_inject = sfc::NonStoredAction(4, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(R0_inject))
        ));
        sfc::NonStoredAction R0_inject_press = sfc::NonStoredAction(4, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(R0_inject_press))
        ));
        sfc::NonStoredAction N_load = sfc::NonStoredAction(4, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_load))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_load))
        ));

        // 05C
        sfc::NonStoredAction N_screw_return = sfc::NonStoredAction(5, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_screw_return))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_screw_return))
        ));

        // 06C
        sfc::NonStoredAction N_timer_cooling_delay = sfc::NonStoredAction(6, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_timer_cooling_delay))
        ));
        
        // 07C
        sfc::NonStoredAction N_mold_open = sfc::NonStoredAction(7, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_open))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_open))
        ));
        sfc::NonStoredAction N_mold_low_press_1 = sfc::NonStoredAction(7, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_low_press))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_low_press))
        ));
        sfc::NonStoredAction N_mold_soft_move_1 = sfc::NonStoredAction(7, N_mold_open_soft_move_activation, HANDLER_ARRAY(2,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_mold_soft_move))
            , ACTION_HANDLER_DEF(ACTION_STATE_DEACTIVATING, HANDLER_DEACTIVATING_REF(N_mold_soft_move))
        ));

        // 08C
        sfc::StoredAction S0_skip_auto_call = sfc::StoredAction(8);
        sfc::NonStoredAction N_piece_count_increase  =sfc::NonStoredAction(8, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_piece_count_increase))
        ));
        sfc::NonStoredAction N_timer_auto_delay = sfc::NonStoredAction(8, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(N_timer_auto_delay))
        ));
        

        // 09C
        sfc::NonStoredAction R0_mold_close = sfc::NonStoredAction(9, HANDLER_ARRAY(1,
              ACTION_HANDLER_DEF(ACTION_STATE_ACTIVATING, HANDLER_ACTIVATING_REF(R0_mold_close))
        ));

        sfc::Action * actions[] = {
            // 01C
              &S0_mold_close
            , &N_mold_low_press
            , &N_mold_soft_move
            // 02C
            , &S0_inject
            , &S0_inject_press
            // 03C
            , &N_inject_low_press
            , &R0_mold_close_1
            , &N_timer_inject_delay
            // 04C
            , &R0_inject
            , &R0_inject_press
            , &N_load
            // 05C
            , &N_screw_return
            // 06C
            , &N_timer_cooling_delay
            // 07C
            , &N_mold_open
            , &N_mold_low_press_1
            , &N_mold_soft_move_1
            // 08C
            , &S0_skip_auto_call
            , &N_piece_count_increase
            , &N_timer_auto_delay
            // 09C
            , &R0_mold_close
        };

        sfc::Application app_sauto = sfc::Application({
              { steps, APP_SAUTO_STEP_COUNT }
            , { actions, APP_SAUTO_ACTION_COUNT }
            , { transitions, APP_SAUTO_TRANSITION_COUNT }
        });

        void setup_app_sauto() {
          
        }
        
        bool transition_0() { 
          bool in_es1     = hal_digital_read(IN_ES1);
          bool in_es4     = hal_digital_read(IN_ES4);
          bool in_door    = hal_digital_read(IN_DOOR);
          bool in_aut     = hal_digital_read(IN_AUTO);
          bool in_saut    = hal_digital_read(IN_SAUTO);
          bool in_btn_sa  = hal_digital_read(IN_BTN_SA);
          bool skip_auto_call = S0_skip_auto_call.getState()->active;

          return in_es1 && in_es4 && in_door && (
            (in_aut && (in_btn_sa || skip_auto_call)) || 
            (in_saut && in_btn_sa));
        }
        bool transition_1() { 
          return !hal_digital_read(IN_DOOR);
        }
        bool transition_2() { 
          return hal_digital_read(IN_ES2) && hal_digital_read(IN_ES3); 
        }
        bool transition_3() { 
          return hal_digital_read(IN_DOOR) && hal_digital_read(IN_BTN_SA);
        }
        bool transition_4() { 
          return hal_digital_read(IN_ES2) && hal_digital_read(IN_ES5);
        }
        bool transition_5() {
          return timers[0].getState()->interrupted; 
        }
        bool transition_6() {
          return hal_digital_read(IN_ES4);
        }
        bool transition_7() {
          return hal_digital_read(IN_ES3);
        }
        bool transition_8() { 
          return timers[1].getState()->interrupted;
        }
        bool transition_9() {
          return hal_digital_read(IN_ES1);
        }
        bool transition_10() { 
          bool in_saut = hal_digital_read(IN_SAUTO);
          bool in_door = hal_digital_read(IN_DOOR);
          bool in_auto = hal_digital_read(IN_AUTO);

          return (in_saut && !in_door) || (in_auto && timers[2].getState()->interrupted);
        }

        bool N_mold_close_soft_move_activation(const sfc::predicate_state_t &state) {
          return hal_digital_read(IN_MSC);
        }

        bool N_mold_open_soft_move_activation(const sfc::predicate_state_t &state) {
          return hal_digital_read(IN_MSO);
        }

        // 01C
        HANDLER_ACTIVATING(S0_mold_close, state) { hal_digital_write(OUT_MOLD_CLOSE, true); }
        HANDLER_DEACTIVATING(S0_mold_close, state) { hal_digital_write(OUT_MOLD_CLOSE, false); }
        HANDLER_ACTIVATING(N_mold_low_press, state) { hal_digital_write(OUT_MOLD_LOW_PRESS, true); }
        HANDLER_DEACTIVATING(N_mold_low_press, state) { hal_digital_write(OUT_MOLD_LOW_PRESS, false); }
        HANDLER_ACTIVATING(N_mold_soft_move, state) { hal_digital_write(OUT_MOLD_SOFT_MOVE, true); }
        HANDLER_DEACTIVATING(N_mold_soft_move, state) { hal_digital_write(OUT_MOLD_SOFT_MOVE, false); }
        
        // 02C
        HANDLER_ACTIVATING(R0_mold_close, state) { S0_mold_close.shutdown(); }
        HANDLER_ACTIVATING(S0_inject, state) { hal_digital_write(OUT_INJECT, true); }
        HANDLER_DEACTIVATING(S0_inject, state) { hal_digital_write(OUT_INJECT, false); }
        HANDLER_ACTIVATING(S0_inject_press, state) { hal_digital_write(OUT_INJECT_PRESS, true); }
        HANDLER_DEACTIVATING(S0_inject_press, state) { hal_digital_write(OUT_INJECT_PRESS, false); }

        // 03C
        HANDLER_ACTIVATING(N_inject_low_press, state) { hal_digital_write(OUT_INJECT_LOW_PRESS, true); }
        HANDLER_DEACTIVATING(N_inject_low_press, state) { hal_digital_write(OUT_INJECT_LOW_PRESS, false); }
        HANDLER_ACTIVATING(N_timer_inject_delay, state) { timers[0].reset(); timers[0].enable(); }

        HANDLER_ACTIVATING(R0_inject, state) { S0_inject.shutdown(); }
        HANDLER_ACTIVATING(R0_inject_press, state) { S0_inject_press.shutdown(); }
        HANDLER_ACTIVATING(N_load, state) { hal_digital_write(OUT_LOAD, true); }
        HANDLER_DEACTIVATING(N_load, state) { hal_digital_write(OUT_LOAD, false); }

        HANDLER_ACTIVATING(N_screw_return, state) { hal_digital_write(OUT_SCREW_RET, true); }
        HANDLER_DEACTIVATING(N_screw_return, state) { hal_digital_write(OUT_SCREW_RET, false); }

        HANDLER_ACTIVATING(N_timer_cooling_delay, state) { timers[1].reset(); timers[1].enable(); }

        HANDLER_ACTIVATING(N_mold_open, state) { hal_digital_write(OUT_MOLD_OPEN, true); }
        HANDLER_DEACTIVATING(N_mold_open, state) { hal_digital_write(OUT_MOLD_OPEN, false); }

        HANDLER_ACTIVATING(N_piece_count_increase, state) { stampi::piece_count++; }
        HANDLER_ACTIVATING(N_timer_auto_delay, state) { timers[2].reset(); timers[2].enable(); }
    }
}