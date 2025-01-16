#include <iostream>
#include "Record.h"

int main() {
    // Test default constructor
    Record record;
    record.setFileName("test_file.txt");

    // Test openFile
    if (record.openFile()) {
        std::cout << "Dosya başarıyla açıldı.\n";

        // Test writeLine
        record.writeLine("Bu bir test satırı.");

        // Test readLine
        std::string line = record.readLine();
        std::cout << "Okunan Satır: " << line << std::endl;

        // Test closeFile
        if (record.closeFile()) {
            std::cout << "Dosya başarıyla kapatıldı.\n";
        } else {
            std::cerr << "Dosya kapatma hatası!\n";
        }
    } else {
        std::cerr << "Dosya açma hatası!\n";
    }

    return 0;
}
