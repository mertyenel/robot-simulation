#include <iostream>
#include "Pose.h"

int main() {
    Pose pose1;
    std::cout << "Varsayılan Pose: (" << pose1.getX() << ", " << pose1.getY() << ", " << pose1.getTh() << ")\n";

    Pose pose2(1.0, 2.0, 45.0);
    std::cout << "Parametreli Pose: (" << pose2.getX() << ", " << pose2.getY() << ", " << pose2.getTh() << ")\n";

    pose1.setX(3.0);
    pose1.setY(4.0);
    pose1.setTh(90.0);
    std::cout << "Güncellenmiş Pose: (" << pose1.getX() << ", " << pose1.getY() << ", " << pose1.getTh() << ")\n";

    if (pose1 == pose2) {
        std::cout << "Poseler eşit.\n";
    } else {
        std::cout << "Poseler eşit değil.\n";
    }

    Pose sum = pose1 + pose2;
    std::cout << "Poselerin Toplamı: (" << sum.getX() << ", " << sum.getY() << ", " << sum.getTh() << ")\n";

    Pose diff = pose1 - pose2;
    std::cout << "Poselerin Farkı: (" << diff.getX() << ", " << diff.getY() << ", " << diff.getTh() << ")\n";

    pose1 += pose2;
    std::cout << "+= Sonrası Güncellenmiş Pose: (" << pose1.getX() << ", " << pose1.getY() << ", " << pose1.getTh() << ")\n";

    pose1 -= pose2;
    std::cout << "-= Sonrası Güncellenmiş Pose: (" << pose1.getX() << ", " << pose1.getY() << ", " << pose1.getTh() << ")\n";

    if (pose1 < pose2) {
        std::cout << "Pose1, Pose2'den küçük.\n";
    } else {
        std::cout << "Pose1, Pose2'den küçük değil.\n";
    }

    double x, y, th;
    pose1.getPose(x, y, th);
    std::cout << "Get Pose: (" << x << ", " << y << ", " << th << ")\n";

    pose1.setPose(10.0, 20.0, 180.0);
    std::cout << "Set Pose: (" << pose1.getX() << ", " << pose1.getY() << ", " << pose1.getTh() << ")\n";

    double distance = pose1.findDistanceTo(pose2);
    std::cout << "Poseler Arası Mesafe: " << distance << "\n";

    double angle = pose1.findAngleTo(pose2);
    std::cout << "Poseler Arası Açı: " << angle << " radian\n";

    return 0;
}
