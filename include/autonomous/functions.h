#ifndef _autonomous_functions_H_
#define _autonomous_functions_H_

#include "vex.h"
#include "pragma.h"
#include "motor/class.h"
#include "motor/functions.h"
#include "custom_math.h"
#include "debug.h"

// auton standard functions -----------------------------------------------------------------------
// auton standard initialize function
void auton_standard_initialize () ;
// auton standard update functions
void auton_standard_update_beg () ;
void auton_standard_update_fin () ;

// wait function ----------------------------------------------------------------------------------
extern int auton_wait_target  ;
extern int auton_wait_current ;

void auton_wait (int input) ;

int auton_wait_done () ;

// ease of use functions ==========================================================================
// ================================================================================================
// wait(time) 
void a_wait (int input_time);

// reset_and_wait(time) ::: yes reset
void a_reset_and_wait (int time_input);

// forward(distance, power) ::: no reset 
void a_forward (double target_input, int power_input);

// drive(power, time) ::: no reset
void a_drive (double power_input, int time_input);

// turn(target, power) ::: yes reset
void a_turn (double target_input, int power_input);

// tray_up()
void a_tray_up ();

// tray_mid()
void a_tray_mid ();

// tray_down()
void a_tray_down ();

// stack()
void a_stack ();

// outtake_small()
void a_outtake_small ();

// straight drive 1 ===============================================================================
#define auton_straight_1_side_moe     30
#define auton_straight_1_target_moe   50
#define auton_straight_1_turn_power    0
#define auton_straight_1_close_power  10
#define auton_straight_1_speed_moe   100

extern int auton_straight_1_done_var       ; // 0 is not done, 1 is done
extern int auton_straight_1_turn_direction ; // 1 is left, -1 is right
extern int auton_straight_1_base_power     ; // base power (user input)
 
extern double auton_straight_1_target            ; // target position
extern double auton_straight_1_pos_l             ; // the current position of the left side
extern double auton_straight_1_pos_r             ; // the current position of the right side
extern double auton_straight_1_error             ; // how far the robot is from its target position
extern double auton_straight_1_initial_side_diff ; // the initial difference between the right and left sides

void auton_straight_1_set (double target, int base_power) ;

void auton_straight_1_loop () ;

bool auton_straight_1_done () ;

// straight drive 2 ===============================================================================
#define auton_straight_2_side_moe     30
#define auton_straight_2_target_moe   50
#define auton_straight_2_turn_power    2
#define auton_straight_2_close_power  10
#define auton_straight_2_speed_moe   100

extern int auton_straight_2_done_var       ; // 0 is not done, 1 is done
extern int auton_straight_2_turn_direction ; // 1 is left, -1 is right
extern int auton_straight_2_base_power     ; // base power (user input)
 
extern double auton_straight_2_target            ; // target position
extern double auton_straight_2_pos_l             ; // the current position of the left side
extern double auton_straight_2_pos_r             ; // the current position of the right side
extern double auton_straight_2_error             ; // how far the robot is from its target position
extern double auton_straight_2_initial_side_diff ; // the initial difference between the right and left sides

void auton_straight_2_set (double target, int base_power) ;

void auton_straight_2_loop () ;

bool auton_straight_2_done () ;

// straight drive 3 ===============================================================================
#define auton_straight_3_side_moe     10
#define auton_straight_3_target_moe   25
#define auton_straight_3_turn_power    2
#define auton_straight_3_close_power  10
#define auton_straight_3_speed_moe   100

extern int auton_straight_3_done_var       ; // 0 is not done, 1 is done
extern int auton_straight_3_turn_direction ; // 1 is left, -1 is right
extern int auton_straight_3_base_power     ; // base power (user input)
 
extern double auton_straight_3_target            ; // target position
extern double auton_straight_3_pos_l             ; // the current position of the left side
extern double auton_straight_3_pos_r             ; // the current position of the right side
extern double auton_straight_3_error             ; // how far the robot is from its target position
extern double auton_straight_3_initial_side_diff ; // the initial difference between the right and left sides

void auton_straight_3_set (double target, int base_power) ;

void auton_straight_3_loop () ;

bool auton_straight_3_done () ;

// s drive 2 ===============================================================================
#define auton_chassis_s_2_p           0.1
#define auton_chassis_s_2_min_power    20
#define auton_chassis_s_2_max_power   100
#define auton_chassis_s_2_moe           5
#define auton_chassis_s_2_turn_power    0
#define auton_chassis_s_2_moe_speed  1000

