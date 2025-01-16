#include <iostream>
#include "BumperSensor.h"

int main() {
    BumperSensor bumperSensor;

    for (int i = 0; i < 4; ++i) {
        bool state = bumperSensor.getState(i);
        std::cout << "Sensör " << i << " durumu: " << (state ? "true" : "false") << "\n";
    }

    bumperSensor.updateSensor();
    std::cout << "Sensörler güncellendi.\n";

    bool touch = bumperSensor.checkTouch();
    std::cout << "Engel teması: " << (touch ? "true" : "false") << "\n";

    return 0;
}
