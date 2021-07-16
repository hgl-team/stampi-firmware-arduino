#define ARRAY(t, n, ...) {(t[]){ __VA_ARGS__ }, n}
#define ACTION_HANDLER_DEF(state, handlername) { state, handlername }