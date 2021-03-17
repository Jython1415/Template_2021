#include "vex.h"
#include "motor/class.h"

vex::brain            Brain;
vex::competition Competition;

vex::controller Controller_1 = vex::controller();

// NAME: name for debug reference
// PORT: which port on the VEX Brain the motor is connected to
/* REVERSE -----
true  - reversed
false - not reversed -- */
/* BRAKE TYPE -----
0 - coast
1 - brake
2 - hold
3 - undefined -- */
/* SLEW -----
true  - controlled acceleration
false - means direct translation of target power to actual power --- */
// ================ name =========== port ======== reverse = brake type = slew? = voltage? = act pwr = tar pwr = rot === d rot
Motor left_front  ( "left front"   , vex::PORT1  , true    , 0          , false , false    , false   , true    , false , false );
Motor left_back   ( "left back"    , vex::PORT9  , false   , 0          , false , false    , false   , true    , false , false );
Motor right_front ( "right front"  , vex::PORT5  , false   , 0          , false , false    , false   , true    , false , false );
Motor right_back  ( "right back"   , vex::PORT8  , true    , 0          , false , false    , false   , true    , false , false );

std::list<Motor> Motors = {left_front   ,
/* ==================== */ left_back    ,
/* ==================== */ right_front  ,
/* ==================== */ right_back
};
