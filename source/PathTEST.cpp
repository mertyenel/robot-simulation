#include <iostream>
#include "Path.h"

int main() {
    Path yol;

    Pose poz1(1.0, 2.0, 45.0);
    Pose poz2(3.0, 4.0, 90.0);
    yol.addPos(poz1);
    yol.addPos(poz2);

    std::cout << "Yol:\n";
    yol.print();

    std::cout << "Index 0'daki Pose: ";
    yol[0];

    Pose alinanPoz = yol.getPos(1);
    std::cout << "Index 1'deki Pose: (" << alinanPoz.getX() << ", " << alinanPoz.getY() << ", " << alinanPoz.getTh() << ")\n";

    if (yol.removePos(0)) {
        std::cout << "Index 0'daki Pose silindi.\n";
        std::cout << "Güncellenmiş Yol:\n";
        yol.print();
    } else {
        std::cerr << "Index 0'daki Pose silinemedi.\n";
    }

    Pose poz3(5.0, 6.0, 135.0);
    if (yol.insertPos(1, poz3)) {
        std::cout << "Index 1'e Pose eklendi.\n";
        std::cout << "Güncellenmiş Yol:\n";
        yol.print();
    } else {
        std::cerr << "Index 1'e Pose eklenemedi.\n";
    }

    std::cout << "Ostream ile Yol: " << yol << "\n";
    std::cout << "Bir Pose girin (x y th formatında): ";
    std::cin >> yol;

    return 0;
}
