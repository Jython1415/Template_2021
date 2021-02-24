#ifndef _Debug_H_
#define _Debug_H_

#include "vex.h"
#include "pragma.h"
#include "controller.h"
#include "motor/class.h"

// other values
#define PRINT_VALUE_1 1
#define PRINT_VALUE_2 0
#define PRINT_VALUE_3 0
#define PRINT_VALUE_4 0
#define PRINT_VALUE_5 0

#define DEBUG_LOOP_DELAY 10

// for counting loop repetitions
extern int debug_i ;
extern int debug_count ;

// run every loop to increment the loop variable
void debug_updateVar () ;

// initial print function
void debug_print_initial ();

// final print function
void debug_print () ;

#endif