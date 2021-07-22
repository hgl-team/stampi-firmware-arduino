#ifndef APP_SAUTO_H_
#define APP_SAUTO_H_

#include <sfctypes.h>
#include <Application.h>
#include <NonStoredAction.h>
#include <StoredAction.h>

#include "macros.h"
#include "../include/globaldef.h"
#include "../include/hardwaredef.h"
#include "../include/microhal.h"

#define APP_SAUTO_STEP_COUNT        10
#define APP_SAUTO_TRANSITION_COUNT  11
#define APP_SAUTO_ACTION_COUNT      19

namespace stampi {
    namespace sauto {
        extern sfc::Step steps[];
        extern sfc::Transition transitions[];
        extern sfc::Action * actions[];

        // 01C
        extern sfc::StoredAction S0_mold_close;
        extern sfc::NonStoredAction N_mold_low_press;
        extern sfc::NonStoredAction N_mold_soft_move;
        
        // 02C
        extern sfc::StoredAction S0_inject;
        extern sfc::StoredAction S0_inject_press;

        // 03C
        extern sfc::NonStoredAction N_inject_low_press;
        extern sfc::NonStoredAction R0_mold_close_1;
        extern sfc::NonStoredAction N_timer_inject_delay;

        // 04C
        extern sfc::NonStoredAction R0_inject;
        extern sfc::NonStoredAction R0_inject_press;
        extern sfc::NonStoredAction N_load;

        // 05C
        extern sfc::NonStoredAction N_screw_return;

        // 06C
        extern sfc::NonStoredAction N_timer_cooling_delay;

        // 07C
        extern sfc::NonStoredAction N_mold_open;
        extern sfc::NonStoredAction N_mold_low_press_1;
        extern sfc::NonStoredAction N_mold_soft_move_1;

        // 08C
        extern sfc::StoredAction S0_skip_auto_call;
        extern sfc::NonStoredAction N_timer_auto_delay;

        // 09C
        extern sfc::NonStoredAction R0_mold_close;
        
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

        bool N_mold_close_soft_move_activation(const sfc::predicate_state_t &state);
        bool N_mold_open_soft_move_activation(const sfc::predicate_state_t &state);

        // 01C
        HANDLER_ACTIVATING(S0_mold_close, state);
        HANDLER_DEACTIVATING(S0_mold_close, state);
        HANDLER_ACTIVATING(N_mold_low_press, state);
        HANDLER_DEACTIVATING(N_mold_low_press, state);
        HANDLER_ACTIVATING(N_mold_soft_move, state);
        HANDLER_DEACTIVATING(N_mold_soft_move, state);
        
        // 02C
        HANDLER_ACTIVATING(S0_inject, state);
        HANDLER_DEACTIVATING(S0_inject, state);
        HANDLER_ACTIVATING(S0_inject_press, state);
        HANDLER_DEACTIVATING(S0_inject_press, state);

        // 03C
        HANDLER_ACTIVATING(N_inject_low_press, state);
        HANDLER_DEACTIVATING(N_inject_low_press, state);
        HANDLER_ACTIVATING(N_timer_inject_delay, state);

        // 04C
        HANDLER_ACTIVATING(R0_inject, state);
        HANDLER_ACTIVATING(R0_inject_press, state);
        HANDLER_ACTIVATING(N_load, state);
        HANDLER_DEACTIVATING(N_load, state);

        // 05C
        HANDLER_ACTIVATING(N_screw_return, state);
        HANDLER_DEACTIVATING(N_screw_return, state);

        // 06C
        HANDLER_ACTIVATING(N_timer_cooling_delay, state);

        // 07C
        HANDLER_ACTIVATING(N_mold_open, state);
        HANDLER_DEACTIVATING(N_mold_open, state);

        // 08C
        HANDLER_ACTIVATING(N_timer_auto_delay, state);

        // 09C
        HANDLER_ACTIVATING(R0_mold_close, state);
    }
}

#endif