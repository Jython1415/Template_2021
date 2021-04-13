#include "vex.h"
#include "pragma.h"
#include "motor/class.h"

// // set target functions ===========================================================================
// void left_set (int input)
// {
//   left_front.set_target(input);
//   left_back.set_target(input);
// }
// void right_set (int input)
// {
//   right_front.set_target(input);
//   right_back.set_target(input);
// }
// void chassis_set (int input)
// {
//   left_set(input);
//   right_set(input);
// }
void motors_set (int input)
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).set_target(input);
  }
}

// update functions  ==============================================================================
// update vars
void motors_update_vars ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).tf_1(*Motors[i]);
  }
}
// update power vel
void motors_update_power_vel ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).update_power_vel();
  }
}
// // update power vol
void motors_update_power_vol ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).update_power_vol();
  }
}
// // update power
void motors_update_power ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).update_power();
  }
}
// // update rotation vars
void motors_update_rotation_vars ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).update_rotation_vars();
  }
}
// // update brake types
void motors_update_brake_type ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).update_brake_type();
  }
}

// // reset rotation =================================================================================
// void left_rotation_reset ()
// {
//   left_front.rotation_reset();
//   left_back.rotation_reset();
// }
// void right_rotation_reset ()
// {
//   right_front.rotation_reset();
//   right_back.rotation_reset();
// }
// void chassis_reset_rotation ()
// {
//   left_rotation_reset();
//   right_rotation_reset();
// }
void motors_rotation_reset ()
{
  for (int i = 0; i < Motors.size(); i++)
  {
    (*Motors[i]).rotation_reset();
  }
}