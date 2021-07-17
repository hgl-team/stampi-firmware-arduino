#include "include/microhal.h"
#include <Arduino.h>

bool hal_digital_read(const int & pin) {
    return digitalRead(pin) == HIGH;
}

void hal_digital_write(const int & pin, const bool & value) {
    digitalWrite(pin, value ? HIGH : LOW);
}