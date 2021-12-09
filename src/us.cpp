#ifndef US_CPP
#define US_CPP

#include "kanu_main/us.h"

void us1Callback(const std_msgs::Float32 &msg){
  us_1_dist = msg.data;
}

void us2Callback(const std_msgs::Float32 &msg){
  us_2_dist = msg.data;
}

void us3Callback(const std_msgs::Float32 &msg){
  us_3_dist = msg.data;
}

void us4Callback(const std_msgs::Float32 &msg){
  us_4_dist = msg.data;
}

#endif
