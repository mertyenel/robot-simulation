/**
 * @file   encrypthion.cpp
 * @author Olcay Gündoğdu
 * @date   29.12.23
 * @brief Robot operatörünün girdiği code'un şifrelenmesi ve bu şifrenin çözülmesini
 *        sağlayan sınıflar bu sınıf altında yapılmıltır.
 */

#include "encryption.h"


int Encryption::encryption(int code) {
    int digit1 = (code + 7) % 10;            //! digit1-4, girilen 4 basamaklı bir kodun her bir basamağına ilgili şifreleme adımlarını
    int digit2 = ((code / 10) + 7) % 10;
    int digit3 = ((code / 100) + 7) % 10;
    int digit4 = ((code / 1000) + 7) % 10;
    int encryptedCode = digit2 * 1000 + digit1 * 100 + digit4 * 10 + digit3; //! 4 basamaklı şifrelenmiş kodun oluşturulması

    cout << "Code: " << code << endl;     //! Asıl Kodun ekrana bastırılması
    cout << "Cryp Code: " << encryptedCode << endl;  //! Şifrelenmiş Kodun ekrana bastırılması

    return encryptedCode;  //! Şifrelenmiş Kodun return edilmesi
}
int Encryption::decryption(int code) {
    int digit1 = (code % 10 + 3) % 10;  
    int digit2 = ((code / 10) % 10 + 3) % 10;
    int digit3 = ((code / 100) % 10 + 3) % 10;
    int digit4 = (code / 1000 + 3) % 10;

    return digit2 * 1000 + digit1 * 100 + digit4 * 10 + digit3; //! Şifresi çözülmüş kodun return edilmesi
}