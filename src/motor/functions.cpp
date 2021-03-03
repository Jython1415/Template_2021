#include "vex.h"
#include "pragma.h"
#include "motor/class.h"

// set target functions ===========================================================================
void left_set (int input)
{
  left_front.set_target(input);
  left_back.set_target(input);
}
void right_set (int input)
{
  right_front.set_target(input);
  right_back.set_target(input);
}
void chassis_set (int input)
{
  left_set(input);
  right_set(input);
}
void motors_set (int input)
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->set_target(input);
  }
}

// update functions  ==============================================================================
// update vars
void motors_update_vars ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->update_vars();
  }
}
// update power vel
void motors_update_power_vel ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->update_power_vel();
  }
}
// update power vol
void motors_update_power_vol ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->update_power_vol();
  }
}
// update power
void motors_update_power ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->update_power();
  }
}
// update rotation vars
void motors_update_rotation_vars ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->update_rotation_vars();
  }
}
// update brake types
void motors_update_brake_type ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->update_brake_type();
  }
}

// reset rotation =================================================================================
void left_rotation_reset ()
{
  left_front.rotation_reset();
  left_back.rotation_reset();
}
void right_rotation_reset ()
{
  right_front.rotation_reset();
  right_back.rotation_reset();
}
void chassis_reset_rotation ()
{
  left_rotation_reset();
  right_rotation_reset();
}
void motors_rotation_reset ()
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->rotation_reset();
  }
}