#ifndef GPS_CPP
#define GPS_CPP

#include "kanu_main/gps.h"


double msg_to_degree(double msg)
{
    double msg_rad, msg_deg, msg_min, msg_sec;
    msg_deg = int(msg/100);
    msg_min = msg - msg_deg*100;
    msg_sec = (msg_min - int(msg_min))*60;
    msg_min = int(msg_min);
    msg_deg = msg_deg + msg_min/60 + msg_sec/60/60;
    // msg_rad = msg_deg * M_PI/180;
    return msg_deg;
}

double Location::distance(Location& to)
{
    double distance, theta;
    theta = longitude - to.longitude;
    distance = sin(deg2rad(latitude))*sin(deg2rad(to.latitude)) + cos(deg2rad(latitude))*cos(deg2rad(to.latitude))*cos(deg2rad(theta));
    distance = acos(distance);
    distance = rad2deg(distance);
    distance = distance * 60 * 1.1515;
    distance = distance * 1609.344; // mile to meter
    return distance;
}

void GPS_Callback(const sensor_msgs::NavSatFix& msg)
{
    GPS = true;
    present_GPS = Location(msg_to_degree(msg.latitude), msg_to_degree(msg.longitude));
}
#endif
