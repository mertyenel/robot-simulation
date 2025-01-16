/**
 * @file   BumperSensor.h
 * @author =Ozan Çelikkol
 * @date   29.12.23
 * @brief Robotun her iki ayağında içe ve dışa dönük olacak şekilde
 *	ikişer adet sensör vardır. Normal değeri 'false' olan bu
 *	sensörler, engel ile temasta 'true' döndürür. Sensör bilgileri
 *	'NaoRobotAPI'den alınır.
 */
#include <iostream>
#include <sstream>
#include "NaoRobotSensorInterface.h"

using namespace std;

class BumperSensor: public NaoRobotSensorInterface {
private:
	bool states[4]; //!Sensör durumlarını barındıran array deklarasyon.
public:
	BumperSensor();	//!constructer deklarasyon
	~BumperSensor(); //!destructor deklarasyon
	bool getState(int); //!sensör durumlarını döndüren fonksiyon deklarasyon
	void updateSensor()override; //!sensör atamalarını güncelleyen fonksiyon deklarasyon
	bool checkTouch(); //!engel temasını kontrol fonksiyon deklarasyon
	string getSensorType()override; //!sensör tipini döndüren fonksiyon deklarasyon
	string getSensorValue()override; //!sensör değerlerini döndüren fonksiyon deklarasyon
};