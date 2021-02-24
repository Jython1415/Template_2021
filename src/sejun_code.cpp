#include "vex.h"
#include "pragma.h"

void Chassis_forward(int power)
{
  left_back.spin(directionType::fwd, power, velocityUnits::pct);
  left_front.spin(directionType::fwd, power, velocityUnits::pct);
  right_back.spin(directionType::fwd, power, velocityUnits::pct);
  right_front.spin(directionType::fwd, power, velocityUnits::pct);
}

void intake(int power)
{
  intake_l.spin(directionType::fwd, power, velocityUnits::pct);
  intake_r.spin(directionType::fwd, power, velocityUnits::pct);
}

void Chassis_right(int power)
{
  right_back.spin(directionType::fwd, power, velocityUnits::pct);
  right_front.spin(directionType::fwd, power, velocityUnits::pct);
}

void Chassis_left(int power)
{
  left_back.spin(directionType::fwd, power, velocityUnits::pct);
  left_front.spin(directionType::fwd, power, velocityUnits::pct);
}

void tilt(int power)
{
  tray.spin(directionType::fwd, power, velocityUnits::pct);
}

void rstop(void)
{
  right_back.stop();
  right_front.stop();
}

void lstop(void)
{
  left_back.stop();
  left_front.stop();
}

void istop(void)
{
  intake_l.stop();
  intake_r.stop();
}

void sleep(int time)
{
  vex::task::sleep(time);
}

void stop(void)
{
  intake_l.stop();
  intake_r.stop();
  right_back.stop();
  left_front.stop();
  right_front.stop();
  left_back.stop();
  tray.stop();
}

void auton_forward(int rotation)
{
  right_back.rotateTo(rotation, rotationUnits::raw);
  right_front.rotateTo(rotation, rotationUnits::raw);
  left_back.rotateTo(rotation, rotationUnits::raw);
  left_front.rotateTo(rotation, rotationUnits::raw);
}

void auton_right(int rotation)
{
  right_back.rotateTo(rotation, rotationUnits::raw);
  right_front.rotateTo(rotation, rotationUnits::raw);
  left_back.rotateTo(-rotation, rotationUnits::raw);
  left_front.rotateTo(-rotation, rotationUnits::raw);
}

void auton_left(int rotation)
{
  right_back.rotateTo(-rotation, rotationUnits::raw);
  right_front.rotateTo(-rotation, rotationUnits::raw);
  left_back.rotateTo(rotation, rotationUnits::raw);
  left_front.rotateTo(rotation, rotationUnits::raw);
}