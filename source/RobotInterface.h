/**
 * @file   RobotInterface.h
 * @author =Mert Yenel
 * @date   8.12.23
 * @brief  RobotInterface inheritance ile alt sınıfına bir arayüz sunuyor. 
 */
#include "Pose.h"
#include "SensorInterface.h"
#include<iostream>
#include<vector>
using namespace std;

class RobotInterface{
private:
    Pose* position;
    int status=0;
    vector<SensorInterface*> sensorList;
public:
    void virtual turnLeft()=0;
    void virtual turnRight()=0;
    void virtual forward()=0;
    void virtual backward()=0;
    void virtual moveLeft()=0;
    void virtual moveRight()=0;
    void virtual stop()=0;
    Pose virtual getPose()=0;
    void virtual print()=0;
    void virtual updateSensors()=0;
    void virtual addSensor(SensorInterface*)=0;
};