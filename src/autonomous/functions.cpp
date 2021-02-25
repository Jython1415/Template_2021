#include "autonomous/functions.h"

// standard auton functions =======================================================================
// auton standard initializing function
void auton_standard_initialize ()
{
  // set rotation values to zero
  motors_rotation_reset();
  // print for spreadsheet compatability
  debug_print_initial();
}

// standard beginning of loop
void auton_standard_update_beg ()
{
  // update loop variable for debug function
  debug_updateVar();
  // update motor varaibles
  motors_update_rotation_vars();
}

// standard end of loop
void auton_standard_update_fin ()
{
  // calculate power based on target power (using slew rate most of the time)
  motors_update_vars();
  // actually set motor power
  motors_update_power();
  // print to the console and screen (happens only 1 out of 10 loops)
  debug_print();
  // wait
  vex::task::sleep(20);
}

// wait function ==================================================================================
int auton_wait_target = 0;
int auton_wait_current = 0;

void auton_wait (int input)
{
  // set target and account for how wait_done is called before the while loop
  auton_wait_target = input - 20;
  // reset the current time
  auton_wait_current = 0;
}

int auton_wait_done ()
{
  // increment the current wait time by the wait time for the loop
  auton_wait_current += 20;
  // return the correct value based on the target and current varaibles
  if (auton_wait_current >= auton_wait_target)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// ease of use functions ==========================================================================
// ================================================================================================
// wait(time) 
void a_wait (int input_time)
{
  auton_wait(input_time);
  while (!auton_wait_done())
  {
    auton_standard_update_beg();
    auton_standard_update_fin();
  }
}

// reset_and_wait(time) ::: yes reset
void a_reset_and_wait (int time_input)
{
  a_wait(time_input/2);
  chassis_rotation_reset();
  a_wait(time_input/2);
}

// forward(distance, power) ::: no reset 
void a_forward (double target_input, int power_input)
{
  auton_straight_3_set(target_input, power_input);
  while (!auton_straight_3_done())
  {
    auton_standard_update_beg();
    auton_straight_3_loop();
    auton_standard_update_fin();
  }
  chassis_set(0);
}

// drive(power, time) ::: no reset
void a_drive (double power_input, int time_input)
{
  chassis_set(power_input);
  a_wait(time_input);
  chassis_set(0);
}

// turn(target, power) ::: yes reset
void a_turn (double target_input, int power_input)
{
  chassis_rotation_reset();
  auton_turn_1_set(target_input, power_input);
  while (!auton_turn_1_done())
  {
    auton_standard_update_beg();
    auton_turn_1_loop();
    auton_standard_update_fin();
  }
  chassis_set(0);
}

// straight drive 1 ===============================================================================
// just simple forward and backward
int auton_straight_1_done_var       = 0; // 0 is not done, 1 is done
int auton_straight_1_turn_direction = 0; // 1 is left, -1 is right
int auton_straight_1_base_power     = 0; // base power (user input)

double auton_straight_1_target            = 0; // target position
double auton_straight_1_pos_l             = 0; // the current position of the left side
double auton_straight_1_pos_r             = 0; // the current position of the right side
double auton_straight_1_error             = 0; // how far the robot is from its target position
double auton_straight_1_side_error        = 0; // the difference in how far each side has travelled
double auton_straight_1_initial_side_diff = 0; // the initial difference between the right and left sides

void auton_straight_1_set (double target, int base_power)
{
  // set program to not done
  auton_straight_1_done_var = 0;
  // reset variables
  auton_straight_1_turn_direction = 0;
  auton_straight_1_base_power     = 0;
  auton_straight_1_pos_l          = 0;
  auton_straight_1_pos_r          = 0;
  auton_straight_1_error          = 0;
  auton_straight_1_side_error     = 0;
  // user input
  auton_straight_1_target = target;
  auton_straight_1_base_power = base_power;
  // position vars
  right_rotation_reset();
  auton_straight_1_initial_side_diff = left_front.rotation_get();
}

void auton_straight_1_loop ()
{
  // update variables
  auton_straight_1_pos_l = left_front.rotation_get(); // get the current position
  auton_straight_1_pos_r = right_front.rotation_get() + auton_straight_1_initial_side_diff;
  auton_straight_1_error = auton_straight_1_target - auton_straight_1_pos_l; // calculate error
  auton_straight_1_side_error = auton_straight_1_pos_l - auton_straight_1_pos_r;
  auton_straight_1_turn_direction = // continued...
  math_sgn_f(auton_straight_1_side_error); // get turn diretion
  if (fabs(auton_straight_1_side_error) < auton_straight_1_side_moe) // turn margin of error
  {
    auton_straight_1_turn_direction = 0; // apply turn direction moe
  }

  // set power
  left_set(auton_straight_1_base_power * math_sgn_f(auton_straight_1_error) - auton_straight_1_turn_power * auton_straight_1_turn_direction);
  right_set(auton_straight_1_base_power * math_sgn_f(auton_straight_1_error) + auton_straight_1_turn_power * auton_straight_1_turn_direction);
  if (fabs(auton_straight_1_error) < auton_straight_1_target_moe * 2)
  {
    chassis_set(math_sgn_f(auton_straight_1_error) * auton_straight_1_close_power);
  }

  // done?
  if (fabs(auton_straight_1_error) < auton_straight_1_target_moe)
  {
    auton_straight_1_done_var = 1; // set done var to 1
  }
}

bool auton_straight_1_done ()
{
  if (auton_straight_1_done_var == 1 && fabs(left_front.rotation_change_get()) < auton_straight_1_speed_moe)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// straight drive 2 ===============================================================================
// has simple auto-straightening
int auton_straight_2_done_var       = 0; // 0 is not done, 1 is done
int auton_straight_2_turn_direction = 0; // 1 is left, -1 is right
int auton_straight_2_base_power     = 0; // base power (user input)

double auton_straight_2_target            = 0; // target position
double auton_straight_2_pos_l             = 0; // the current position of the left side
double auton_straight_2_pos_r             = 0; // the current position of the right side
double auton_straight_2_error             = 0; // how far the robot is from its target position
double auton_straight_2_side_error        = 0; // the difference in how far each side has travelled
double auton_straight_2_initial_side_diff = 0; // the initial difference between the right and left sides

void auton_straight_2_set (double target, int base_power)
{
  // set program to not done
  auton_straight_2_done_var = 0;
  // reset variables
  auton_straight_2_turn_direction = 0;
  auton_straight_2_base_power     = 0;
  auton_straight_2_pos_l          = 0;
  auton_straight_2_pos_r          = 0;
  auton_straight_2_error          = 0;
  auton_straight_2_side_error     = 0;
  // user input
  auton_straight_2_target = target;
  auton_straight_2_base_power = base_power;
  // position vars
  right_rotation_reset();
  auton_straight_2_initial_side_diff = left_front.rotation_get();
}

void auton_straight_2_loop ()
{
  // update variables
  auton_straight_2_pos_l = left_front.rotation_get(); // get the current position
  auton_straight_2_pos_r = right_front.rotation_get() + auton_straight_2_initial_side_diff;
  auton_straight_2_error = auton_straight_2_target - auton_straight_2_pos_l; // calculate error
  auton_straight_2_side_error = auton_straight_2_pos_l - auton_straight_2_pos_r;
  auton_straight_2_turn_direction = // continued...
  math_sgn_f(auton_straight_2_side_error); // get turn diretion
  if (fabs(auton_straight_2_side_error) < auton_straight_2_side_moe) // turn margin of error
  {
    auton_straight_2_turn_direction = 0; // apply turn direction moe
  }

  // set power
  left_set(auton_straight_2_base_power * math_sgn_f(auton_straight_2_error) - auton_straight_2_turn_power * auton_straight_2_turn_direction);
  right_set(auton_straight_2_base_power * math_sgn_f(auton_straight_2_error) + auton_straight_2_turn_power * auton_straight_2_turn_direction);
  if (fabs(auton_straight_2_error) < auton_straight_2_target_moe * 2)
  {
    chassis_set(math_sgn_f(auton_straight_2_error) * auton_straight_2_close_power);
  }

  // done?
  if (fabs(auton_straight_2_error) < auton_straight_2_target_moe)
  {
    auton_straight_2_done_var = 1; // set done var to 1
  }
}

bool auton_straight_2_done ()
{
  if (auton_straight_2_done_var == 1 && fabs(left_front.rotation_change_get()) < auton_straight_2_speed_moe)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// straight drive 3 ===============================================================================
// doesn't reset the right side
int auton_straight_3_done_var       = 0; // 0 is not done, 1 is done
int auton_straight_3_turn_direction = 0; // 1 is left, -1 is right
int auton_straight_3_base_power     = 0; // base power (user input)

double auton_straight_3_target            = 0; // target position
double auton_straight_3_pos_l             = 0; // the current position of the left side
double auton_straight_3_pos_r             = 0; // the current position of the right side
double auton_straight_3_error             = 0; // how far the robot is from its target position
double auton_straight_3_side_error        = 0; // the difference in how far each side has travelled
double auton_straight_3_initial_side_diff = 0; // the initial difference between the right and left sides

void auton_straight_3_set (double target, int base_power)
{
  // set program to not done
  auton_straight_3_done_var = 0;
  // reset variables
  auton_straight_3_turn_direction = 0;
  auton_straight_3_base_power     = 0;
  auton_straight_3_pos_l          = 0;
  auton_straight_3_pos_r          = 0;
  auton_straight_3_error          = 0;
  auton_straight_3_side_error     = 0;
  // user input
  auton_straight_3_target = target;
  auton_straight_3_base_power = base_power;
  // position vars
  // right_rotation_reset();
  // auton_straight_3_initial_side_diff = left_front.rotation_get();
}

void auton_straight_3_loop ()
{
  // update variables
  auton_straight_3_pos_l = left_front.rotation_get(); // get the current position
  auton_straight_3_pos_r = right_front.rotation_get() + auton_straight_3_initial_side_diff;
  auton_straight_3_error = auton_straight_3_target - auton_straight_3_pos_l; // calculate error
  auton_straight_3_side_error = auton_straight_3_pos_l - auton_straight_3_pos_r;
  auton_straight_3_turn_direction = // continued...
  math_sgn_f(auton_straight_3_side_error); // get turn diretion
  if (fabs(auton_straight_3_side_error) < auton_straight_3_side_moe) // turn margin of error
  {
    auton_straight_3_turn_direction = 0; // apply turn direction moe
  }

  // set power
  left_set(auton_straight_3_base_power * math_sgn_f(auton_straight_3_error) - auton_straight_3_turn_power * auton_straight_3_turn_direction);
  right_set(auton_straight_3_base_power * math_sgn_f(auton_straight_3_error) + auton_straight_3_turn_power * auton_straight_3_turn_direction);
  if (fabs(auton_straight_3_error) < auton_straight_3_target_moe * 4)
  {
    chassis_set(math_sgn_f(auton_straight_3_error) * auton_straight_3_close_power);
  }

  // done?
  if (fabs(auton_straight_3_error) < auton_straight_3_target_moe)
  {
    auton_straight_3_done_var = 1; // set done var to 1
  }
}

bool auton_straight_3_done ()
{
  if (auton_straight_3_done_var == 1 && fabs(left_front.rotation_change_get()) < auton_straight_3_speed_moe)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// turn 1 ========================================================================================
// #define auton_turn_1_min_power       10
// #define auton_turn_1_moe             10
// #define auton_turn_1_min_power_range 50

int auton_turn_1_done_var   = 0; // 0 is not done, 1 is done
int auton_turn_1_base_power = 0; // the base power for turning

double auton_turn_1_target = 0; // left is positive, right is negative
double auton_turn_1_pos    = 0; // current position (angle)
double auton_turn_1_error  = 0; // how far the robot is from the target position (angle)

void auton_turn_1_set (double target_input, double power_input)
{
  // set done to "not done" or "0"
  auton_turn_1_done_var = 0;
  // reset variables
  auton_turn_1_pos   = 0;
  auton_turn_1_error = 0;
  chassis_rotation_reset();
  // set user input variables
  auton_turn_1_target = target_input;
  auton_turn_1_base_power = power_input;
}

void auton_turn_1_loop ()
{
  // update variables
  auton_turn_1_pos = right_front.rotation_get() - left_front.rotation_get();
  auton_turn_1_error = auton_turn_1_target - auton_turn_1_pos;

  // set power
  if (fabs(auton_turn_1_error) > auton_turn_1_min_power_range)
  {
    left_set(auton_turn_1_base_power * -1 * math_sgn_f(auton_turn_1_error));
    right_set(auton_turn_1_base_power * math_sgn_f(auton_turn_1_error));
  }
  else
  {
    left_set(auton_turn_1_min_power * -1 * math_sgn_f(auton_turn_1_error));
    right_set(auton_turn_1_min_power * math_sgn_f(auton_turn_1_error));
  }

  // update done variable
  if (fabs(auton_turn_1_error) < auton_turn_1_moe)
  {
    auton_turn_1_done_var = 1;
  }
}

bool auton_turn_1_done ()
{
  if (auton_turn_1_done_var == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}