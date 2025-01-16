#include <iostream>
#include "ForceSensor.h"

int main() {
    ForceSensor forceSensor;

    forceSensor.updateSensor();
    std::cout << "Sensör güncellendi.\n";

    double forceValue = forceSensor.getForce();
    std::cout << "Sensör değeri: " << forceValue << "\n";

    bool fallStatus = forceSensor.CheckFall();
    std::cout << "Düşme durumu: " << (fallStatus ? "true" : "false") << "\n";

    return 0;
}
