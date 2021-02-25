#include "vex.h"
#include "pragma.h"
#include "motor/class.h"
#include "custom_math.h"
#include "autonomous/functions.h"
#include "autonomous/routes.h"

// route wait function
void auton_route_wait (int input)
{
  auton_wait(input);
  while (!auton_wait_done())
  {
    auton_standard_update_beg();    
    auton_standard_update_fin();
  }
}

// testing routes =================================================================================
void auton_route_testing_4 ()
{
}

void auton_route_testing_3 ()
{
}

void auton_route_testing_2 () // 1 cube i think
{
}

void auton_route_testing_1 () // stacking testing
{
  auton_intake_1_in();
  a_wait(1000);
  auton_intake_1_stop();
  a_wait(100);
}

// blank and template
void auton_route_0 ()
{
  // initialize stuff

  // set initial commands

  // while loop
    // loop that needs updating
    // other loop that needs updating
    // wait command
  
  // set other initial commands

  // while loops
    // loop that needs updating
    // other loop that needs updating
    // wait command
}

// 5 point red unprotected auton 
void auton_route_1 ()
{
  //flip out starts 
  intake(-100);
  tilt(-5);
  sleep(1800);

  sleep(20);
  //flip out ends 

  //go forward intake 5 cubes
  right_back.resetRotation();
  
  if (right_back.rotation_get()<2000)
  {
    Chassis_forward(40);
    intake(100);
  }
  //forward stop 
  
  //just there
  sleep(20);

  //go back
  right_back.resetRotation();
  if (right_back.rotation_get()<1500)
  {
    Chassis_forward(-40);
    intake(100);
  }
  // go back stop

  //just there again
  sleep(20);

  //rotate towards the unprotected side
  right_back.resetRotation();
  if (right_back.rotation_get()<1750)
  {
    Chassis_right(40);
    intake(100);
  }
  // stop turning

  //just there x3
  sleep(20);

  //go towards the unprotected zone
  right_back.resetRotation();
  if (right_back.rotation_get()<500)
  {
    Chassis_forward(30);
    intake(100);
  }

  //tilt 
  right_back.resetRotation();
  if (tray.rotation_get()<1700)
  {
    tray.set_target(40);
    intake(-20);
  }
  //tilt stop

  tray.resetRotation();
  if (right_back.rotation_get()<500)
  {
    Chassis_forward(-50);
  }

  stop();
}

// 5 point red (15 seconds) [protected]
void auton_route_2 ()
{
}


// 7-8 point 15 second red autonomous

void auton_route_3 ()
{
  //flip out starts 
  intake(-100);
  tilt(-5);
  sleep(1800);

  //grab 5 cubes (4 bubes for now)
  right_back.resetRotation();
  if (right_back.rotation_get()<0)
  {
    Chassis_forward(40);
    intake(100);
  }

  sleep(20);

  //s-line curve-ish move
  right_back.resetRotation();
  if (right_back.rotation_get()<0)
  {
    Chassis_forward(-40);
    intake(100);
  }

  sleep(20);

  right_back.resetRotation();
  if (right_back.rotation_get()<0)
 {
   Chassis_right(40);
   intake(100);
 }

  sleep(20);

  right_back.resetRotation();
  if (right_back.rotation_get()<0)
  {
    Chassis_forward(-100);
    intake(100);
  }

  //intake 4-5 cubes 
  right_back.resetRotation();
  if (right_back.rotation_get()<0)
  {
    Chassis_forward(40);
    intake(100);
  }

  sleep(20);

  //going back - turn towards the unprotected zone
  right_back.resetRotation();
  if (right_back.rotation_get()<0)
  {
    Chassis_left(40);
    intake(100);
  }

  sleep(20);

  //go towards the zone
  right_back.resetRotation();
  if (right_back.rotation_get()<0)
  {
    Chassis_right(40);
    intake(100);
  }

  sleep(20);

  //tray 
  right_back.resetRotation();
  if (tray.rotation_get()<0)
  {
    a_stack();
  }

  sleep(20);

  Chassis_forward(-40);
  sleep(500);

  stop();
}

// 5 points blue (15 seconds) [unprotected]
void auton_route_4 ()
{
  
}

// 3 points blue (15 seconds) [protected]
void auton_route_5 ()
{
  
}

// 5 point blue (15 seconds) [protected]
void auton_route_6 ()
{
  
}

// 12 point auton
void auton_route_11 ()
{
  
}

// 12 point auton route 2 - Joshua
void auton_route_12 ()
{
 
}

// another sejun auton
void auton_route_13 ()
{
  
}
