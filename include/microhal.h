#ifndef MICROHAL_H_
#define MICROHAL_H_

bool hal_digital_read(const int & pin);
void hal_digital_write(const int & pin, const bool & value);

#endif