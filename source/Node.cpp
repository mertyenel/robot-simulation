#include "Node.h"
using namespace std;
#include<iostream>
Node::Node(double poseX, double poseY, double poseTh)
    : next(nullptr), pose(poseX, poseY, poseTh) {}

//! başlangıç olarak bir tane node nesnesi daha yaratıyor. next diye o yüzden veri yapısı kurarken bunu dikkate alarak
//! kurmaya çalıştım.
Node* Node::getNext() const {
    return next;
}

 Pose& Node::getPose()  {
    return pose;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}

void Node::setPose(const Pose& newPose) {
    pose = newPose;
} //! verileri print ediyor.
void Node::print(){
cout<<"X = "<<pose.getX()<<" Y = "<<pose.getY()<<" Th = "<<pose.getTh()<<endl;
}