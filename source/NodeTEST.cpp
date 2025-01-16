#include <iostream>
#include "Node.h"

int main() {
    Node node1;
    node1.print();

    Node node2(1.0, 2.0, 45.0);
    node2.print();

    Pose yeniPose(3.0, 4.0, 90.0);
    node1.setPose(yeniPose);
    Pose alinanPose = node1.getPose();
    std::cout << "Alınan Pose: (" << alinanPose.getX() << ", " << alinanPose.getY() << ", " << alinanPose.getTh() << ")\n";

    Node node3(5.0, 6.0, 135.0);
    node1.setNext(&node3);
    Node* sonrakiNode = node1.getNext();
    if (sonrakiNode != nullptr) {
        sonrakiNode->print();
    } else {
        std::cout << "Sonraki Node boş.\n";
    }

    return 0;
}
