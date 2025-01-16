#include <iostream>
#include "encryption.h"

int main() {
    Encryption encryption;

    int originalCode = 1234;
    int encryptedCode = encryption.encryption(originalCode);
    std::cout << "Şifrelenmiş kod: " << encryptedCode << "\n";

    int decryptedCode = encryption.decryption(encryptedCode);
    std::cout << "Şifresi çözülmüş kod: " << decryptedCode << "\n";

    return 0;
}
