#ifndef APP_MANUAL_H_
#define APP_MANUAL_H_

#include <Application.h>
#include <NonStoredAction.h>

#include "macros.h"
#include "hardwaredef.h"
#include "microhal.h"

#define APP_MANUAL_STEP_COUNT           8
#define APP_MANUAL_ACTION_COUNT         15
#define APP_MANUAL_TRANSITION_COUNT     14

namespace stampi {
    namespace manual {
        extern sfc::Step steps[];
        extern sfc::Transition transitions[];
        extern sfc::Action * actions[];

        extern sfc::NonStoredAction N_mold_close;
        extern sfc::NonStoredAction N_mold_low_press;
        extern sfc::NonStoredAction N_mold_soft_move;

        // 02C
        extern sfc::NonStoredAction N_mold_open;
        extern sfc::NonStoredAction N_mold_low_press_1;
        extern sfc::NonStoredAction N_mold_soft_move_1;

        // 03C
        extern sfc::NonStoredAction N_inject;
        extern sfc::NonStoredAction N_inject_press;
        extern sfc::NonStoredAction N_mold_close_1;

        // 04C
        extern sfc::NonStoredAction N_load;

        // 05C
        extern sfc::NonStoredAction N_screw_return;

        // 06D
        extern sfc::NonStoredAction N_carrier_move_l;
        extern sfc::NonStoredAction N_mold_close_2;

        // 07D
        extern sfc::NonStoredAction N_carrier_move_r;
        extern sfc::NonStoredAction N_mold_close_2;

        void setup_app_manual();

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
        bool transition_10();
        bool transition_11();
        bool transition_12();
        bool transition_13();

        bool N_mold_close_soft_move_activation(const sfc::predicate_state_t &state);
        bool N_mold_open_soft_move_activation(const sfc::predicate_state_t &state);
        bool N_inject_mold_close_activation(const sfc::predicate_state_t &state);

        // 01D
        HANDLER_ACTIVATING(N_mold_close, state);
        HANDLER_DEACTIVATING(N_mold_close, state);
        HANDLER_ACTIVATING(N_mold_low_press, state);
        HANDLER_DEACTIVATING(N_mold_low_press, state);
        HANDLER_ACTIVATING(N_mold_soft_move, state);
        HANDLER_DEACTIVATING(N_mold_soft_move, state);

        // 02D
        HANDLER_ACTIVATING(N_mold_open, state);
        HANDLER_DEACTIVATING(N_mold_open, state);

        // 03D
        HANDLER_ACTIVATING(N_inject, state);
        HANDLER_DEACTIVATING(N_inject, state);
        HANDLER_ACTIVATING(N_inject_press, state);
        HANDLER_DEACTIVATING(N_inject_press, state);

        // 04D
        HANDLER_ACTIVATING(N_load, state);
        HANDLER_DEACTIVATING(N_load, state);

        // 05D
        HANDLER_ACTIVATING(N_screw_return, state);
        HANDLER_DEACTIVATING(N_screw_return, state);

        // 06D
        HANDLER_ACTIVATING(N_carrier_move_l, state);
        HANDLER_DEACTIVATING(N_carrier_move_l, state);

        // 07D
        HANDLER_ACTIVATING(N_carrier_move_r, state);
        HANDLER_DEACTIVATING(N_carrier_move_r, state);
    }
}

#endif