#include "../include/comm.h"

#include <umodbus.h>
#include <umodbus_tcp.h>
#include <Ethernet.h>
#include <EthernetServer.h>

#define MODBUS_REGISTER(address, type, pointer) { address, type, pointer }

namespace stampi {
    uint8_t mac_address[] = { 123, 245, 6, 21, 107, 4 };

    namespace comm {
        umodbus::register_t registers[] = {
              MODBUS_REGISTER(0,  UMODBUS_TYPE_COIL,              UMODBUS_U16_PTROF(stampi::stop))
            , MODBUS_REGISTER(1,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::mac_address, 0))
            , MODBUS_REGISTER(2,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::mac_address, 1))
            , MODBUS_REGISTER(3,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::mac_address, 2))
            , MODBUS_REGISTER(4,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::timers[0].getPeriod(), 1))
            , MODBUS_REGISTER(5,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::timers[0].getPeriod(), 0))
            , MODBUS_REGISTER(6,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::timers[1].getPeriod(), 1))
            , MODBUS_REGISTER(7,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::timers[1].getPeriod(), 0))
            , MODBUS_REGISTER(8,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::timers[2].getPeriod(), 1))
            , MODBUS_REGISTER(9,  UMODBUS_TYPE_HOLDING_REGISTER,  U16_PTRAT_N(stampi::timers[2].getPeriod(), 0))
            , MODBUS_REGISTER(10,  UMODBUS_TYPE_HOLDING_REGISTER,  UMODBUS_U16_NPTROF(stampi::piece_count, 1))
            , MODBUS_REGISTER(11,  UMODBUS_TYPE_HOLDING_REGISTER,  UMODBUS_U16_NPTROF(stampi::piece_count, 0))
        };
        umodbus::uModbusTcp modbus(COMM_MODBUS_UNIT_ID, registers, COMM_MODBUS_REGISTER_COUNT);
        EthernetServer modbusServer(COMM_MODBUS_PORT);

        void comm_serial_setup();
        void comm_ethernet_setup();
        void comm_ethernet_loop();
        void ethernet_print_mac();
        void ethernet_dhcp_request(const uint16_t & attemps);

        void comm_setup() {
            comm_serial_setup();
            comm_ethernet_setup();
        }

        void comm_loop() {
            comm_ethernet_loop();
        }

        void comm_serial_setup() {
            Serial.begin(115200);
            serial_println("> Serial set up");
        }

        void comm_ethernet_setup() {
            ethernet_print_mac();
            ethernet_dhcp_request(5);
            Ethernet.localIP().printTo(Serial);
        }

        void comm_ethernet_loop() {
            EthernetClient client = modbusServer.available();
            bool client_connected = false;
            if(client) {
                client_connected = true;
                serial_println("> Connected. Once the connection is closed, loop will resume.");
                while (client.connected()) {
                    modbus.accept(&client);
                    modbus.poll();
                }
            } 
            delay(5);
            client.stop();
            if(client_connected) {
                serial_println("> Disconnected.");
            }
        }

        void ethernet_print_mac() {
            serial_print("> Mac address: ");
            for(size_t i = 0; i < 6; i++) {
                serial_print(stampi::mac_address[i], FORMAT_HEX);
                serial_print(":");
            }
            serial_println();
        }

        void ethernet_dhcp_request(const uint16_t & attemps) {
            for(uint16_t i = 0; i < attemps; i++) {
                if (Ethernet.begin(stampi::mac_address) == 0)
                {
                    serial_print("> DHCP Fail. Attempt ");
                    serial_print(++i);
                    serial_print(" of ");
                    serial_print(attemps);
                    serial_println();
                    hal_delay(2000);
                }
                else
                {
                    break;
                }
            }
        }
    }
}