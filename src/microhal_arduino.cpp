#include "../include/microhal.h"

#include <Arduino.h>

bool hal_digital_read(const int & pin) {
    return digitalRead(pin) == HIGH;
}
void hal_digital_write(const int & pin, const bool & value) {
    digitalWrite(pin, value ? HIGH : LOW);
}
void hal_delay(const unsigned long & ms) {
    delay(ms);
}

void serial_print(const char * value) { Serial.print(value); }
void serial_print(const double & value) { Serial.print(value); }
void serial_print(const int & value) { Serial.print(value); }
void serial_print(const long & value) { Serial.print(value); }
void serial_print(const unsigned int & value) { Serial.print(value); }
void serial_print(const unsigned long & value) { Serial.print(value); }
void serial_print(const char & value) { Serial.print(value); }
void serial_println() { Serial.println(); }
void serial_println(const char * value) { Serial.println(value); }

// formatting

void serial_print(const int & value, const int & format) { Serial.print(value, format); }
void serial_print(const long & value, const int & format) { Serial.print(value, format); }
void serial_print(const unsigned int & value, const int & format) { Serial.print(value, format); }
void serial_print(const unsigned long & value, const int & format) { Serial.print(value, format); }
