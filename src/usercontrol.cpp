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
// /*
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
// */

// intake control 1 ===============================================================================
void user_intake_1 ()
{
  if (ctlr_buttonR1 && !ctlr_buttonR2)
  {
    intake_set(-100);
  }
  else if (ctlr_buttonR2 && !ctlr_buttonR1)
  {
    intake_set(100);
  }
  else
  {
    intake_set(0);
  }
}

// intake control 2 ===============================================================================
// press R1 for fast intake
// press R2 for slow intake
// hold L1 for  outtaking

void user_intake_2 ()
{
  if (ctlr_buttonR1) // fast intaking
  {
    intake_set(user_intake_2_intake_fast_power);
  }
  else if (ctlr_buttonL1) // slow intake
  {
    intake_set(user_intake_2_intake_slow_power);
  }
  else if (ctlr_buttonR2) // outtaking
  {
    intake_set(user_intake_2_outtake_fast_power);
  }
  else
  {
    intake_set(0);
    // if (tray.rotation_get() < user_tray_2_down_pos_2 + 300 && ctlr_buttonUP)
    // {
    //   intake_set(-90);
    // }
  }
}

// tray control 1 =================================================================================
// press R1 to go up
// press R2 to go down

void user_tray_1 ()
{
  if (ctlr_buttonUP)
  {
    tray.set_target(100);
  }
  else if (ctlr_buttonDOWN)
  {
    tray.set_target(-100);
  }
  else
  {
    tray.set_target(0);
  }
}

// tray control 2 - slows down near the top =======================================================
void user_tray_2 ()
{
  if (ctlr_buttonRIGHT) // if the up button is pressed
  {
    tray.update_power_mode_set(0);
    if (tray.rotation_get() < user_tray_2_up_pos_1) // if we are not close to verticle
    {
      tray.set_target(user_tray_2_up_power_super_fast);
    }
    else if (tray.rotation_get() < user_tray_2_up_pos_2) // if we are close to verticle
    {
      tray.set_target(user_tray_2_up_power_fast);
    }
    else if (tray.rotation_get() < user_tray_2_up_pos_3) // if we are closer to verticle
    {
      tray.set_target(user_tray_2_up_power_slow);
    }
    else // if we are past the limit
    {
      tray.set_target(-20);
    }
  }
  else if (ctlr_buttonDOWN) // if down button is pressed
  {
    tray.update_power_mode_set(0);
    tray.set_target(user_tray_2_down_power_fast);
  }
  else
  {
    if (tray.rotation_get() > user_tray_2_up_pos_1 && tray.rotation_get() < user_tray_2_up_pos_3)
    {
      tray.update_power_mode_set(1);
      tray.set_target(15);
    }
    else if (tray.rotation_get() > user_tray_2_up_pos_3)
    {
      tray.update_power_mode_set(1);
      tray.set_target(-20);
    }
    else
    {
      tray.update_power_mode_set(0);
      tray.set_target(0);
    }
  }
}

// tray control 3 - slows down near the top and resets in the beginning ===========================
bool user_tray_3_setup_done = false;
int user_tray_3_setup_count = 0;

void user_tray_3 ()
{
  if (ctlr_buttonUP || ctlr_buttonDOWN) {
    user_tray_3_setup_done = true;
  }
  if (!user_tray_3_setup_done) {
    user_tray_3_setup_count += 1;
    tray.update_power_mode_set(true);
    tray.set_target(-30);
    if (fabs(tray.rotation_change_get()) == 0.0 &&
        user_tray_3_setup_count > 20) {
      tray.rotation_reset();
      user_tray_3_setup_done = true;
    }
  } else {
    tray.update_power_mode_set(false);
  }

  if (ctlr_buttonUP) // if the up button is pressed
  {
    tray.update_power_mode_set(0);
    if (tray.rotation_get() <
        user_tray_3_up_pos_1) // if we are not close to verticle
    {
      tray.set_target(user_tray_3_up_power_super_fast);
    } else if (tray.rotation_get() <
               user_tray_3_up_pos_2) // if we are close to verticle
    {
      tray.set_target(user_tray_3_up_power_fast);
    } else if (tray.rotation_get() <
               user_tray_3_up_pos_3) // if we are closer to verticle
    {
      tray.set_target(user_tray_3_up_power_slow);
    } else // if we are past the limit
    {
      tray.set_target(-20);
    }
  } else if (ctlr_buttonDOWN) // if down button is pressed
  {
    tray.update_power_mode_set(0);
    tray.set_target(user_tray_3_down_power_fast);
  } else {
    if (tray.rotation_get() > user_tray_3_up_pos_1 &&
        tray.rotation_get() < user_tray_3_up_pos_3) {
      tray.update_power_mode_set(1);
      tray.set_target(15);
    } else if (tray.rotation_get() > user_tray_3_up_pos_3) {
      tray.update_power_mode_set(1);
      tray.set_target(-20);
    } else if (user_tray_3_setup_done) {
      tray.update_power_mode_set(0);
      tray.set_target(0);
    }
  }
}

