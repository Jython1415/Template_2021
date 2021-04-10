#ifndef _pragma_H_
#define _pragma_H_

#include "vex.h"
#include "motor/class.h"

extern vex::brain             Brain ;
extern vex::competition Competition ;

extern vex::controller Controller_1 ;

// extern Motor left_front  ;
// extern Motor left_back   ;
// extern Motor right_front ;
// extern Motor right_back  ;
extern Motor_v2 tm;
extern Motor_v2 *temp_1;
void initialize_pragma ();

// extern std::list<Motor_v2> Motors ;
extern Motor_v2 * Motors ;

#endif