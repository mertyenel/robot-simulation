//! author= Selay Kocatüfek 28.12.23
#include "NaoRobotSensorInterface.h"
#include <iostream>
#include <sstream>
using namespace std;

class SonarSensor : public NaoRobotSensorInterface {
private:
	double ranges[2];	 
public:
	SonarSensor();
	~SonarSensor();
	double getRange(int);
	double getMax(int&);
	double getMin(int&);
	void updateSensor()override;
	double operator[](int);
	string getSensorType()override;
	string getSensorValue()override;
};

















