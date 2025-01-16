
#include "ForceSensor.h"

ForceSensor::ForceSensor() : Force(0.0) {
    sensorType = "Force";
} //!consturctor tanımlanması
void ForceSensor::updateSensor() { //!sensör değerlerini çeken fonksiyon tanımlanması
    Force = robotAPI->getFootForce(); //!sensör değerlerinin çekilmesi
}
double ForceSensor::getForce() //!sensör değerlerini dönen fonksiyon deklarasyonu
{
    return Force; //!sensör değeri döndürülür
}
bool ForceSensor::CheckFall() //!düşme durumunu kontrol eden fonksiyon tanımlanması
{
    //!Robot düştüğünde sensör değeri 4.76 oluyor. Bu değere eşit ve küçük değerler 'true' döndürür.
    if (Force <= 4.8)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string ForceSensor::getSensorType() { //! sensör tipi döndürülür. (bumber, sonar vs.)
    return sensorType;
}
string ForceSensor::getSensorValue() { //! sensör değeri söndürülür. (Newton & kg)
    stringstream ss;
    ss << Force;
    return ss.str();
}