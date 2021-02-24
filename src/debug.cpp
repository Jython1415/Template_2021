#include "vex.h"
#include "pragma.h"
#include "controller.h"
#include "motor/class.h"
#include "autonomous/functions.h"
#include "usercontrol.h"
#include "debug.h"

// definitions ====================================================================================
#define DEBUG_LOOP_DELAY 10

// variables ======================================================================================
// for counting loop repetition 
int debug_i = 0;
int debug_count = 0;
// hallo
// run every loop to increment the loop variable ==================================================
void debug_updateVar ()
{
  debug_i += 1;
  if (debug_i == DEBUG_LOOP_DELAY)
  {
    debug_i = 0;
  }
}

// for printing motor position ====================================================================

// for printing other values ======================================================================

// initial print functions ========================================================================
void debug_print_initial ()
{
  // first line
  std::cout << "debug count," << std::flush;

  // initial print function
  for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_actual_power();
  }
  // print target power
  for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_target_power();
  }
  // print rotation
  for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_rotation();
  }
  // print rotation change
  for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_rotation_change();
  }

  std::cout << "blank" << std::endl;
}

// final print function ===========================================================================
void debug_print ()
{
  if (debug_i == 0)
  {
    debug_count += 1;
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 0);
    // std::cout << debug_count << std::flush;
    // std::cout << "," << std::flush;
    
    // // print actual power
    // for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    // {
    //   i->print_actual_power();
    // }
    // print target power
    // for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    // {
    //   i->print_target_power();
    // }
    // print rotation
    // for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    // {
    //   i->print_rotation();
    // }
    // // print rotation change
    // for (std::list<Motor>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    // {
    //   i->print_rotation_change();
    // }

    
    // left_front.set_target(1);
    // std::cout << left_front.target_power << std::endl;
    // std::cout << left_front.target_power_get() << std::endl;
    // std::cout << left_front.print_target_power_bool << ',' << std::flush;
    // left_front.print_target_power();

    
    // if (left_front.print_target_power_bool)
    // {
    //   std::cout << left_front.target_power_get() << "," << std::flush;
    // }

    // int thing = 0;
    left_front.target_power = 1;
    std::cout << left_front.target_power << ',' << std::flush;

    left_back.target_power = 1;
    std::cout << left_back.target_power << ',' << std::flush;
    
    
    
    for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
    {
      // thing += 1;
      // i->print_target_power();
      // i->target_power = 1;

      // left_front.print_target_power();

      // left_front.target_power = 1;
      // std::cout << left_front.target_power << std::flush;
      std::cout << it->target_power << std::flush;
    }


    // std::cout << "  , " << thing << std::flush;

    // Brain.Screen.newLine(); Brain.Screen.print("tray auto: %d", user_arm_tray_1_tray_automatic);
    // Brain.Screen.newLine(); Brain.Screen.print("arm auto: %d", user_arm_tray_1_arm_automatic);
    // Brain.Screen.newLine(); Brain.Screen.print("hello");

    std::cout << std::endl;

    // std::cout << "0" << std::endl;

  }
}