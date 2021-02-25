#include "vex.h"
#include "motor/class.h"

vex::brain            Brain;
vex::competition Competition;

vex::controller Controller_1 = vex::controller();

// ================ name =========== port ======== reverse = brake type = slew? = voltage? = act pwr = tar pwr = rot === d rot
Motor left_front  ( "left front"   , vex::PORT13 , false   , 0          , false , false    , false   , true    , false , false );
Motor left_back   ( "left back"    , vex::PORT14 , false   , 1          , false , false    , false   , true    , false , false );
Motor right_front ( "right front"  , vex::PORT20 , true    , 2          , false , false    , false   , true    , false , false );
Motor right_back  ( "right back"   , vex::PORT19 , true    , 3          , false , false    , false   , true    , false , false );

std::list<Motor> Motors = {left_front   ,
/* ==================== */ left_back    ,
/* ==================== */ right_front  ,
/* ==================== */ right_back
};
