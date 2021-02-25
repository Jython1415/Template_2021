#include "usercontrol.h"
#include "sejun_code.h"

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