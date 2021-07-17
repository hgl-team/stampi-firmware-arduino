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

void setup() {

}

void loop() {
    
}

bool hal_digital_read(const int & pin) {
    return digitalRead(pin) == HIGH;
}

void hal_digital_write(const int & pin, const bool & value) {
    digitalWrite(pin, value ? HIGH : LOW);
}