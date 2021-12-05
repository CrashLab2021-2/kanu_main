#include "ros/ros.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;
int mode_flag=0;

// for GPS
struct Location{
private:
	double theta;
	double dist;
public:
	double latitude; // 위도
	double longitude; // 경도
} library;

// for init in case 1
bool node1_on = fasle;
bool node2_on = fasle;
void node1_on_Callback(const::kanu_msgs::node_on& msg) { node1_on = msg.node_on; }
void node2_on_Callback(const::kanu_msgs::node_on& msg) { node2_on = msg.node_on; }


int main(int argc, char *argv[]){
	ros::init(argc, argv, "kanu_main");
	ros::NodeHandle nh;

	ros::Publisher motor_pub = nh.advertise<kanu_msgs::motor_msgs>("motor_set", 1);
	ros::Publisher dynamixel_pub = nh.advertise<kanum_msgs::servo_msgs>("servo_set", 1);
	ros::Publisher ui_pub = nh.advertise<std_msgs::String>("/chatter", 1);

    ros::Subscriber node1 = nh.subscribe("node1_on",1,node1_on_Callback);
	ros::Subscriber node2 = nh.subscribe("node2_on",1,node2_on_Callback);
	// motor, imu, gps, ultrasonuc, camera(AI)

	while(ros::ok()){
		switch(mode_flag)
		{
			case 0:
				void setup()
				{
					if(node1_on && node2_on && ...){
						gps_imu_init();
						ui_pub.publish(ui, 초기 화면);
						ROS_INFO("Node init");
						mode_flag = 1;
					}
					motor_pub.publish(motor_pub : 0);
					dynamixel_pub.publish(초기 위치로 pub);
				}
				bool gps_imu_init() // 현재 위치와 방향을 상대좌표계에 초기화(학정 위도, 경도는 const로..)
				{
					// do init something
					return true;
				}
				break;
			case 1:
				void find_person()
				{
					AI에서 사람을 찾았는지 topic 확인 -> AI에서 사람을 잡았는지 못잡았는지 토픽을 계속 보내
					if(사람 찾음?){
						mode_flag = 다음으로
					}
					else{
						autonomous();
					}
				}
				void autonomous()
				{
					float 로봇과 학정사이의 거리()
					if(로봇과 학정 사이의 거리가 영역 안이면)
						void 포인트로 이동(){
							if(포인트로의 방향이 맞는지 확인(IMU))
							{//맞으면
								if(안전거리 이상인가)
									right_pwm = left_pwm = pwm;
									Motor_controller(1, true, right_pwm);
									Motor_controller(2, true, left_pwm);
								else
									right_pwm = left_pwm = 0;
									Motor_controller(1, true, right_pwm);
									Motor_controller(2, true, left_pwm);
							}
							else{
								int pwm=100;
								if(목표 포인트보다 오른쪽을 보고 있음){//오른쪽 출력이 더 쎄야 수평이 맞음 -> 왼쪽 출력을 약하게
									left_pwm = pwm - 10;
								}
								else{
									right_pwm = pwm - 10;
								}
							}
							
						}
						if( 로봇 위치 == 포인트)
							랜덤 포인터 선택();
							// int 랜덤 포인트 선택(){ 포인트 = 포인트 랜덤 선택 }
					else
						로봇을 중심으로 이동
				}
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
