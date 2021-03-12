#include "vex.h"
#include "pragma.h"

// DEBUG OPTIONS
// whether or not to print the following values in the debug menu
int ctlr_axis1_debug       = 0 ;
int ctlr_axis2_debug       = 0 ;
int ctlr_axis3_debug       = 0 ;
int ctlr_axis4_debug       = 0 ;
int ctlr_buttonR1_debug    = 0 ;
int ctlr_buttonR2_debug    = 0 ;
int ctlr_buttonL1_debug    = 0 ;
int ctlr_buttonL2_debug    = 0 ;
int ctlr_buttonA_debug     = 0 ;
int ctlr_buttonB_debug     = 0 ;
int ctlr_buttonX_debug     = 0 ;
int ctlr_buttonY_debug     = 0 ;
int ctlr_buttonUP_debug    = 0 ;
int ctlr_buttonDOWN_debug  = 0 ;
int ctlr_buttonLEFT_debug  = 0 ;
int ctlr_buttonRIGHT_debug = 0 ;

// has current axis value, -100~100
int ctlr_axis1       = 0 ;
int ctlr_axis2       = 0 ;
int ctlr_axis3       = 0 ;
int ctlr_axis4       = 0 ;
// has current button position, 0 or 1
int ctlr_buttonR1    = 0 ;
int ctlr_buttonR2    = 0 ;
int ctlr_buttonL1    = 0 ;
int ctlr_buttonL2    = 0 ;
int ctlr_buttonA     = 0 ;
int ctlr_buttonB     = 0 ;
int ctlr_buttonX     = 0 ;
int ctlr_buttonY     = 0 ;
int ctlr_buttonUP    = 0 ;
int ctlr_buttonDOWN  = 0 ;
int ctlr_buttonLEFT  = 0 ;
int ctlr_buttonRIGHT = 0 ;

// stores previous axis values
int ctlr_axis1_prev       = 0 ;
int ctlr_axis2_prev       = 0 ;
int ctlr_axis3_prev       = 0 ;
int ctlr_axis4_prev       = 0 ;
// stores previous button values
int ctlr_buttonR1_prev    = 0 ;
int ctlr_buttonR2_prev    = 0 ;
int ctlr_buttonL1_prev    = 0 ;
int ctlr_buttonL2_prev    = 0 ;
int ctlr_buttonA_prev     = 0 ;
int ctlr_buttonB_prev     = 0 ;
int ctlr_buttonX_prev     = 0 ;
int ctlr_buttonY_prev     = 0 ;
int ctlr_buttonUP_prev    = 0 ;
int ctlr_buttonDOWN_prev  = 0 ;
int ctlr_buttonLEFT_prev  = 0 ;
int ctlr_buttonRIGHT_prev = 0 ;

// 0 or 1, whether the button has been toggled from off to on in the last iteration
int ctlr_buttonR1_pressed    = 0 ;
int ctlr_buttonR2_pressed    = 0 ;
int ctlr_buttonL1_pressed    = 0 ;
int ctlr_buttonL2_pressed    = 0 ;
int ctlr_buttonA_pressed     = 0 ;
int ctlr_buttonB_pressed     = 0 ;
int ctlr_buttonX_pressed     = 0 ;
int ctlr_buttonY_pressed     = 0 ;
int ctlr_buttonUP_pressed    = 0 ;
int ctlr_buttonDOWN_pressed  = 0 ;
int ctlr_buttonLEFT_pressed  = 0 ;
int ctlr_buttonRIGHT_pressed = 0 ;

// 0 or 1, whether the button has been toggled from on to off in the last iteration
int ctlr_buttonR1_released    = 0 ;
int ctlr_buttonR2_released    = 0 ;
int ctlr_buttonL1_released    = 0 ;
int ctlr_buttonL2_released    = 0 ;
int ctlr_buttonA_released     = 0 ;
int ctlr_buttonB_released     = 0 ;
int ctlr_buttonX_released     = 0 ;
int ctlr_buttonY_released     = 0 ;
int ctlr_buttonUP_released    = 0 ;
int ctlr_buttonDOWN_released  = 0 ;
int ctlr_buttonLEFT_released  = 0 ;
int ctlr_buttonRIGHT_released = 0 ;

