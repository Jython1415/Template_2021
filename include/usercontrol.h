#ifndef _Usercontrol_H_
#define _Usercontrol_H_

#include "vex.h"
#include "controller.h"
#include "pragma.h"
#include "motor/class.h"
#include "motor/functions.h"
#include "custom_math.h"
#include "sejun_code.h"

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
// /*
#define user_arcade_1_fast_multiplier 1.0
#define user_arcade_1_slow_multiplier 0.4

extern int user_arcade_1_mode ; // 0 is slow, 1 is fast

void user_arcade_1 () ;
// */

// intake control 1 ===============================================================================
void user_intake_1 () ;

// intake control 2 ===============================================================================
#define user_intake_2_intake_fast_power   90
#define user_intake_2_intake_slow_power   40
#define user_intake_2_outtake_slow_power -40
#define user_intake_2_outtake_fast_power -90

void user_intake_2 () ;

// tray control 1 ===============================================================================
#define user_tray_1_up_power   100
#define user_tray_1_down_power -80

void user_tray_1 () ;

// tray control 2 - slows down near the top =====================================================
#define user_tray_2_up_power_super_fast   100
#define user_tray_2_up_power_fast          30
#define user_tray_2_up_power_slow          20
#define user_tray_2_down_power_fast       -90
#define user_tray_2_down_power_slow       -60
#define user_tray_2_down_power_super_slow -20

#define user_tray_2_up_pos_1   1300
#define user_tray_2_up_pos_2   2250
#define user_tray_2_up_pos_3   2850
#define user_tray_2_down_pos_1  300
#define user_tray_2_down_pos_2  100

void user_tray_2 () ;

// tray control 3 - slows down near the top =====================================================
#define user_tray_3_up_power_super_fast   100
#define user_tray_3_up_power_fast          50
#define user_tray_3_up_power_slow          30
#define user_tray_3_down_power_fast       -90
#define user_tray_3_down_power_slow       -60
#define user_tray_3_down_power_super_slow -20
 
#define user_tray_3_up_pos_1   1500
#define user_tray_3_up_pos_2   1800
#define user_tray_3_up_pos_3   2750
#define user_tray_3_down_pos_1  300
#define user_tray_3_down_pos_2  100
 
extern bool user_tray_3_setup_done ;
extern int user_tray_3_setup_count ;
 
void user_tray_3 () ;

// arm control 1 =================================================================================
void user_arm_1 () ;

// arm and tray control 1 - simple combined control ===============================================
#define user_arm_tray_1_tray_moe 50 // 
#define user_arm_tray_1_arm_moe  25 // 

#define user_arm_tray_1_tray_0    -50 // automatic movment position - down
#define user_arm_tray_1_tray_1    100 // slow down tray
#define user_arm_tray_1_tray_2    300 // tray is down
#define user_arm_tray_1_tray_3   1000 // automatic movement position
#define user_arm_tray_1_tray_4   1300 // start slowing down position
#define user_arm_tray_1_tray_5   2250 // even slower
#define user_arm_tray_1_tray_6   2950 // very top position
#define user_arm_tray_1_tray_7   3000 // physical limit

#define user_arm_tray_1_arm_1    0 // position for intaking
#define user_arm_tray_1_arm_2 1200 // tray safe value
// #define user_arm_tray_1_arm_3  700 // low towers
// #define user_arm_tray_1_arm_4 1400 // high towers
#define user_arm_tray_1_arm_5 2100 // upper limit for the arm

#define user_arm_tray_1_tray_up           ctlr_buttonRIGHT
#define user_arm_tray_1_tray_down         ctlr_buttonDOWN
#define user_arm_tray_1_arm_up            ctlr_buttonY
#define user_arm_tray_1_arm_down          ctlr_buttonB
#define user_arm_tray_1_arm_down_duration ctlr_buttonB_duration

#define user_arm_tray_1_tray_up_pwr_1      100 // default power
#define user_arm_tray_1_tray_up_pwr_2       30 // slow power 1
#define user_arm_tray_1_tray_up_pwr_3       20 // slowest power
#define user_arm_tray_1_tray_auto_up_pwr    70 // for automatically raising the tray
#define user_arm_tray_1_tray_auto_down_pwr -50 // for automatically lowering the tray
#define user_arm_tray_1_tray_down_pwr_1    -90 // default power
#define user_arm_tray_1_tray_down_pwr_2    -20 // slow power
#define user_arm_tray_1_arm_up_pwr         100 // default power
#define user_arm_tray_1_arm_down_pwr       -90 // default power

