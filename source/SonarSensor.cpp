//! author= Selay Kocatüfek 28.12.23

#include "SonarSensor.h"

//!constructer
SonarSensor::SonarSensor() :ranges{ 0.0, 0.0 } {
    sensorType= "Sonar";
}
SonarSensor::~SonarSensor() {
}

//!uzaklık bilgisi aldığımız sonar sensörden gelen aralık
double SonarSensor::getRange(int index) {
    return ranges[index];
}

//!uzaklık bilgisi aldığımız sonar sensörden gelen max değer
double SonarSensor::getMax(int &maxIndex) {
    double maxDistance = ranges[0];
    maxIndex = 0;

    for (int i = 1; i < 2; ++i) {
        if (ranges[i] > maxDistance) {
            maxDistance = ranges[i];
            maxIndex = i;
        }
    }
    return maxDistance;
}

//!uzaklık bilgisi aldığımız sonar sensörden gelen min değer
double SonarSensor::getMin(int &minIndex) {
    double minDistance = ranges[0];
    minIndex = 0;

    for (int i = 1; i < 2; ++i) {
        if (ranges[i] < minDistance) {
            minDistance = ranges[i];
            minIndex = i;
        }
    }

    return minDistance;
}

//!uzaklık bilgisi aldığımız sonar sensörden gelen değerlerin güncellenmesi
void SonarSensor::updateSensor(){
    robotAPI->getSonarRange(ranges[0], ranges[1]);
}

double SonarSensor::operator[](int index){
    return ranges[index];
}
string SonarSensor::getSensorType(){
    return sensorType;
}
string SonarSensor::getSensorValue(){
    stringstream ss;
    ss << ranges[0] << " " << ranges[1];
    return ss.str();
}
       