// how long the button has been pressed down in milliseconds
int ctlr_buttonR1_duration    = 0 ;
int ctlr_buttonR2_duration    = 0 ;
int ctlr_buttonL1_duration    = 0 ;
int ctlr_buttonL2_duration    = 0 ;
int ctlr_buttonA_duration     = 0 ;
int ctlr_buttonB_duration     = 0 ;
int ctlr_buttonX_duration     = 0 ;
int ctlr_buttonY_duration     = 0 ;
int ctlr_buttonUP_duration    = 0 ;
int ctlr_buttonDOWN_duration  = 0 ;
int ctlr_buttonLEFT_duration  = 0 ;
int ctlr_buttonRIGHT_duration = 0 ;

// update function to run each cycle of the usercontrol while loop
void ctlr_updateVars()
{
  // stores the previous iteration's axis and button values
  ctlr_axis1_prev       = ctlr_axis1       ;
  ctlr_axis2_prev       = ctlr_axis2       ;
  ctlr_axis3_prev       = ctlr_axis3       ;
  ctlr_axis4_prev       = ctlr_axis4       ;
  ctlr_buttonR1_prev    = ctlr_buttonR1    ;
  ctlr_buttonR2_prev    = ctlr_buttonR2    ;
  ctlr_buttonL1_prev    = ctlr_buttonL1    ;
  ctlr_buttonL2_prev    = ctlr_buttonL2    ;
  ctlr_buttonA_prev     = ctlr_buttonA     ;
  ctlr_buttonB_prev     = ctlr_buttonB     ;
  ctlr_buttonX_prev     = ctlr_buttonX     ;
  ctlr_buttonY_prev     = ctlr_buttonY     ;
  ctlr_buttonUP_prev    = ctlr_buttonUP    ;
  ctlr_buttonDOWN_prev  = ctlr_buttonDOWN  ;
  ctlr_buttonLEFT_prev  = ctlr_buttonLEFT  ;
  ctlr_buttonRIGHT_prev = ctlr_buttonRIGHT ;

  // get new values to store in variables
  ctlr_axis1       = Controller_1.Axis1.value()          ;
  ctlr_axis2       = Controller_1.Axis2.value()          ;
  ctlr_axis3       = Controller_1.Axis3.value()          ;
  ctlr_axis4       = Controller_1.Axis4.value()          ;
  ctlr_buttonR1    = Controller_1.ButtonR1.pressing()    ;
  ctlr_buttonR2    = Controller_1.ButtonR2.pressing()    ;
  ctlr_buttonL1    = Controller_1.ButtonL1.pressing()    ;
  ctlr_buttonL2    = Controller_1.ButtonL2.pressing()    ;
  ctlr_buttonA     = Controller_1.ButtonA.pressing()     ;
  ctlr_buttonB     = Controller_1.ButtonB.pressing()     ;
  ctlr_buttonX     = Controller_1.ButtonX.pressing()     ;
  ctlr_buttonY     = Controller_1.ButtonY.pressing()     ;
  ctlr_buttonUP    = Controller_1.ButtonUp.pressing()    ;
  ctlr_buttonDOWN  = Controller_1.ButtonDown.pressing()  ;
  ctlr_buttonLEFT  = Controller_1.ButtonLeft.pressing()  ;
  ctlr_buttonRIGHT = Controller_1.ButtonRight.pressing() ;

  // compute whether a button has been toggled from 0 to 1
  ctlr_buttonR1_pressed    = (ctlr_buttonR1_prev    == 0 && ctlr_buttonR1    == 1) ? 1 : 0;
  ctlr_buttonR2_pressed    = (ctlr_buttonR2_prev    == 0 && ctlr_buttonR2    == 1) ? 1 : 0;
  ctlr_buttonL1_pressed    = (ctlr_buttonL1_prev    == 0 && ctlr_buttonL1    == 1) ? 1 : 0;
  ctlr_buttonL2_pressed    = (ctlr_buttonL2_prev    == 0 && ctlr_buttonL2    == 1) ? 1 : 0;
  ctlr_buttonA_pressed     = (ctlr_buttonA_prev     == 0 && ctlr_buttonA     == 1) ? 1 : 0;
  ctlr_buttonB_pressed     = (ctlr_buttonB_prev     == 0 && ctlr_buttonB     == 1) ? 1 : 0;
  ctlr_buttonX_pressed     = (ctlr_buttonX_prev     == 0 && ctlr_buttonX     == 1) ? 1 : 0;
  ctlr_buttonY_pressed     = (ctlr_buttonY_prev     == 0 && ctlr_buttonY     == 1) ? 1 : 0;
  ctlr_buttonUP_pressed    = (ctlr_buttonUP_prev    == 0 && ctlr_buttonUP    == 1) ? 1 : 0;
  ctlr_buttonDOWN_pressed  = (ctlr_buttonDOWN_prev  == 0 && ctlr_buttonDOWN  == 1) ? 1 : 0;
  ctlr_buttonLEFT_pressed  = (ctlr_buttonLEFT_prev  == 0 && ctlr_buttonLEFT  == 1) ? 1 : 0;
  ctlr_buttonRIGHT_pressed = (ctlr_buttonRIGHT_prev == 0 && ctlr_buttonRIGHT == 1) ? 1 : 0;

  // compute whether a button has been toggled from 1 to 0
  ctlr_buttonR1_released    = (ctlr_buttonR1_prev    == 1 && ctlr_buttonR1    == 0) ? 1 : 0;
  ctlr_buttonR2_released    = (ctlr_buttonR2_prev    == 1 && ctlr_buttonR2    == 0) ? 1 : 0;
  ctlr_buttonL1_released    = (ctlr_buttonL1_prev    == 1 && ctlr_buttonL1    == 0) ? 1 : 0;
  ctlr_buttonL2_released    = (ctlr_buttonL2_prev    == 1 && ctlr_buttonL2    == 0) ? 1 : 0;
  ctlr_buttonA_released     = (ctlr_buttonA_prev     == 1 && ctlr_buttonA     == 0) ? 1 : 0;
  ctlr_buttonB_released     = (ctlr_buttonB_prev     == 1 && ctlr_buttonB     == 0) ? 1 : 0;
  ctlr_buttonX_released     = (ctlr_buttonX_prev     == 1 && ctlr_buttonX     == 0) ? 1 : 0;
  ctlr_buttonY_released     = (ctlr_buttonY_prev     == 1 && ctlr_buttonY     == 0) ? 1 : 0;
  ctlr_buttonUP_released    = (ctlr_buttonUP_prev    == 1 && ctlr_buttonUP    == 0) ? 1 : 0;
  ctlr_buttonDOWN_released  = (ctlr_buttonDOWN_prev  == 1 && ctlr_buttonDOWN  == 0) ? 1 : 0;
  ctlr_buttonLEFT_released  = (ctlr_buttonLEFT_prev  == 1 && ctlr_buttonLEFT  == 0) ? 1 : 0;
  ctlr_buttonRIGHT_released = (ctlr_buttonRIGHT_prev == 1 && ctlr_buttonRIGHT == 0) ? 1 : 0;

  // update button duration variables
  ctlr_buttonR1_duration    = (ctlr_buttonR1   ) ? ctlr_buttonR1_duration    + 20 : 0;
  ctlr_buttonR2_duration    = (ctlr_buttonR2   ) ? ctlr_buttonR2_duration    + 20 : 0;
  ctlr_buttonL1_duration    = (ctlr_buttonL1   ) ? ctlr_buttonL1_duration    + 20 : 0;
  ctlr_buttonL2_duration    = (ctlr_buttonL2   ) ? ctlr_buttonL2_duration    + 20 : 0;
  ctlr_buttonA_duration     = (ctlr_buttonA    ) ? ctlr_buttonA_duration     + 20 : 0;
  ctlr_buttonB_duration     = (ctlr_buttonB    ) ? ctlr_buttonB_duration     + 20 : 0;
  ctlr_buttonX_duration     = (ctlr_buttonX    ) ? ctlr_buttonX_duration     + 20 : 0;
  ctlr_buttonY_duration     = (ctlr_buttonY    ) ? ctlr_buttonY_duration     + 20 : 0;
  ctlr_buttonUP_duration    = (ctlr_buttonUP   ) ? ctlr_buttonUP_duration    + 20 : 0;
  ctlr_buttonDOWN_duration  = (ctlr_buttonDOWN ) ? ctlr_buttonDOWN_duration  + 20 : 0;
  ctlr_buttonLEFT_duration  = (ctlr_buttonLEFT ) ? ctlr_buttonLEFT_duration  + 20 : 0;
  ctlr_buttonRIGHT_duration = (ctlr_buttonRIGHT) ? ctlr_buttonRIGHT_duration + 20 : 0;
}

