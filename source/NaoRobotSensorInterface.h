#include "NaoRobotAPI.h"
#include "SensorInterface.h"
class NaoRobotSensorInterface :public SensorInterface {
protected:
    NaoRobotAPI* robotAPI;
public:
    NaoRobotSensorInterface();
    ~NaoRobotSensorInterface();
};