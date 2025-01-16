#include "Record.h"
//! kurucuda boş string atadık.
Record::Record() : fileName(""), file() {}
//! dosyayı açıp kapatma kısmı
bool Record::openFile() {
    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    return file.is_open();
}
//! dosya açıksa kapatır true döndürür.
bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}
//! alınan dosya adını set ediyoruz.
void Record::setFileName(const std::string &name) {
    fileName = name;
}
//! okuma yapan kısım
std::string Record::readLine() {
    std::string line;
    std::getline(file, line);
    return line;
}
//! yazma yapan kısım
bool Record::writeLine(const std::string &str) {
    if (file.is_open()) {
        file << str << std::endl;
        return true;
    }
    return false;
}
 //! operator fonksiyonları verileri dosyaya yazmak ve almak için kullanılır.
Record &Record::operator<<(const Record &record) {
    file << record.fileName;
    return *this;
}

Record &Record::operator>>(Record &record) {
    file >> record.fileName;
    return *this;
}
