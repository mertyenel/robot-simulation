#include <iostream>
#include "SonarSensor.h"

int main() {
    NaoRobotAPI robotAPI;
    
    SonarSensor sonarSensor(&robotAPI);

    sonarSensor.updateSensor();
    std::cout << "Sensör güncellendi.\n";

    for (int i = 0; i < 2; ++i) {
        double range = sonarSensor.getRange(i);
        std::cout << "Sonar sensöründen alınan uzaklık (" << i << "): " << range << "\n";
    }

    int maxIndex;
    double maxDistance = sonarSensor.getMax(maxIndex);
    std::cout << "Sonar sensöründen alınan maksimum uzaklık: " << maxDistance << " (Index: " << maxIndex << ")\n";

    int minIndex;
    double minDistance = sonarSensor.getMin(minIndex);
    std::cout << "Sonar sensöründen alınan minimum uzaklık: " << minDistance << " (Index: " << minIndex << ")\n";

    for (int i = 0; i < 2; ++i) {
        double range = sonarSensor[i];
        std::cout << "Sonar sensöründen alınan uzaklık (" << i << ") (Operator[]): " << range << "\n";
    }

    return 0;
}
