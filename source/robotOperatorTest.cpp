#include "robotOperator.h"
#include <iostream>

int main() {
    // Test robotOperator constructor and print function
    robotOperator operator1("John", "Doe", 123, true);
    operator1.print();
    // Test encryption and decryption functions
    int originalCode = 456;
    int encryptedCode = operator1.getEnc().encryption(originalCode);
    int decryptedCode = operator1.getEnc().decryption(encryptedCode);

    std::cout << "Original Code: " << originalCode << std::endl;
    std::cout << "Encrypted Code: " << encryptedCode << std::endl;
    std::cout << "Decrypted Code: " << decryptedCode << std::endl;

    // Test checkAccessCode function
    int accessCodeToCheck = 789;
    std::cout << "Checking Access Code: " << accessCodeToCheck << std::endl;
    if (operator1.checkAccessCode(accessCodeToCheck)) {
        std::cout << "Access granted!" << std::endl;
    } else {
        std::cout << "Access denied!" << std::endl;
    }

    return 0;
}
