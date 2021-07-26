#ifndef MDUINO58IO_H_
#define MDUINO58IO_H_

/* ############################################################
 *             INDUSTRIALSHIELD M-DUINO 58 IO
 * ############################################################
 */

// DIGITAL INPUT -------------------------------------------------
#define I0_00   22
#define I0_01   23
#define I0_02   24
#define I0_03   25
#define I0_04   26
#define I0_05   2
#define I0_06   3
#define I0_07   54
#define I0_08   55
#define I0_09   56
#define I0_10   57
#define I0_11   58
#define I0_12   59

#define I1_00   27
#define I1_01   28
#define I1_02   29
#define I1_03   30
#define I1_04   31
#define I1_05   18
#define I1_06   19
#define I1_07   60
#define I1_08   61
#define I1_09   62
#define I1_10   63
#define I1_11   64
#define I1_12   65

#define I2_00    32
#define I2_01    33
#define I2_02    34
#define I2_03    35
#define I2_04    NC
#define I2_05    20
#define I2_06    21
#define I2_07    66
#define I2_08    67
#define I2_09    68
#define I2_10    69
#define I2_11    NC
#define I2_12    NC

// ANALOG OUTPUT ------------------------------------------------

#define A0_5   4
#define A0_6   5
#define A0_7   6

#define A1_5   8
#define A1_6   9
#define A1_7   7

#define A2_5   12
#define A2_6   13
#define A2_7   NC

// RELAY OUTPUT -------------------------------------------------

#define Q0_0   36
#define Q0_1   37
#define Q0_2   38
#define Q0_3   39
#define Q0_4   40
#define Q0_5   4
#define Q0_6   5
#define Q0_7   6

#define Q1_0   41
#define Q1_1   42
#define Q1_2   43
#define Q1_3   44
#define Q1_4   45
#define Q1_5   8
#define Q1_6   9
#define Q1_7   7

#define Q2_0   46
#define Q2_1   47
#define Q2_2   48
#define Q2_3   49
#define Q2_4   NC
#define Q2_5   12
#define Q2_6   13
#define Q2_7   NC

// I2C ----------------------------------------------------------

#define SCL   21
#define SDA   20

// UART TTL -----------------------------------------------------

#define RX0   1
#define TX0   0
#define RX1   19
#define TX1   18

// UART RS232 ---------------------------------------------------
#define TX    17
#define RX    16

// UART RS485 ---------------------------------------------------
#define RS485_RE   15
#define RS485_DE   14
#define RS485_RO   11
#define RS485_DI   10

// PIN 3 --------------------------------------------------------
#define PIN3    3

// SPI ----------------------------------------------------------
#define SO      50
#define SI      51
#define SCK     52
#define ETH_CS  53

// PIN 2 --------------------------------------------------------
#define PIN2    2

#endif
