#ifndef MOTOR_H
#define MOTOR_H

#include "ros/ros.h"
#include "kanu_msgs/motor_msgs.h"

ros::Publisher *pwm_pub;

void motor_pub(int pwm_1, int pwm_2, float delay);
void stop(int current_pwm1, int current_pwm2, float delay);

#endif
