#ifndef GPS_H
#define GPS_H

#include <cmath>
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>


class Location{
private:
    double latitude;
    double longitude;
    double ERR = 0.5; // 0.5m 이내
    double deg2rad(double deg){return (deg*M_PI/180.0);}
    double rad2deg(double rad){return (rad*180.0/M_PI);}
    double msg_to_degree(double msg);

public:
    Location(){};
    Location(double latitude_, double longitude_) : latitude(latitude_), longitude(longitude_)
    {  }
    double distance(Location& to);
    bool operator == (Location& ref)
    {
        if(this->distance(ref)<ERR) return true;
        else return false;
    }
};

Location HackJung(37.29694, 126.83529);
Location point[6] = {Location(37.297117, 126.835444),
                     Location(37.297060, 126.835395), };
Location present_GPS;
#endif
