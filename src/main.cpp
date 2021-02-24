// adding arm_tray_intake_1()
#include "vex.h"
#include "pragma.h"
#include "controller.h"
#include "motor/class.h"
#include "debug.h"
#include "usercontrol.h"
#include "autonomous/functions.h"
#include "autonomous/routes.h"
#include "custom_math.h"

// recording mode =================================================================================
#define RECORDING_MODE 0
// auton selection ================================================================================
#define AUTON_ROUTE -1

// actions inside this functions will be performed once  after the robot is powered on ============
void pre_auton( void )
{
}

// all code for the autonomous section goes in here ===============================================
void autonomous( void )
{
  auton_standard_initialize();

  switch (AUTON_ROUTE)
  {
    case -4  :
      auton_route_testing_4();
      break;
    case -3  :
      auton_route_testing_3();
      break;
    case -2  :
      auton_route_testing_2();
      break;
    case -1  :
      auton_route_testing_1();
      break;
    case 0  : // nothing
      auton_route_0();
      break;
    case 1  :
      auton_route_1();
      break;
    case 2  :
      auton_route_2();
      break;
    case 3  :
      auton_route_3();
      break;
    case 4  :
      auton_route_4();
      break;
    case 5  :
      auton_route_5();
      break;
    case 6  :
      auton_route_6();
      break;
    case 11 :
      auton_route_11();
      break;
    case 12 :
      auton_route_12();
      default:
    case 13 :
      auton_route_13();
      break;
  }
}

// all code for the usercontrol section goes in here ==============================================
void usercontrol( void )
{
  motors_rotation_reset();
  debug_print_initial();
  
  arm.setBrake(vex::brakeType::hold);
  tray.setBrake(vex::brakeType::hold);

  while (true)
  {
    // variable updates
    debug_updateVar();
    ctlr_updateVars();
    motors_update_rotation_vars();

    user_tank_2();
    user_TIA_1();

    // slew rate & such
    motors_update_vars();

    // set power to the motors unless we're recording right now
    if (!RECORDING_MODE) { motors_update_power(); }

    // print to console & the brain's screen
    debug_print();

    //Sleep the task for a short amount of time to prevent wasted resources. 
    vex::task::sleep(20);
  }
}

int main()
{
  vexcodeInit(); // Initializing Robot Configuration. DO NOT REMOVE!

  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );

  pre_auton(); // run the pre_auton code
      
  //Prevent main from exiting with an infinite loop.                        
  while(1) {
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
  }  
}
