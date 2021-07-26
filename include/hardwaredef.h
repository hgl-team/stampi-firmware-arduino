#include "mduino58io.h"

#ifndef HARDWAREDEF_H_
#define HARDWAREDEF_H_

// INPUTS ===============================

#define IN_AUTO                 I0_00
#define IN_SAUTO                I0_01
#define IN_MANUAL               I0_02
#define IN_BTN_SA               I0_03
#define IN_BTN_CL               I0_04
#define IN_DOOR                 I0_07
#define IN_ES1                  I0_08
#define IN_ES2                  I0_09
#define IN_ES3                  I0_10
#define IN_ES4                  I0_11
#define IN_ES5                  I0_12

#define IN_BTN_CR               I1_00
#define IN_START                I1_02
#define IN_BTN_MC               I1_03
#define IN_BTN_MO               I1_04
#define IN_ES8                  I1_09
#define IN_ES9                  I1_10
#define IN_MSC                  I1_12
#define IN_MSO                  I1_11

#define IN_BTN_INJECT           I2_00
#define IN_BTN_LOAD             I2_01
#define IN_BTN_SR               I2_02

// OUTPUTS ==============================

#define OUT_INJECT_PRESS        Q1_1
#define OUT_MOLD_CLOSE          Q1_2
#define OUT_INJECT_LOW_PRESS    Q1_3
#define OUT_MOLD_LOW_PRESS      Q1_4
#define OUT_MOLD_SOFT_MOVE      Q1_5
#define OUT_HEALTH              Q1_7

#define OUT_PUMP                Q0_0
#define OUT_MOLD_OPEN           Q0_1
#define OUT_INJECT              Q0_2
#define OUT_SCREW_RET           Q0_3
#define OUT_LOAD                Q0_4
#define OUT_CARRIER_MOVE_L      Q0_5
#define OUT_CARRIER_MOVE_R      Q0_6

#endif