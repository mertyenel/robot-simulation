#include "Path.h"
//! başlangıç olarak head ve taile nullptr ataması yaptım.
Path::Path(){
    head=nullptr;
    tail=nullptr;
    number=0;
}
Path::~Path() {
    Node* current = head; //! burada dinamik olarak oluşan yapıları yıkıcı ile sildim.
    while (current != nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}
//! yeni bir node eklemek için bu fonksiyonu yaptım. listenin sonuna ekliyor.
void Path::addPos(Pose& obj) {
    number++;
    if (head == nullptr) {
        head = new Node(obj.getX(), obj.getY(), obj.getTh());
        tail = head;
    } else {
        Node* newNode = new Node(obj.getX(), obj.getY(), obj.getTh());
        tail->setNext(newNode);
        tail = newNode;
    }
}
//! burada tek tek nodeların bilgisini veriyor.
void Path::print(){
    Node* current = head;
    while (current != nullptr) {
        current->print();
        current = current->getNext();
    }
}
//! ulaşılmak istenilen node a giderek print ediyor.
   void Path::operator[](int sayi){
    if (sayi >= 0 && sayi < number) {
        Node* current = head;
        for (int i = 0; i < sayi; ++i) {
            current = current->getNext();
        }
        current->print();
    }
}

    Pose Path::getPos(int sayi){
    if (sayi >= 0 && sayi < number) {
        Node* current = head;
        for (int i = 0; i < sayi; ++i) {
            current = current->getNext();
        }
        return current->getPose();
    }
    return Pose(); 
}
     int Path::getSize(){
        return number;
    }
    bool Path::removePos(int sayi) {
    if (sayi >= 0 && sayi < number) {
        Node* beforeCurrent = nullptr;
        Node* current = head;
        for (int i = 0; i < sayi; ++i) {
            beforeCurrent = current;
            current = current->getNext();
        }
        if (beforeCurrent == nullptr) {
            head = current->getNext();
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            beforeCurrent->setNext(current->getNext());
            if (current == tail) {
                tail = beforeCurrent;
            }
        }
        delete current;
        number--;
        return true;
    }
    return false;
}
    bool Path::insertPos(int sayi,Pose& obj) {
    if (sayi >= 0 && sayi <= number) {
        if (sayi == 0) {
            Node* newNode = new Node(obj.getX(), obj.getY(), obj.getTh());
            newNode->setNext(head);
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else {
            Node* beforeCurrent = nullptr;
            Node* current = head;
            for (int i = 0; i < sayi; ++i) {
                beforeCurrent = current;
                current = current->getNext();
            }
            Node* newNode = new Node(obj.getX(), obj.getY(), obj.getTh());
            beforeCurrent->setNext(newNode);
            newNode->setNext(current);
            if (current == nullptr) {
                tail = newNode;
            }
        }
        number++;
        return true;
    }
    return false;
}
    std::ostream& Path::operator<<(std::ostream& out) const {
    Node* current = head;
    while (current != nullptr) {
        out << "(" << current->getPose().getX() << ", " << current->getPose().getY() << ", " << current->getPose().getTh() << ") ";
        current = current->getNext();
    }
    out << std::endl;
    return out;
 } 
 //!  Klavyeden girilen konumu listenin sonuna ekler.
   std::istream& Path::operator>>(std::istream& in) {
    double x, y, th;
    in >> x >> y >> th;
    Pose obj(x, y, th);
    addPos(obj);
    return in;
}