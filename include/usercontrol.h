#ifndef _Usercontrol_H_
#define _Usercontrol_H_

#include "vex.h"
#include "controller.h"
#include "pragma.h"
#include "motor/class.h"
#include "motor/functions.h"
#include "custom_math.h"

// constants
#define TANK_DRIVE_JOYSTICK_THRESHOLD    5
#define ARCADE_DRIVE_JOYSTICK_THRESHOLD 10

// simple tank ctrl w/ threshold ==================================================================
void user_tank_1 () ;

// tanks ctrl w/ threshold and fast/slow ==========================================================
#define user_tank_2_fast_multiplier 1.0
#define user_tank_2_slow_multiplier 0.6
#define user_tank_2_turn_multiplier 1.0

extern int user_tank_2_mode                ; // 0 is slow, 1 is fast
extern double user_tank_2_speed_multiplier ;

void user_tank_2 () ;

// arcade ctrl w/ threshold and fast/slow =========================================================

#define user_arcade_1_fast_multiplier 1.0
#define user_arcade_1_slow_multiplier 0.4

extern int user_arcade_1_mode ; // 0 is slow, 1 is fast

void user_arcade_1 () ;

#endif