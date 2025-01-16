#include "NaoRobotSensorInterface.h"

NaoRobotSensorInterface::NaoRobotSensorInterface(){
   robotAPI = new NaoRobotAPI();
}

NaoRobotSensorInterface::~NaoRobotSensorInterface(){
if (robotAPI != nullptr) {
        delete robotAPI;
        robotAPI = nullptr;
    }
}