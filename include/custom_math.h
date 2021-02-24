#ifndef _custom_math_H__
#define _custom_math_H__

int math_sgn_f (double input) ;
int math_sgn_i (int input) ;

int math_restrict_i (int input, int lower_range, int upper_range) ;
double math_restrict_f (double input, double lower_range, double upper_range) ;

double math_abs_restrict_f (double input, double abs_lower_range, double abs_upper_range) ;

double math_map_f (double input, double range_1_low, double range_1_high , double range_2_low, double range_2_high) ;

#endif