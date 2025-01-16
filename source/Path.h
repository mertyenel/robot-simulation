/**
 * @file Path.h
 * @author =Mert Yenel
 * @date   29.12.23
 * @brief  Bu sınıf, Pose ve node sınıfları ile ilişkili o yüzden o sınıfları yazdıktan sonra
 *         bu sınıfa geçtim. Amacı ise  Linked list formunda yol planını yönetmeyi sağlayan sınıftır.
 *         bir veri yapısı oluşturdum. onun üzerinden işlemler yaptım.
 */
#include "Pose.h"
#include "Node.h"
#include<iostream>
#include<list>
using namespace std;
class Path{
private:
    Node* tail;
    Node* head;
    int number;
public:
    Path();
    ~Path();
    void addPos(Pose&);
    void print();
    void operator[](int);
    Pose getPos(int);
    bool removePos(int);
    bool insertPos(int,Pose&);
    int getSize();
    std::ostream& operator<<(std::ostream&) const;
    std::istream& operator>> (std::istream&);
    };