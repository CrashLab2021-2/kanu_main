#ifndef MOTOR_CPP
#define MOTOR_CPP
#include "motor.h"

void motor_pub(int pwm_1, int pwm_2, float delay){
    kanu_msgs::motor_msgs motor_msg;
    motor_msg.pwm1 = pwm_1;
    motor_msg.pwm2 = pwm_2;
    pwm_pub->publish(motor_msg);
    ros::Duration(delay).sleep();
}

void stop(int current_pwm_1, int current_pwm_2, float delay){
    float set_pwm_1 = (float)current_pwm_1 / 10.0;
    float set_pwm_2 = (float)current_pwm_2 / 10.0;
    float set_time = delay / 10.0;
    for(int i{}; i < 10; i++){
        motor_pub(current_pwm_1 - (int)((i + 1) * set_pwm_1), current_pwm_2 - (int)((i + 1) * set_pwm_2), set_time);
    }
}

#endif