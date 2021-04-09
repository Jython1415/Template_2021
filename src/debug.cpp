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

// for printing other values ======================================================================

// initial print functions ========================================================================

//consolidated intial print function
void debug_print_initial ()
{
  // first line
  std::cout << "debug count," << std::flush;

  // initial print functions
  //print actual power
  for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_actual_power();
  }
  // print target power
  for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_target_power();
  }
  // print rotation
  for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_rotation();
  }
  // print rotation change
  for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
  {
    i->print_initial_rotation_change();
  }

  ctlr_debug_print_initial();

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
    std::cout << debug_count << std::flush;
    std::cout << "," << std::flush;
    
    // print actual power
    for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    {
      i->print_actual_power();
    }
    // print target power
    for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    {
      i->print_target_power();
    }
    // print rotation
    for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    {
      i->print_rotation();
    }
    // print rotation change
    for (std::list<Motor_v2>::iterator i=Motors.begin(); i != Motors.end(); ++i)
    {
      i->print_rotation_change();
    }
    
    ctlr_debug_print_loop();

    std::cout << "0" << std::endl;
  }
}