extern int user_arm_tray_1_tray_automatic           ; // 0 when button input works, 1 when target is down, 2 when target is up
extern int user_arm_tray_1_arm_automatic            ; // 0 when button input works, 1 when target is down

void user_arm_tray_1 ();

// TIA control 1 - tray, intake, and arm combined control =========================================
// controller mapping ===========================
#define user_TIA_tray_up            ctlr_buttonRIGHT
#define user_TIA_tray_up_pressed    ctlr_buttonRIGHT_pressed
#define user_TIA_tray_down          ctlr_buttonDOWN
#define user_TIA_tray_down_duration ctlr_buttonDOWN_duration
#define user_TIA_arm_up             ctlr_buttonY
#define user_TIA_arm_down           ctlr_buttonB
#define user_TIA_arm_down_duration  ctlr_buttonB_duration
#define user_TIA_intake_in_fast     ctlr_buttonR1
#define user_TIA_intake_in_slow     ctlr_buttonL2
#define user_TIA_intake_out         ctlr_buttonR2

// tray positions ===============================
#define user_TIA_tray_pos_1   50 // (u & a) down position
#define user_TIA_tray_pos_2  300 // (user)  slow down: for going down
#define user_TIA_tray_pos_3  300 // (auto)  slow down: for going down
#define user_TIA_tray_pos_4 1000 // (auto)  arm safety position: where the arm can start moving
#define user_TIA_tray_pos_5 1500 // (auto)  arm safety position: where the arm has full range of movement
#define user_TIA_tray_pos_6 1750 // (user)  tray slow position: where the tray starts slowing down
#define user_TIA_tray_pos_7 2750 // (user)  tray up position: where the tray is the slowest
#define user_TIA_tray_pos_8 2850 // (user)  tray up limit: the tray shouldn't go farther than this
#define user_TIA_tray_pos_9 0000 // (user)  tray physical limit: the physical limit for movement of the tray

// tray motor powers ============================
#define user_TIA_tray_pwr_1 100 // (user) fast up power
#define user_TIA_tray_pwr_2  20 // (user) slow up power
#define user_TIA_tray_pwr_3 -90 // (user) fast down power
#define user_TIA_tray_pwr_4 -40 // (user) slow down power
#define user_TIA_tray_pwr_5  95 // (auto) auto fast
#define user_TIA_tray_pwr_6  40 // (auto) auto slow

// arm positions ================================
#define user_TIA_arm_pos_1   50 // (u & a) down position
#define user_TIA_arm_pos_2  200 // (u & a) slow down: for going down
#define user_TIA_arm_pos_3  300 // (auto)  tray safety position: where the tray has full range of movement
#define user_TIA_arm_pos_4  750 // (auto)  tray safety position: where the tray can start to go down
#define user_TIA_arm_pos_5 1300 // (user)  lower tower
#define user_TIA_arm_pos_6 1700 // (user)  middle tower
#define user_TIA_arm_pos_7 2000 // (user)  upper limit

// arm motor powers =============================
#define user_TIA_arm_pwr_1 100 // (user) fast up power
#define user_TIA_arm_pwr_2 -90 // (user) fast down power
#define user_TIA_arm_pwr_3 -40 // (user) slow down power
#define user_TIA_arm_pwr_4  95 // (auto) auto fast
#define user_TIA_arm_pwr_5  40 // (auto) auto slow

// intake motor powers ==========================
#define user_TIA_intake_pwr_1 100 // (user) fast intake
#define user_TIA_intake_pwr_2  50 // (user) slow intake
#define user_TIA_intake_pwr_3 -90 // (user) outtake
#define user_TIA_intake_pwr_4 -30 // (auto) stacking outtake power

// margin of error values =======================
#define user_TIA_tray_moe 50 // default margin of error for tray position constants
#define user_TIA_arm_moe  25 // default margin of error for arm position constants

// other ========================================
#define user_TIA_arm_down_duration_constant  500 // how long the arm down button has to be pressed down for the automatic control to be engaged
#define user_TIA_tray_down_duration_constant 500 // how long the tray down button has to be pressed down for the automatic control to be engaged
#define user_TIA_auto_outtake_duration       500 // how long the intake outtakes when stacking

// variables ====================================
extern int user_TIA_tray_automatic         ; // 0 when button input works, 1 when target is down, 2 when target is up
extern int user_TIA_arm_automatic          ; // 0 when button input works, 1 when target is down
extern int user_TIA_intake_automatic       ; // 0 when button input works, 1 when outtaking automatically, -1 for flip out
extern int user_TIA_intake_automatic_timer ; // to track how long the intake should outtake while stacking

void user_TIA_1();

#endif