/**
 * @file   Record.h
 * @author =Mert Yenel
 * @date   28.12.23
 * @brief  Record sınıfı adı üstünde file adı alıp okuma yazma ekleme modlarında açılıp 
 *          ona göre işlem yapmak için tasarlanmıştır.
 */
#include <iostream>
#include <fstream>
#include <string>

class Record {
private:
    std::string fileName;
    std::fstream file;

public:
    Record();

    bool openFile();
    bool closeFile();
    void setFileName(const std::string &name);
    std::string readLine();
    bool writeLine(const std::string &str);
    Record &operator<<(const Record &record);
    Record &operator>>(Record &record);
};

