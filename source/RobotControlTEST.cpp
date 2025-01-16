#include "RobotControl.h"

int main() {
    RobotControl robot;

    std::cout << "Turning left..." << std::endl;
    robot.turnLeft();
    robot.print();

    std::cout << "Turning right..." << std::endl;
    robot.turnRight();
    robot.print();

    std::cout << "Moving forward..." << std::endl;
    robot.forward();
    robot.print();

    std::cout << "Moving backward..." << std::endl;
    robot.backward();
    robot.print();

    std::cout << "Moving left..." << std::endl;
    robot.moveLeft();
    robot.print();

    std::cout << "Moving right..." << std::endl;
    robot.moveRight();
    robot.print();

    std::cout << "Stopping..." << std::endl;
    robot.stop();
    robot.print();

    return 0;
}