// arm control 1 - kinda dumb =====================================================================
void user_arm_1()
{
  if (ctlr_buttonY)
  {
    arm.set_target(100);
  }
  else if (ctlr_buttonB)
  {
    arm.set_target(-75);
  }
  else
  {
    arm.set_target(0);
  }
}

// arm and tray control 1 - simple combined control ===============================================
int user_arm_tray_1_tray_automatic = 0; // 0 when button input works, 1 when target is down, 2 when target is up
int user_arm_tray_1_arm_automatic = 0; // 0 when button input works, 1 when target is down

void user_arm_tray_1 ()
{
  if (user_arm_tray_1_arm_up) // button input for automatic tray and arm control
  {
    user_arm_tray_1_tray_automatic = 2;
    user_arm_tray_1_arm_automatic = 0;
  }
  else if (user_arm_tray_1_arm_down_duration >= 500)
  {
    user_arm_tray_1_tray_automatic = 1;
    user_arm_tray_1_arm_automatic = 1;
  }

  // automatic tray control (usercontrol at the very end)
  if (user_arm_tray_1_tray_automatic == 2) // if the tray target is up
  {
    if (tray.rotation_get() < user_arm_tray_1_tray_3) // if the tray is too low
    {
      if (arm.rotation_get() > user_arm_tray_1_arm_2)
      {
        tray.set_target(user_arm_tray_1_tray_auto_up_pwr);
      }
      else
      {
        tray.set_target(user_arm_tray_1_tray_auto_up_pwr/2);
      }
    }
    else if (tray.rotation_get() >= user_arm_tray_1_tray_3 && tray.rotation_get() < user_arm_tray_1_tray_3 + user_arm_tray_1_tray_moe)  // if the tray is above the target
    {
      tray.set_target(0);
    }
    else // if the tray is too high
    {
      tray.set_target(user_arm_tray_1_tray_auto_down_pwr);
    }
  }
  else if (user_arm_tray_1_tray_automatic == 1) // if the tray target is down
  {
    if (tray.rotation_get() > user_arm_tray_1_tray_0) // if the tray is too high
    {
      if (arm.rotation_get() < user_arm_tray_1_arm_2)
      {
        tray.set_target(user_arm_tray_1_tray_auto_down_pwr);
      }
      else
      {
        tray.set_target(0);
      }
    }
    else // if the tray is down - DONE
    {
      tray.set_target(0);
      user_arm_tray_1_tray_automatic = 0; // engage usercontrol for the tray
    }
  }
  else // usercontrol for the tray
  {
    if (user_arm_tray_1_tray_up) // if tray up button is pressed
    {
      if (tray.rotation_get() < user_arm_tray_1_tray_4) // stage 1
      {
        tray.set_target(user_arm_tray_1_tray_up_pwr_1); // fastest usercontrol power
      }
      else if (tray.rotation_get() < user_arm_tray_1_tray_5) // stage 2
      {
        tray.set_target(user_arm_tray_1_tray_up_pwr_2);
      }
      else if (tray.rotation_get() < user_arm_tray_1_tray_6) // stage 3
      {
        tray.set_target(user_arm_tray_1_tray_up_pwr_3);
      }
      else if (tray.rotation_get() < user_arm_tray_1_tray_7) // limit
      {
        tray.set_target(0);
      }
      else
      {
        tray.set_target(user_arm_tray_1_tray_down_pwr_2);
      }
    }
    else if (user_arm_tray_1_tray_down) // if tray down button is pressed
    {
      tray.set_target(user_tray_2_down_power_fast);
    }
    else
    {
      tray.set_target(0);
    }
  }

  // arm usercontrol
  if (user_arm_tray_1_arm_automatic) // if automatic control down
  {
    if (arm.rotation_get() > user_arm_tray_1_arm_1) // if the tray is too high
    {
      arm.set_target(user_arm_tray_1_arm_down_pwr);
    }
    else // if the arm is down - DONE
    {
      tray.set_target(0);
      user_arm_tray_1_tray_automatic = 0; // engage usercontrol for the tray
    }
  }
  else // usercontrol
  {
    if (user_arm_tray_1_arm_up)
    {
      arm.set_target(user_arm_tray_1_arm_up_pwr);
    }
    else if (user_arm_tray_1_arm_down)
    {
      arm.set_target(user_arm_tray_1_arm_down_pwr);
    }
    else
    {
      arm.set_target(0);
    }
  }
}

