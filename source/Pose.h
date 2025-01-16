
/**
 * @file Pose.h
 * @author =Mert Yenel
 * @date   28.12.23
 * @brief  Bu sınıf, robotun konum bilgilerini tutma ve yönetme görevine sahiptir. 
 * x,y koordinatları th ise açıyı temsil ediyor. operator overloading işlemleri ile rahatlıkla işlem yapılması
 * için düzenlenmiştir.
 */
#include<iostream>
#include<string>
using namespace std;
class Pose{
private:
    double x;
    double y;
    double th;
public:
    Pose(double _x = 0.0, double _y = 0.0, double _th = 0.0);
    double getX();
    void setX(double);
    double getY();
    void setY(double);
    double getTh();
    void setTh(double);
    bool operator==(const Pose&);
    Pose operator+(const Pose&);
    Pose operator-(const Pose&);
    Pose& operator+=(const Pose&);
    Pose& operator-=(const Pose&);
    bool operator<(const Pose&);
    Pose getPose();
    string getPoseValue();
    void setPose(double,double,double);
    double findDistanceTo(Pose);
    double findAngleTo(Pose);   
};