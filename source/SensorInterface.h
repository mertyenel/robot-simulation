/**
 * @file   SensorInterface.h
 * @author =Mert Yenel
 * @date   8.12.23
 * @brief  SensorInterface inheritance ile alt sınıflara  bir arayüz sunuyor.
 */
#include<iostream>
using namespace std;
class SensorInterface{
protected:
    string sensorType;
public:
    virtual void updateSensor()=0; //!pure virtual tanımladım hepsini
    virtual string getSensorType()=0;
    virtual string getSensorValue()=0;
};