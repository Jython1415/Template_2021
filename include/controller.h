#ifndef _Controller_H_
#define _Controller_H_

#include "vex.h"
#include "pragma.h"

// whether or not to print the following values in the debug menu
extern int ctlr_axis1_debug       ;
extern int ctlr_axis2_debug       ;
extern int ctlr_axis3_debug       ;
extern int ctlr_axis4_debug       ;
extern int ctlr_buttonR1_debug    ;
extern int ctlr_buttonR2_debug    ;
extern int ctlr_buttonL1_debug    ;
extern int ctlr_buttonL2_debug    ;
extern int ctlr_buttonA_debug     ;
extern int ctlr_buttonB_debug     ;
extern int ctlr_buttonX_debug     ;
extern int ctlr_buttonY_debug     ;
extern int ctlr_buttonUP_debug    ;
extern int ctlr_buttonDOWN_debug  ;
extern int ctlr_buttonLEFT_debug  ;
extern int ctlr_buttonRIGHT_debug ;

// stores current axis values
extern int ctlr_axis1       ;
extern int ctlr_axis2       ;
extern int ctlr_axis3       ;
extern int ctlr_axis4       ;
// stores current button values
extern int ctlr_buttonR1    ;
extern int ctlr_buttonR2    ;
extern int ctlr_buttonL1    ;
extern int ctlr_buttonL2    ;
extern int ctlr_buttonA     ;
extern int ctlr_buttonB     ;
extern int ctlr_buttonX     ;
extern int ctlr_buttonY     ;
extern int ctlr_buttonUP    ;
extern int ctlr_buttonDOWN  ;
extern int ctlr_buttonLEFT  ;
extern int ctlr_buttonRIGHT ;

// stores previous axis values
extern int ctlr_axis1_prev       ;
extern int ctlr_axis2_prev       ;
extern int ctlr_axis3_prev       ;
extern int ctlr_axis4_prev       ;
// stores previous button values
extern int ctlr_buttonR1_prev    ;
extern int ctlr_buttonR2_prev    ;
extern int ctlr_buttonL1_prev    ;
extern int ctlr_buttonL2_prev    ;
extern int ctlr_buttonA_prev     ;
extern int ctlr_buttonB_prev     ;
extern int ctlr_buttonX_prev     ;
extern int ctlr_buttonY_prev     ;
extern int ctlr_buttonUP_prev    ;
extern int ctlr_buttonDOWN_prev  ;
extern int ctlr_buttonLEFT_prev  ;
extern int ctlr_buttonRIGHT_prev ;

// whether a button has been toggled from 0 to 1
extern int ctlr_buttonR1_pressed    ;
extern int ctlr_buttonR2_pressed    ;
extern int ctlr_buttonL1_pressed    ;
extern int ctlr_buttonL2_pressed    ;
extern int ctlr_buttonA_pressed     ;
extern int ctlr_buttonB_pressed     ;
extern int ctlr_buttonX_pressed     ;
extern int ctlr_buttonY_pressed     ;
extern int ctlr_buttonUP_pressed    ;
extern int ctlr_buttonDOWN_pressed  ;
extern int ctlr_buttonLEFT_pressed  ;
extern int ctlr_buttonRIGHT_pressed ;

// whether a button has been toggled from 1 to 0
extern int ctlr_buttonR1_released    ;
extern int ctlr_buttonR2_released    ;
extern int ctlr_buttonL1_released    ;
extern int ctlr_buttonL2_released    ;
extern int ctlr_buttonA_released     ;
extern int ctlr_buttonB_released     ;
extern int ctlr_buttonX_released     ;
extern int ctlr_buttonY_released     ;
extern int ctlr_buttonUP_released    ;
extern int ctlr_buttonDOWN_released  ;
extern int ctlr_buttonLEFT_released  ;
extern int ctlr_buttonRIGHT_released ;

// how long a button has been held down
extern int ctlr_buttonR1_duration    ;
extern int ctlr_buttonR2_duration    ;
extern int ctlr_buttonL1_duration    ;
extern int ctlr_buttonL2_duration    ;
extern int ctlr_buttonA_duration     ;
extern int ctlr_buttonB_duration     ;
extern int ctlr_buttonX_duration     ;
extern int ctlr_buttonY_duration     ;
extern int ctlr_buttonUP_duration    ;
extern int ctlr_buttonDOWN_duration  ;
extern int ctlr_buttonLEFT_duration  ;
extern int ctlr_buttonRIGHT_duration ;

// update function to run each cycle of the usercontrol while loop
void ctlr_updateVars();

// loop
void ctlr_axis1_debug_print_loop();
void ctlr_axis2_debug_print_loop();
void ctlr_axis3_debug_print_loop();
void ctlr_axis4_debug_print_loop();
void ctlr_buttonR1_debug_print_loop();
void ctlr_buttonR2_debug_print_loop();
void ctlr_buttonL1_debug_print_loop();
void ctlr_buttonL2_debug_print_loop();
void ctlr_buttonA_debug_print_loop();
void ctlr_buttonB_debug_print_loop();
void ctlr_buttonX_debug_print_loop();
void ctlr_buttonY_debug_print_loop();
void ctlr_buttonUP_debug_print_loop();
void ctlr_buttonDOWN_debug_print_loop();
void ctlr_buttonLEFT_debug_print_loop();
void ctlr_buttonRIGHT_debug_print_loop();

// initial
void ctlr_axis1_debug_print_initial();
void ctlr_axis2_debug_print_initial();
void ctlr_axis3_debug_print_initial();
void ctlr_axis4_debug_print_initial();
void ctlr_buttonR1_debug_print_initial();
void ctlr_buttonR2_debug_print_initial();
void ctlr_buttonL1_debug_print_initial();
void ctlr_buttonL2_debug_print_initial();
void ctlr_buttonA_debug_print_initial();
void ctlr_buttonB_debug_print_initial();
void ctlr_buttonX_debug_print_initial();
void ctlr_buttonY_debug_print_initial();
void ctlr_buttonUP_debug_print_initial();
void ctlr_buttonDOWN_debug_print_initial();
void ctlr_buttonLEFT_debug_print_initial();
void ctlr_buttonRIGHT_debug_print_initial();

// combined debug functions
void ctlr_debug_print_loop();
void ctlr_debug_print_initial();

#endif