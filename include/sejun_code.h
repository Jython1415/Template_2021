#ifndef _sejun_code_H_
#define _sejun_code_H_

#include "vex.h"
#include "pragma.h"

void Chassis_forward(int power);

void intake(int power);

void Chassis_right(int power);

void Chassis_left(int power);

void tilt(int power);

void rstop(void);

void lstop(void);

void istop(void);

void tray_r(int rotation, int power);

void sleep(int time);

void stop(void);

void auton_forward(int rotation);

void auton_right(int rotation);

void auton_left(int rotation);

#endif