// DEBUG CODE
// shortcuts for easy adjustment of the code
// CPL stands for CONTROLLER_PRINT_LOOP
#define CPL_1 Brain.Screen.print(
#define CPL_2 ); std::cout <<
#define CPL_3 << "," << std::flush; Brain.Screen.newLine();
// the above code helps produce the following:
// void ctlr_axis1_debug_print_loop()
// {
//   Brain.Screen.print("axis 1: %d", ctlr_axis1);
//   std::cout << ctlr_axis1 << "," << std::flush;
//   Brain.Screen.newLine();
// }

void ctlr_axis1_debug_print_loop()
{
  CPL_1 "axis 1: %d", ctlr_axis3 CPL_2 ctlr_axis3 CPL_3
}
void ctlr_axis2_debug_print_loop()
{
  CPL_1 "axis 2: %d", ctlr_axis3 CPL_2 ctlr_axis3 CPL_3
}
void ctlr_axis3_debug_print_loop()
{
  CPL_1 "axis 3: %d", ctlr_axis3 CPL_2 ctlr_axis3 CPL_3
}
void ctlr_axis4_debug_print_loop()
{
  CPL_1 "axis 4: %d", ctlr_axis4 CPL_2 ctlr_axis3 CPL_3
}
void ctlr_buttonR1_debug_print_loop()
{
  CPL_1 "button R1: %d", ctlr_buttonR1 CPL_2 ctlr_buttonR1 CPL_3
}
void ctlr_buttonR2_debug_print_loop()
{
  CPL_1 "button R2: %d", ctlr_buttonR2 CPL_2 ctlr_buttonR2 CPL_3
}
void ctlr_buttonL1_debug_print_loop()
{
  CPL_1 "button L1: %d", ctlr_buttonL1 CPL_2 ctlr_buttonL1 CPL_3
}
void ctlr_buttonL2_debug_print_loop()
{
  CPL_1 "button L2: %d", ctlr_buttonL2 CPL_2 ctlr_buttonL2 CPL_3
}
void ctlr_buttonA_debug_print_loop()
{
  CPL_1 "button A: %d", ctlr_buttonA CPL_2 ctlr_buttonA CPL_3
}
void ctlr_buttonB_debug_print_loop()
{
  CPL_1 "button B: %d", ctlr_buttonB CPL_2 ctlr_buttonB CPL_3
}
void ctlr_buttonX_debug_print_loop()
{
  CPL_1 "button X: %d", ctlr_buttonX CPL_2 ctlr_buttonX CPL_3
}
void ctlr_buttonY_debug_print_loop()
{
  CPL_1 "button Y: %d", ctlr_buttonY CPL_2 ctlr_buttonY CPL_3
}
void ctlr_buttonUP_debug_print_loop()
{
  CPL_1 "button UP: %d", ctlr_buttonUP CPL_2 ctlr_buttonUP CPL_3
}
void ctlr_buttonDOWN_debug_print_loop()
{
  CPL_1 "button DOWN: %d", ctlr_buttonDOWN CPL_2 ctlr_buttonDOWN CPL_3
}
void ctlr_buttonLEFT_debug_print_loop()
{
  CPL_1 "button LEFT: %d", ctlr_buttonLEFT CPL_2 ctlr_buttonLEFT CPL_3
}
void ctlr_buttonRIGHT_debug_print_loop()
{
  CPL_1 "button RIGHT: %d", ctlr_buttonY CPL_2 ctlr_buttonY CPL_3
}