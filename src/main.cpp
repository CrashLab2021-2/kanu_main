#include "ros/ros.h"
#include "motor.cpp"
#include "dynamixel.cpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int mode_flag=0;

int main(int argc, char *argv[]){
	ros::init(argc, argv, "kanu_main");
	ros::NodeHandle nh;
	
	ros::Publisher m_pub = nh.advertise<kanu_msgs::motor_msgs>("/motor_topic", 1);
	
	ros::ServiceClient d_client = nh.serviceClient<kanu_msgs::door>("door");
	ros::ServiceClient t_client = nh.serviceClient<kanu_msgs::tilt>("tilt");
	ros::ServiceClient dis_client = nh.serviceClient<kanu_msgs::dispenser>("dispenser");
	
	pwm_pub = &m_pub;
	
	door_client = &d_client;
	tilt_client = &t_client;
	dispenser_client = &dis_client;
	
	while(ros::ok())
	{
		switch(mode_flag)
		{
			case 0:
				motor_pub(50, 50, 5);
				ROS_INFO("RUN");
				break;
			case 1:
				//자율주행with사람찾기();
				break;
			case 2:
				//사람 따라가기();
				break;
			case 3:
				//사람과 상호작용();
				//상호작용 중에 사람이 도망갔다? -> 타이머로 해결(카메라, 초음파에서 사라짐)
				//명함 뽑아갔는지 안뽑아갔는지
				break;
			case 4:
				//초기화, 방금 만났던  사람과 안마주치기 위해 90도 돌고 case1로 돌아갈까?
			default:
				break;
		}
		ros::spinOnce();
	}
	
	return 0;
}
