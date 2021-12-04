#ifndef DYNAMIX_H
#define DYNAMIX_H

#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "kanu_msgs/tilt.h"
#include "kanu_msgs/door.h"
#include "kanu_msgs/dispenser.h"

ros::ServiceClient *door_client;
ros::ServiceClient *tilte_client;
ros::ServiceClient *dispenser_client;

kanu_msgs::door door_srv;
kanu_msgs::tilte tilte_srv;
kanu_msgs::dispenser dispenser_srv;

void openDoor();
void closeDoor();
void tilteUp();
void tilteDown();
void dispenser();

#endif 