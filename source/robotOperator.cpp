//! author= Olcay Gündoğdu - 503020230006 - 29/12/2023

#include "robotOperator.h"


robotOperator::robotOperator(string _name, string _surname, int _accessCode, bool _accessState) {
    name = _name;                                  //! Constructor, sınıf verilerinin atanması
    surname = _surname;
    accessCode = encryptCode(_accessCode); //! şifrelenmiş verinin tutulması
    accessState = _accessState;
    };

void robotOperator::print() {
    cout <<"Operator Adi: " << name << "Operator Soyadi: " << surname << "Erisim Durumu: " << accessState << endl;  //! Operatör bilgilerinin ekrana basılması
}

int robotOperator::encryptCode(int code) {
    int encode = enc.encryption(code);  //! Kodun şifrelenmesi için Encryption sınıfının encryption fonksiyonunun kullanılması
    return encode;
}

int robotOperator::decryptCode(int code) {
    int decode = enc.decryption(code);          //! Kodun şifresinin çözülmesi için Encryption sınıfının decryption fonksiyonunun kullanılması
    return decode;
}

bool robotOperator::checkAccessCode(int code) {
    if (code == accessCode) return true;    //! tutulan şifrelenmiş kodun (accessCode) verilen kod ile kıyaslanması. Eşleşme sağlandıysa true, sağlanmadıysa false döner.
    else return false;
}
Encryption robotOperator::getEnc(){
        return enc;
    }
