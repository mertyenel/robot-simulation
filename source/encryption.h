/**
 * @file   encrypthion.h
 * @author Olcay Gündoğdu
 * @date   29.12.23
 * @brief Robot operatörünün girdiği code'un şifrelenmesi ve bu şifrenin çözülmesini
 *        sağlayan sınıflar bu sınıf altında yapılmıltır.
 */

#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Encryption{
public:
    int encryption(int);
    int decryption(int);
};