#include "../include/globaldef.h"

namespace stampi {
    bool stop = 0;

    sfc::Timer timers[] = {
        // app_sauto
          sfc::Timer(0, false)
        , sfc::Timer(0, false)
        , sfc::Timer(0, false)
    };
}