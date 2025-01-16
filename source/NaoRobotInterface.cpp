#include "NaoRobotInterface.h"

NaoRobotInterface::NaoRobotInterface(){
    robotAPI = new NaoRobotAPI();
}
NaoRobotInterface::~NaoRobotInterface(){
    if (robotAPI != nullptr) {
       delete robotAPI;
    }
}
void NaoRobotInterface::turnLeft(){
    robotAPI->turnRobot(status+2);
}
void NaoRobotInterface::turnRight(){
    robotAPI->turnRobot(status+3);
}
void NaoRobotInterface::forward(){
    robotAPI->moveRobot(status);
}
void NaoRobotInterface::backward(){
    robotAPI->moveRobot(status+1);
}
void NaoRobotInterface::moveLeft(){
    robotAPI->moveRobot(status+2);
}
void NaoRobotInterface::moveRight(){
    robotAPI->moveRobot(status+3);
}
void NaoRobotInterface::stop(){
    robotAPI->stopRobot();
}
Pose NaoRobotInterface::getpose(){
    return *position;  
}
void NaoRobotInterface::print(){
    cout << "X: " << robotAPI->getX() << endl;
    cout << "Y: " << robotAPI->getY() << endl;
    cout << "Th: " << robotAPI->getTh() << endl;
}



 


 
   
   