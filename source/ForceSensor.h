/**
 * @file   ForceSensor.h
 * @author =Ozan Çelikkol
 * @date   29.12.23
 * @brief Robotun ayak tabanlarında, her bir ayakta dörder tane olacak şekilde,
 * basınç sensörleri bulunmaktadır. Bu sensör verileri ölçülerek
 * robotun tabanının yer ile teması anlaşılır. Sensör verilerinin ortalama
 * değeri ile ilerlenecektir.
 */
#include "NaoRobotSensorInterface.h"
#include <iostream>
#include <string>
#include <sstream>

class ForceSensor : public NaoRobotSensorInterface { //!ForceSensor nesnesi tanımlanır.
private:
	double Force; //!basın sensör değişkeninin deklarasyonu
public:
	ForceSensor(); //!constuctor deklarasyonu
	void updateSensor()override;//!sensör değerlerini çeken fonksiyon deklarasyonu
	double getForce();//!sensör verilerini dönen fonksiyon deklarasyonu
	bool CheckFall();//!robotun düşme durumunu kontrol eden fonksiyon deklarasyonu
	string getSensorType()override; //!sensör tipini döndüren fonksiyon deklarasyonu
	string getSensorValue()override; //!sensör değerini döndüren fonksiyon deklarasyonu
};