// TIA control 1 - tray, intake, and arm combined control =========================================
int user_TIA_tray_automatic         =  0; // 0 when button input works, 1 when target is down, 2 when target is up
int user_TIA_arm_automatic          =  0; // 0 when button input works, 1 when target is down
int user_TIA_intake_automatic       =  0; // 0 when button input works, 1 when outtaking automatically
int user_TIA_intake_automatic_timer = -1; // to track how long the intake should outtake while stacking

void user_TIA_1()
{
  // update automatic variables =================
  if (user_TIA_arm_up)
  {
    user_TIA_arm_automatic = 0;
    user_TIA_tray_automatic = 2;
    user_TIA_intake_automatic = 0;
  }
  if (user_TIA_arm_down_duration > user_TIA_arm_down_duration_constant)
  {
    user_TIA_arm_automatic = 1;
    user_TIA_tray_automatic = 1;
    user_TIA_intake_automatic = 0;
  }
  if (user_TIA_tray_up && user_TIA_tray_automatic == 0)
  {
    if (user_TIA_tray_up_pressed)
    {
      user_TIA_intake_automatic = 1;
      user_TIA_intake_automatic_timer = 0;
    }
    user_TIA_arm_automatic = 1;
  }
  if (user_TIA_tray_down_duration > user_TIA_tray_down_duration_constant && user_TIA_tray_automatic == 0)
  {
    user_TIA_tray_automatic = 0;
  }

  // tray control ===============================
  if (user_TIA_tray_automatic != 0) // automatic tray control
  {
    if (user_TIA_tray_automatic == 1) // tray target down
    {
      if (tray.rotation_get() > user_TIA_tray_pos_1 /* down position */ && arm.rotation_get() < user_TIA_arm_pos_4 /* safety pos 1 */)
      {
        if (tray.rotation_get() > user_TIA_tray_pos_3 /* slow down position */)
        {
          tray.set_target(-user_TIA_tray_pwr_5 /* fast auto power */);
        }
        else
        {
          tray.set_target(-user_TIA_tray_pwr_6) /* slow auto power */;
        }
      }
      else if (tray.rotation_get() > user_TIA_tray_pos_1) // if the tray is up but shouldn't move because of the arm
      {
        tray.set_target(0);
      }
      else if (tray.rotation_get() <= user_TIA_tray_pos_1) // if the tray is down; back to usercontrol
      {
        tray.set_target(0);
        user_arm_tray_1_tray_automatic = 0;
      }
      else // should never happen
      {
        tray.set_target(0);
      }
    }
    else if (user_TIA_tray_automatic == 2) // tray target up
    {
      if (tray.rotation_get() < user_TIA_tray_pos_5 /* safe position 2 */) // if the tray is too low
      {
        if (tray.rotation_get() < user_TIA_tray_pos_4 /* safe position 1 */)
        {
          tray.set_target(user_TIA_tray_pwr_5 /* auto fast power */);
        }
        else
        {
          // linearly decrease the power as it reaches the target position
          tray.set_target(user_TIA_tray_pwr_6 + (user_TIA_tray_pwr_5 - user_TIA_tray_pwr_6)*(1 - (tray.rotation_get() - user_TIA_tray_pos_4)/(user_TIA_tray_pos_5 - user_TIA_tray_pos_4)));
        }
      }
      else if (tray.rotation_get() > user_TIA_tray_pos_5 + user_TIA_tray_moe) // if the tray is too high
      {
        tray.set_target(-user_TIA_tray_pwr_6 /* auto slow power */);
      }
      else // if the tray is just right
      {
        tray.set_target(0);
      }
    }
    else // if the tray_automatic has done something funky, go back to usercontrol
    {
      user_TIA_tray_automatic = 0;
    }
  }
  else // tray usercontrol ======================
  {
    if (user_TIA_tray_up && !user_TIA_tray_down) // tray up
    {
      if (tray.rotation_get() < user_TIA_tray_pos_6 /* slow down position (user) */) // normal up speed
      {
        tray.set_target(user_TIA_tray_pwr_1 /* fast up pwr */);
      }
      else if (tray.rotation_get() < user_TIA_tray_pos_7 /* tray up position */) // slowing down to stack
      {
        tray.set_target(user_TIA_tray_pwr_2 + (user_TIA_tray_pwr_1 - user_TIA_tray_pwr_2) * (1 - (tray.rotation_get() - user_TIA_tray_pos_6)/(user_TIA_tray_pos_7 - user_TIA_tray_pos_6)));
      }
      else if (tray.rotation_get() > user_TIA_tray_pos_8 /* limit */)
      {
        tray.set_target(user_TIA_tray_pwr_4 /* slow down power (user) */);
      }
      else
      {
        tray.set_target(0);
      }
    }
    else if (user_TIA_tray_down && !user_TIA_tray_up) // tray down
    {
      if (tray.rotation_get() > user_TIA_tray_pos_2 /* user slowdown pos */) // fast down
      {
        tray.set_target(user_TIA_tray_pwr_3 /* fast down power */);
      }
      else if (tray.rotation_get() > user_TIA_tray_pos_1) // slow down
      {
        tray.set_target(user_TIA_tray_pwr_4);
      }
      else
      {
        tray.set_target(0);
      }
    }
    else // no valid usercontrol input for the tray
    {
      tray.set_target(0);
    }
  }

  // arm control ================================
  if (user_TIA_arm_automatic != 0) // automatic arm control
  {
    if (user_TIA_arm_automatic == 1) // arm target down
    {
      if (arm.rotation_get() > user_TIA_arm_pos_4 /* tray safety pos (minor) */)
      {
        arm.set_target(-user_TIA_arm_pwr_4);
      }
      else if (arm.rotation_get() > user_TIA_arm_pos_2 /* slow down pos */)
      {
        arm.set_target(-user_TIA_arm_pwr_5);
      }
      else
      {
        arm.set_target(0);
        user_TIA_arm_automatic = 0;
      }
    }
    else // if the code messed up somehow, revert back to usercontrol
    {
      user_TIA_arm_automatic = 0;
    }
  }
  else // arm usercontrol =======================
  {
    if (user_TIA_arm_up)
    {
      arm.set_target(user_TIA_arm_pwr_1);
    }
    else if (user_TIA_arm_down)
    {
      arm.set_target(user_TIA_arm_pwr_2);
    }
    else
    {
      arm.set_target(0);
    }
  }

  // intake control =============================
  if (user_TIA_intake_automatic != 0) // automatic intake control
  {
    if (user_TIA_intake_automatic == 1)
    {
      if (user_TIA_intake_automatic_timer >= user_TIA_auto_outtake_duration)
      {
        user_TIA_intake_automatic = 0;
        user_TIA_intake_automatic_timer = 0;
      }

      intake_set(user_TIA_intake_pwr_4);

      if (user_TIA_intake_automatic == 1)
      {
        user_TIA_intake_automatic_timer += 20;
      }
    }
    else if (user_TIA_intake_automatic == -1)
    {
      intake_set(-100);

      if (user_TIA_intake_automatic_timer < 1000)
      {
        user_TIA_intake_automatic_timer += 20;
      }
      else
      {
        intake_set(0);
        user_TIA_intake_automatic = 0;
      }
    }
    else
    {
      user_TIA_intake_automatic = 0; // back to usercontrol for the intake
    }
  }
  else // intake usercontrol
  {
    if (ctlr_buttonR1) // fast intaking
    {
      intake_set(user_TIA_intake_pwr_1);
    }
    else if (ctlr_buttonL1) // slow intake
    {
      intake_set(user_TIA_intake_pwr_2);
    }
    else if (ctlr_buttonR2) // outtaking
    {
      intake_set(user_TIA_intake_pwr_3);
    }
    else
    {
      intake_set(0);
    }
  }
}