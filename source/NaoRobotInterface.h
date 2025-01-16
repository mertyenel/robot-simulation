#include<iostream>
#include "NaoRobotAPI.h"
#include "RobotInterface.h"
using namespace std;

class NaoRobotInterface : public RobotInterface{
private:
    NaoRobotAPI* robotAPI;
public:
    NaoRobotInterface();
    ~NaoRobotInterface();
    void turnLeft();
    void turnRight();
    void forward();
    void backward();
    void moveLeft();
    void moveRight();
    void stop();
    Pose getpose();
    void print();
};