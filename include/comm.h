#include <stdint.h>

#include "../include/microhal.h"
#include "../include/globaldef.h"

#define U16_PTRAT_N(ptr, n) (((uint16_t*)(ptr)) + (n))
#define COMM_MODBUS_REGISTER_COUNT          12
#define COMM_MODBUS_UNIT_ID                 33
#define COMM_MODBUS_PORT                    502

#define COMM_SERIAL_BAUDRATE                115200

namespace stampi {
    namespace comm {

        void comm_setup();
        void comm_loop();
    }
}