/**
 * @file   RobotControl.h
 * @author =Selay Kocatüfek 
 * @date   09.01.2024
 * @brief  Robot kontrol faaliyetlerini içeriyor.
 */
#include "Pose.h"
#include "Path.h"
#include "Record.h"
#include "robotOperator.h"
#include "SensorInterface.h"
#include "NaoRobotInterface.h"
#include<iostream>
class RobotControl{
private:
    bool control=false;
    Pose* position;
    Path path;
    Record rec;
    robotOperator robotOp;
    list<SensorInterface*>sensorList;
    NaoRobotInterface naoRobotINT;
public:
	RobotControl();  
    ~RobotControl(); 
    void turnLeft();
    void turnRight();
    void forward();
    void print();
    void backward();
    Pose getPose();
    void moveLeft();
    void moveRight();
    void stop();
    bool addToPath();
    void clearPath();
    bool recordPathToFile();
    bool openAccess(int);
    bool closeAccess(int);
    bool recordSensor(string);
    void printSensor(string);
    void addSensor(SensorInterface*);
};