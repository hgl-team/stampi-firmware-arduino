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

#define APP_MAIN_STEP_COUNT         6
#define APP_MAIN_TRANSITION_COUNT   10
#define APP_MAIN_ACTION_COUNT       5

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

        extern sfc::Step steps[];
        extern sfc::Transition transitions[];
        extern sfc::Action* actions[];

        extern sfc::NonStoredAction    R0_stampi;
        extern sfc::StoredAction       S0_stampi;
        extern sfc::NonStoredAction    P_toggle_stop;
        extern sfc::StoredAction       S0_hold;
        extern sfc::NonStoredAction    R0_hold;

        class AppMainEventListener : public sfc::EventListener
        {
        public:
            AppMainEventListener(/* args */);
            ~AppMainEventListener();

            virtual void onActivationChanged(const sfc::stateful_state_t &state);
        };        
    }
};


#endif