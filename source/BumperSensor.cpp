
#include "BumperSensor.h"

BumperSensor::BumperSensor() {
    for (int i = 0; i < 4; ++i) { //!constructor tanımlanması
        states[i] = false; //! tüm değerlere 'false' tanımlanır
    }
    sensorType = "Bumper"; //!sensör tipi atanır
}
BumperSensor::~BumperSensor() { //!destructor tanımlanması
}
bool BumperSensor::getState(int index) { //!sensör durumlarını dönen fonksiyon tanımlanması
    if (index >= 0 && index < 4) {
        return states[index]; //!sensör durumları döndürülür
    }
    else {
        cout<<"Hatalı index";
        return false; //!geçersiz sensör seçimi uyarı verir
    }
}
void BumperSensor::updateSensor() { //!sensör durumlarının sensörlerle eşleştirilmesi
    bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
    robotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);

    //!sensör tanımlamaları
    states[0] = leftFoot_left; 
    states[1] = leftFoot_right;
    states[2] = rightFoot_left;
    states[3] = rightFoot_right;
}
bool BumperSensor::checkTouch() { //!engel ile temas fonksiyon tanımlanması
    for (int j = 0; j < 4; ++j) {
        if (states[j]) {
            return true; //!temas durumunda 'true' döndürülür
        }
    }
    return false; //! temas yoksa 'false' döndürülür.
}
string BumperSensor::getSensorType(){ //! sensör tipi döndürülür. (bumber, sonra vs.)
  
    return sensorType;
}
string BumperSensor::getSensorValue(){ //! ayaklardaki sensör değerleri sırasıyla döndürülür.
    stringstream ss;
    ss << states[0] << " " << states[1]<< " " << states[2] << " " << states[3];
    return ss.str();
}
