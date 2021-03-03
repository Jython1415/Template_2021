#include "motor/class.h"

// ================================================================================================
void Motor::set_target (int input)
{
  target_power = math_restrict_i(input, -100, 100);
}

// update functions ===============================================================================
void Motor::update_vars_direct ()
{
  actual_power = target_power;
}

void Motor::update_vars_slew ()
{
  if (actual_power < target_power)
  {
    actual_power += slew_rate;
    if (actual_power > target_power)
    {
      actual_power = target_power;
    }
  }
  else if (actual_power > target_power)
  {
    actual_power -= slew_rate;
    if (actual_power < target_power)
    {
      actual_power = target_power;
    }
  }
}

void Motor::update_vars ()
{
  if (update_vars_mode)
  {
    update_vars_slew();
  }
  else
  {
    update_vars_direct();
  }
}

void Motor::update_power_vel ()
{
  spin(vex::directionType::fwd, actual_power, vex::velocityUnits::pct);
}

void Motor::update_power_vol ()
{
  spin(vex::directionType::fwd, math_map_f(actual_power, -100, 100, -12.0, 12.0), vex::voltageUnits::volt);
}

void Motor::update_power ()
{
  if (update_power_mode)
  {
    Motor::update_power_vol();
  }
  else
  {
    Motor::update_power_vel();
  }
}

void Motor::update_rotation ()
{
  rotation_current = rotation(vex::rotationUnits::raw) - rotation_initial;
}

void Motor::update_rotation_prev ()
{
  rotation_prev = rotation_current;
}

void Motor::update_rotation_change ()
{
  rotation_change = rotation_current - rotation_prev;
}

void Motor::update_rotation_vars ()
{
  update_rotation_prev();
  update_rotation();
  update_rotation_change();
}

void Motor::update_brake_type ()
{
  switch (brake_type)
  {
    case 0:
      setBrake(vex::brakeType::coast);
      break;
    case 1:
      setBrake(vex::brakeType::brake);
      break;
    case 2:
      setBrake(vex::brakeType::hold);
      break;
    default:
      setBrake(vex::brakeType::undefined);
      break;
  }
}

// reset rotation =============================================================================
void Motor::rotation_reset ()
{
  rotation_initial = rotation(vex::rotationUnits::raw);
  rotation_current = 0;
  rotation_prev = 0;
  rotation_change = 0;
}

// debug print functions ======================================================================
void Motor::print_actual_power ()
{
  if (print_actual_power_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, " actual power: %d");
    Brain.Screen.print(result, actual_power_get());
    std::cout << actual_power_get() << "," << std::flush;
    Brain.Screen.newLine();

  }
}

void Motor::print_target_power ()
{
  if (print_target_power_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, " target power: %d");
    Brain.Screen.print(result, target_power_get());
    std::cout << target_power_get() << "," << std::flush;
    Brain.Screen.newLine();

  }
}

void Motor::print_rotation ()
{
  if (print_rotation_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, " rotation: %f");
    Brain.Screen.print(result, rotation(vex::rotationUnits::raw));
    std::cout << rotation_get() << "," << std::flush;
    Brain.Screen.newLine();

  }
}

void Motor::print_rotation_change ()
{
  if (print_rotation_change_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, " rotation change: %f");
    Brain.Screen.print(result, rotation_change_get());
    std::cout << rotation_change_get() << "," << std::flush;
    Brain.Screen.newLine();

  }
}

// print initial functions ====================================================================
void Motor::print_initial_actual_power ()
{
  if (print_actual_power_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, "actual power,");
    std::cout << result << std::flush;
  }
}
void Motor::print_initial_target_power ()
{
  if (print_target_power_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, "target power,");
    std::cout << result << std::flush;
  }
}
void Motor::print_initial_rotation ()
{
  if (print_rotation_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, "rotation,");
    std::cout << result << std::flush;
  }
}
void Motor::print_initial_rotation_change ()
{
  if (print_rotation_change_bool)
  {
    char result[100]; strcpy(result, name.c_str()); strcat(result, "rotation change,");
    std::cout << result << std::flush;
  }
}

// getter functions ===========================================================================
int Motor::actual_power_get ()
{
  return actual_power;
}
int Motor::target_power_get ()
{
  return target_power;
}
double Motor::rotation_get ()
{
  return rotation_current;
}
double Motor::rotation_prev_get()
{
  return rotation_prev;
}
double Motor::rotation_change_get()
{
  return rotation_change;
}

// setter functions ===========================================================================
void Motor::slew_rate_set (int input_rate)
{
  slew_rate = input_rate;
}
void Motor::update_power_mode_set (bool input_bool)
{
  update_power_mode = input_bool;
}

// contructor =================================================================================
Motor::Motor (std::string name_input, int index, bool reverse, int brake_type_input, bool update_vars_mode_input, bool update_power_mode_input, bool print_actual_power_input, bool print_target_power_input, bool print_rotation_input, bool print_rotation_change_input) : vex::motor (index, reverse)
{
  motor (index, reverse);

  name = name_input;

  brake_type = brake_type_input;

  update_vars_mode  = update_vars_mode_input ;
  update_power_mode = update_power_mode_input;

  print_actual_power_bool    = print_actual_power_input   ;
  print_target_power_bool    = print_target_power_input   ;
  print_rotation_bool        = print_rotation_input       ;
  print_rotation_change_bool = print_rotation_change_input;

  target_power =   0;
  actual_power =   0;

  rotation_current = 0.0;
  rotation_prev    = 0.0;
  rotation_change  = 0.0;
  rotation_initial = 0.0;

  slew_rate = DEFAULT_SLEW_RATE;
}