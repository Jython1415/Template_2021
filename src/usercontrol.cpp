#include "usercontrol.h"

// simple tank ctrl w/ threshold ==================================================================
void user_tank_1 ()
{
  // set left power (take into account the threshold)
  left_set(ctlr_axis3);
  if (abs(ctlr_axis3) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    left_set(0);
  }

  // set right power (same as left)
  right_set(ctlr_axis2);
  if (abs(ctlr_axis2) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    right_set(0);
  }
}

// tanks ctrl w/ threshold and fast/slow + slow turns  ============================================
int user_tank_2_mode = 1; // 0 is slow, 1 is fast
double user_tank_2_speed_multiplier; // used to keep track of how fast it should be going

void user_tank_2 ()
{
  // change drive mode based on button input
  if (ctlr_buttonL2)
  {
    user_tank_2_mode = 0;
  }
  else
  {
    user_tank_2_mode = 1;
  }

  // change drive multiplier
  if (user_tank_2_mode)
  {
    user_tank_2_speed_multiplier = user_tank_2_fast_multiplier;
  }
  else
  {
    user_tank_2_speed_multiplier = user_tank_2_slow_multiplier;
  }
  // slow down turns
  if (math_sgn_i(ctlr_axis2) != math_sgn_i(ctlr_axis3) && math_sgn_i(ctlr_axis2) + math_sgn_i(ctlr_axis3) == 0)
  {
    user_tank_2_speed_multiplier *= user_tank_2_turn_multiplier;
  }

  // set left power (and drive threshold)
  left_set(ctlr_axis3 * user_tank_2_speed_multiplier);
  if (abs(ctlr_axis3) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    left_set(0);
  }

  // set right power (and drive threshold)
  right_set(ctlr_axis2 * user_tank_2_speed_multiplier);
  if (abs(ctlr_axis2) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    right_set(0);
  }
}

// arcade ctrl w/ threshold and fast/slow =========================================================

int user_arcade_1_mode = 1;
int user_arcade_1_l       ;
int user_arcade_1_r       ;

void user_arcade_1 ()
{
  if (ctlr_buttonUP_pressed)
  {
    user_arcade_1_mode = 1;
  }
  if (ctlr_buttonLEFT_pressed)
  {
    user_arcade_1_mode = 0;
  }

  user_arcade_1_l = math_restrict_i(ctlr_axis2 + ctlr_axis4, -100, 100);
  if (user_arcade_1_mode)
  {
    user_arcade_1_l = user_arcade_1_l * user_arcade_1_fast_multiplier;
  }
  else
  {
    user_arcade_1_l = user_arcade_1_l * user_arcade_1_slow_multiplier;
  }
  if (abs(user_arcade_1_l) < ARCADE_DRIVE_JOYSTICK_THRESHOLD)
  {
    left_set(user_arcade_1_l);
  }

  user_arcade_1_r = math_restrict_i(ctlr_axis2 - ctlr_axis4, -100, 100);
  if (user_arcade_1_mode)
  {
    user_arcade_1_l = user_arcade_1_r * user_arcade_1_fast_multiplier;
  }
  else
  {
    user_arcade_1_r = user_arcade_1_r * user_arcade_1_slow_multiplier;
  }
  if (abs(user_arcade_1_r) < ARCADE_DRIVE_JOYSTICK_THRESHOLD)
  {
    right_set(user_arcade_1_r);
  }
}