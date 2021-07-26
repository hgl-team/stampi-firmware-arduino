#ifndef MICROHAL_H_
#define MICROHAL_H_

#define FORMAT_BIN              2
#define FORMAT_DEC              10
#define FORMAT_HEX              16

bool hal_digital_read(const int & pin);
void hal_digital_write(const int & pin, const bool & value);
void hal_delay(const unsigned long & ms);

void serial_print(const char * value);
void serial_print(const double & value);
void serial_print(const int & value);
void serial_print(const long & value);
void serial_print(const unsigned int & value);
void serial_print(const unsigned long & value);
void serial_print(const char & value);
void serial_println();
void serial_println(const char * value);

// formatting

void serial_print(const int & value, const int & format);
void serial_print(const long & value, const int & format);
void serial_print(const unsigned int & value, const int & format);
void serial_print(const unsigned long & value, const int & format);

#endif