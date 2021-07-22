#define ACTION_HANDLER_DEF(state, handler_name) { state, handler_name }

#define HANDLER_ACTIVATING_REF(action_name)     action_name##_activating_handler
#define HANDLER_ACTIVE_REF(action_name)         action_name##_active_handler
#define HANDLER_DEACTIVATING_REF(action_name)   action_name##_deactivating_handler
#define HANDLER_INACTIVE_REF(action_name)       action_name##_inactive_handler

#define HANDLER_ACTIVATING(action_name, var)     void action_name##_activating_handler(const sfc::stateful_state_t &var)
#define HANDLER_ACTIVE(action_name, var)         void action_name##_active_handler(const sfc::stateful_state_t &var)
#define HANDLER_DEACTIVATING(action_name, var)   void action_name##_deactivating_handler(const sfc::stateful_state_t &var)
#define HANDLER_INACTIVE(action_name, var)       void action_name##_inactive_handler(const sfc::stateful_state_t &var)

#define HANDLER_ARRAY(n, ...) {(sfc::state_handler_t[]){ __VA_ARGS__ }, n}