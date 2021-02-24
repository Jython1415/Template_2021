#include "vex.h"
#include "custom_math.h"

int math_sgn_f (double input)
{
  if (input > 0)
  {
    return 1;
  }
  else if (input < 0)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int math_sgn_i (int input)
{
  if (input > 0)
  {
    return 1;
  }
  else if (input < 0)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int math_restrict_i (int input, int lower_range, int upper_range)
{
  if (input > upper_range)
  {
    return upper_range;
  }
  else if (input < lower_range)
  {
    return lower_range;
  }
  else
  {
    return input;
  }
}

double math_restrict_f (double input, double lower_range, double upper_range)
{
  if (input > upper_range)
  {
    return upper_range;
  }
  else if (input < lower_range)
  {
    return lower_range;
  }
  else
  {
    return input;
  }
}

double math_abs_restrict_f (double input, double abs_lower_range, double abs_upper_range)
{
  if (fabs(input) > abs_upper_range)
  {
    return math_sgn_f(input) * abs_upper_range;
  }
  else if (fabs(input) < abs_lower_range)
  {
    return math_sgn_f(input) * abs_lower_range;
  }
  else
  {
    return input;
  }
}

double math_map_f (double input, double range_1_low, double range_1_high , double range_2_low, double range_2_high)
{
  return ((input-(range_1_low+range_1_high)/2)/(range_1_low-(range_1_low+range_1_high)/2) * (range_2_low - (range_2_low+range_2_high)/2) + (range_2_low+range_2_high)/2) ;
}