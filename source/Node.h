/**
 * @file   Node.h
 * @author =Mert Yenel
 * @date   29.12.23
 * @brief  Bu sınıf, Pose sınıfını kullanarak bir node nesnesi üretmeyi sağlıyor.
 * içeriğinde pose verilerini tutarak onları get set ve print edecek.
 */
#include "Pose.h"
#include<iostream>
using namespace std;

class Node {
private:
    Node* next;
    Pose pose;
public:
    Node(double poseX = 0.0, double poseY = 0.0, double poseTh = 0.0);
    Node* getNext() const; 
    Pose& getPose();  
    void setNext(Node* newNext);  
    void setPose(const Pose& newPose); 
    void print();
};
