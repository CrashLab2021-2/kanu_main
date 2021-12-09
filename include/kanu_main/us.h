#ifndef US_H
#define US_H

#include "ros/ros.h"
#include "std_msgs/Float32.h"

float us_1_dist = -1;
float us_2_dist = -1;
float us_3_dist = -1;
float us_4_dist = -1;

void us1Callback(const std_msgs::Float32 &msg);
void us2Callback(const std_msgs::Float32 &msg);
void us3Callback(const std_msgs::Float32 &msg);
void us4Callback(const std_msgs::Float32 &msg);

#endif
