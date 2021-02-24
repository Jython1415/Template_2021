#ifndef _pragma_H_
#define _pragma_H_

#include "vex.h"
#include "motor/class.h"

extern vex::brain             Brain ;
extern vex::competition Competition ;

extern vex::controller Controller_1 ;

extern Motor left_front  ;
extern Motor left_back   ;
extern Motor right_front ;
extern Motor right_back  ;
extern Motor intake_l    ;
extern Motor intake_r    ;
extern Motor tray        ;
extern Motor arm         ;

extern std::list<Motor> Motors ;

#endif