extern int auton_chassis_s_2_done      ;
extern double auton_chassis_s_2_target ;
 
extern double auton_chassis_s_2_current     ;
extern double auton_chassis_s_2_error       ;
extern double auton_chassis_s_2_error_l     ;
extern double auton_chassis_s_2_error_r     ;
extern int auton_chassis_s_2_turn_direction ;
extern int auton_chassis_s_2_base_power     ;
 
void auton_chassis_s_2_set (double target) ;
void auton_chassis_s_2_loop () ;

// turning control 1 ------------------------------------------------------------------------------
#define auton_chassis_t_1_p          0.25
#define auton_chassis_t_1_min_power    20
#define auton_chassis_t_1_max_power   100
#define auton_chassis_t_1_moe           5
#define auton_chassis_t_1_moe_speed  1000
#define auton_chassis_t_1_raw_deg     1.0

extern int auton_chassis_t_1_done      ;
extern double auton_chassis_t_1_target ;

extern double auton_chassis_t_1_angle_raw   ;
extern double auton_chassis_t_1_angle       ;
extern double auton_chassis_t_1_error       ;
extern int auton_chassis_t_1_base_power     ;

void auton_chassis_t_1_set (double target) ;
void auton_chassis_t_1_loop () ;

// turn 1 ========================================================================================
#define auton_turn_1_min_power        10
#define auton_turn_1_moe              10
#define auton_turn_1_min_power_range 400

extern int auton_turn_1_done_var   ; // 0 is not done, 1 is done
extern int auton_turn_1_base_power ; // the base power for turning

extern double auton_turn_1_target ; // left is positive, right is negative
extern double auton_turn_1_pos    ; // current position (angle)
extern double auton_turn_1_error  ; // how far the robot is from the target position (angle)

void auton_turn_1_set (double target_input, double power_input) ;
void auton_turn_1_loop () ;
bool auton_turn_1_done () ;

// arm control 1 ---------------------------------------------------------------------------------
#define auton_arm_1_up_power        90
#define auton_arm_1_down_power     -50
#define auton_arm_1_holding_power   15
#define auton_arm_1_moe             25
#define auton_arm_1_up_pos_1      1750
#define auton_arm_1_up_pos_2      2250
#define auton_arm_1_down_pos       -10

extern int auton_arm_1_done  ;
extern int auton_arm_1_mode  ;
extern int auton_arm_1_error ;
extern int auton_arm_1_power ;

void auton_arm_1_set (int arm_state) ;
void auton_arm_1_loop () ;

// tray control 1 ===============================================================================
/*
#define auton_tray_1_down_position       -10
#define auton_tray_1_up_position        2400
#define auton_tray_1_default_power        60
#define auton_tray_1_close_power          20
#define auton_tray_1_holding_power_up     15
#define auton_tray_1_holding_power_down    5
#define auton_tray_1_moe                  10

extern int auton_tray_1_done  ;
extern int auton_tray_1_error ;

void auton_tray_1_up_set () ;
void auton_tray_1_up () ;
void auton_tray_1_down_set () ;
void auton_tray_1_down () ;
*/

// tray 2 =======================================================================================
#define auton_tray_2_up_pos_1   1300
#define auton_tray_2_up_pos_2   1550
#define auton_tray_2_up_pos_3   2550
#define auton_tray_2_mid_pos    2000
#define auton_tray_2_down_pos_1  500
#define auton_tray_2_down_pos_2  100

#define auton_tray_2_up_power_max     90
#define auton_tray_2_up_power         40
#define auton_tray_2_up_power_slow    25
#define auton_tray_2_down_power_fast -60 
#define auton_tray_2_down_power_slow -90
#define auton_tray_2_down_power_min  -25
#define auton_tray_2_mid_power        60

#define auton_tray_2_mid_moe 20

extern int auton_tray_2_done_var   ; // 0 is not done, 1 is done
extern int auton_tray_2_target_pos ; // 0 is down, 1 is almost up, 2 is stack

extern double auton_tray_2_pos   ;
extern double auton_tray_2_error ;

void auton_tray_2_set (int position_input);

void auton_tray_2_loop ();

bool auton_tray_2_done ();

// intake control 1 -------------------------------------------------------------------------------
#define auton_intake_1_in_power  100
#define auton_intake_1_out_power -90

void auton_intake_1_in () ;
void auton_intake_1_out () ;
void auton_intake_1_stop () ;

#endif