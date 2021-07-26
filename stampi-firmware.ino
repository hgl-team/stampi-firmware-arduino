#include <umodbus_tcp.h>
#include <umodbus.h>

#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetServer.h>

#include <Action.h>
#include <Application.h>
#include <Clock.h>
#include <ClockListener.h>
#include <EventListener.h>
#include <NonStoredAction.h>
#include <sfctypes.h>
#include <StatefulObject.h>
#include <Step.h>
#include <StepContext.h>
#include <StoredAction.h>
#include <Timer.h>
#include <Transition.h>

#include "include/microhal.h"
#include "include/globaldef.h"
#include "include/comm.h"

void setup() {
    stampi::application_setup();
}

void loop() {
    stampi::application_loop(millis());
}
