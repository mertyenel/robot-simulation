    #include "Pose.h"
    #include <cmath>
    Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}
    double Pose::getX(){    //! bazı get, set işlemleri var. üye verileri alıyoruz veya set ediyoruz.
        return x;
    }
    void Pose::setX(double number){
        x = number;
    }
    double Pose::getY(){
        return y;
    }
    void Pose::setY(double number){
        y = number;
    }
    double Pose::getTh(){
        return th;
    }
    void Pose::setTh(double number){
        th = number;
    }
 /**
  * @brief burada operator olarak == + - += -= < vb kullandım ki işlemlerimiz daha kolay yapılsın diye. bazıları nesnenin
  * kendisini, bazıları ise bool döndürüyor.
 */
    bool Pose::operator==(const Pose& obj){
        return((*this).x == obj.x && (*this).y == obj.y && (*this).th == obj.th);
    }
    Pose Pose::operator+(const Pose& obj){
        Pose tmp;
        tmp.x = (*this).x + obj.x;
        tmp.y = (*this).y + obj.y;
        tmp.th = (*this).th + obj.th;
        return tmp;
    }
    Pose Pose::operator-(const Pose& obj){
        Pose tmp;
        tmp.x = (*this).x - obj.x;
        tmp.y = (*this).y - obj.y;
        tmp.th = (*this).th - obj.th;
        return tmp;
    }
    Pose& Pose::operator+=(const Pose& obj){
        this->x += obj.x;
        this->y += obj.y;
        this->th += obj.th;
        return *this;
    }
    Pose& Pose::operator-=(const Pose& obj){
        this->x -= obj.x;
        this->y -= obj.y;
        this->th -= obj.th;
        return *this;
    }
    bool Pose::operator<(const Pose& obj){
        return (this->x < obj.x) && (this->y < obj.y) && (this->th < obj.th);
    }
    Pose Pose::getPose(){
       return *this;
    }
    string Pose::getPoseValue(){
        string hold = "";
        hold += to_string(x);
        hold += " ";
        hold += to_string(y);
        hold += " ";
        hold += to_string(th);
        return hold;
    }
    void Pose::setPose(double _x, double _y, double _th){
        x = _x;
        y = _y;
        th = _th;
    }
    //! burada mesafeyi bulmak için matematikteki iki nokta arası en kısa mesafe formülünü kullandım.
    double Pose::findDistanceTo(Pose obj){
       return sqrt(pow(this->x - obj.x, 2) + pow(this->y - obj.y, 2));
    }
    //! açıyı bulmak içinde atan2 diye çift parametre alan bir fonksiyon kullandım.
    double Pose::findAngleTo(Pose obj){
        double _x = obj.x - this->x;
        double _y = obj.y - this->y;
        double angle = atan2(_y, _x);
        return angle;
    }
    


