/**
 * @file   encrypthion.h
 * @author Olcay Gündoğdu
 * @date   29.12.23
 * @brief Robot Operatorun isim, soyisim, erişim kodu ve durumunu belirleyen-tutan sınıf.
 *        Burada code'u şifreleyen ve şifre çözen fonksiyonlar eklenmiştir.
 *        Ayrıca operatorun bilgilerini dönen ve erişim kodunun doğruluğunu kontrol eden fonksiyonlar mevcuttur.
 */

#include <string>
#include "encryption.h"    //! Encyrption sınıfının fonksiyonlarının kullanılması için eklemesi yapıldı.
#include <cmath>
#include <iostream>


using namespace std;

class robotOperator{
private:
    string name;
    string surname;
    int accessCode;
    bool accessState;
    int encryptCode(int);
    int decryptCode(int);
    Encryption enc;
public:
    Encryption getEnc();
    bool checkAccessCode(int);
    void print();
    robotOperator(string, string, int ,bool);
};