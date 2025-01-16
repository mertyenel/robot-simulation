// Ozan Çelikkol - Selay Kocatüfek - Olcay Gündoğdu - Mert Yenel

#include <iostream>
#include "NaoRobotAPI.h"
#include "RobotControl.h"
#include "BumperSensor.h"
#include "SonarSensor.h"
#include "ForceSensor.h"



class MainMenu {
public:
    void showMenu() {
        int choice;
        do {
            std::cout << "Main Menu\n";
            std::cout << "1. Connection 1\n";
            std::cout << "2. Motion 2\n";
            std::cout << "3. Sensor 3\n";
            std::cout << "4. Quit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            otherMenus(choice);

        } while (choice != 4);
    }

private:
    SonarSensor sonar;

    NaoRobotAPI* robotAPI;
    void otherMenus(int choice) {
        switch (choice) {
            case 1:
                int choice;
                do {
                    std::cout << "Connection Menu\n";
                    std::cout << "1. Connect Robot 1\n";
                    std::cout << "2. Disconnect Robot 2\n";
                    std::cout << "3. Back 3\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        std::cout << "Connected Robot.";
                        robotAPI->connect();
                        break;
                    case 2:
                        std::cout << "Disonnected Robot.";
                        robotAPI->disconnect();
                        break;
                    case 3:
                        showMenu();
                        break;
                    default:
                        std::cout << "Please try again.\n";
                        break;
                    }
                } while (choice != 3);
                break;
            case 2:
                int choice;
                do {
                    std::cout << "Moiton Menu\n";
                    std::cout << "1. Move Robot 1\n";
                    std::cout << "2. Safe Move Robot 2\n";
                    std::cout << "3. Turn Left 3\n";
                    std::cout << "4. Turn Right 4\n";
                    std::cout << "5. Forward 5\n";
                    std::cout << "6. Move Distance 6\n";
                    std::cout << "7. Close Wall 7\n";
                    std::cout << "8. Quit 8\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;

                    char inp;
                    switch (choice)
                    {
                    case 1:
                        std::cout << "Left = L, Right= R";
                        std::cin >> inp;
                        if (inp == 'L') {
                            robotAPI->moveRobot(LEFT);
                        } else if (inp == 'R') {
                            robotAPI->moveRobot(RIGHT);
                        } 
                        break;
                    case 2:
                        bool inp;
                        std::cout << "Left = L, Right= R";
                        std::cin >> inp;
                        if (BumperSensor::checkTouch) {
                            std::cout << "Obstacle detected.";
                        } else {
                            std::cout << "Left = L, Right= R";
                            std::cin >> inp;
                            if (inp == 'L') {
                                robotAPI->moveRobot(LEFT);
                            } else if (inp == 'R') {
                                robotAPI->moveRobot(RIGHT);
                            }
                        }
                        break;
                    case 3:
                        robotAPI->turnRobot(LEFT);
                        break;
                    case 4:
                        robotAPI->turnRobot(RIGHT);
                        break;
                    case 5:
                        robotAPI->moveRobot(FORWARD);
                        break;
                    case 6:
                        
                        if (sonar.getRange(0) < 2.5 || sonar.getRange(1) < 2.5) {
                            robotAPI->stopRobot();
                        } else robotAPI->moveRobot(FORWARD);
                        break;
                    case 7:
                        if (sonar.getRange(0) < 0.5 || sonar.getRange(1) < 0.5) {
                            robotAPI->stopRobot();
                        } else robotAPI->moveRobot(FORWARD);
                        break;
                    case 8:
                        std::cout << "Disonnected Robot.";
                        robotAPI->disconnect();
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                } while (choice != 8);
                break;
            case 3:
                std::cout << "Sonar Sensor: " << SonarSensor::getRange << "\n";
                std::cout << "Bumper Sensor: " << BumperSensor::getState << "\n";
                std::cout << "Force Sensor: " << ForceSensor::getForce << "\n";
                showMenu();
                break;
            case 4:
                std::cout << "Exiting the program\n";
                break;
            default:
                std::cout << "Please try again.\n";
                break;
        }
    }
};

int main() {

    
    MainMenu::showMenu;

    return 0;
}
