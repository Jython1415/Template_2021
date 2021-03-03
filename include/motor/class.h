#ifndef _motor_class_H_
#define _motor_class_H_

#include "vex.h"
#include "custom_math.h"

#define DEFAULT_SLEW_RATE 6

// 1 is velocity, 0 is voltage
#define MOTORS_POWER_MODE 0

// 0 is simple, 1 is slew
#define L_F_UPDATE_VARS_MODE      1
#define L_B_UPDATE_VARS_MODE      1
#define R_F_UPDATE_VARS_MODE      1
#define R_B_UPDATE_VARS_MODE      1
#define INTAKE_L_UPDATE_VARS_MODE 0
#define INTAKE_R_UPDATE_VARS_MODE 0
#define TILTER_UPDATE_VARS_MODE   0

class Motor: public vex::motor {
  public:
  // protected: // ===================================================================================
    std::string name;
    int brake_type; // -1 is vel ctrl, 0 is brake, 1 is coast, 2 is hold
    bool update_vars_mode; // 0 is direct, 1 is slew
    bool update_power_mode; // 0 is velocity, 1 is voltage
    bool print_actual_power_bool, print_target_power_bool, print_rotation_bool, print_rotation_change_bool;
    int target_power, actual_power;
    double rotation_current, rotation_prev, rotation_change, rotation_initial;
    int slew_rate;
  // public: // ======================================================================================
    void set_target (int input) ;

    // update functions ===========================================================================
    void update_vars_direct () ;
    void update_vars_slew () ;
    void update_vars () ;
    void update_power_vel () ;
    void update_power_vol () ;
    void update_power () ;
    void update_rotation () ;
    void update_rotation_prev () ;
    void update_rotation_change () ;
    void update_rotation_vars () ;
    void update_brake_type () ;

    // reset rotation =============================================================================
    void rotation_reset () ;

    // print functions ============================================================================
    void print_actual_power    () ;
    void print_target_power    () ;
    void print_rotation        () ;
    void print_rotation_change () ;
    // print initial functions ====================================================================
    void print_initial_actual_power    () ;
    void print_initial_target_power    () ;
    void print_initial_rotation        () ;
    void print_initial_rotation_change () ;

    // getter functions ===========================================================================
    int    actual_power_get () ;
    int    target_power_get () ;

    double rotation_get        () ;
    double rotation_prev_get   () ;
    double rotation_change_get () ;

    // setter functions ===========================================================================
    void slew_rate_set (int input_rate) ;
    void update_power_mode_set (bool input_bool) ;

    // contructor =================================================================================
    Motor (std::string name_input, int index, bool reverse, int brake_type_input, bool update_vars_mode_input, bool update_power_mode_input, bool print_rotation_input, bool print_actual_power_input, bool print_target_power_input, bool print_rotation_change_input) ;
};

#endif