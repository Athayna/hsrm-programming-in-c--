#include <cmath>
#include <iostream>

class Punkt3D {
    private:
        double x, y, z;

    public:
        void init(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}
};

class Dreieck {
    private:
        double abstand1, abstand2, abstand3;
        double umfang;

        double berechneAbstand(Punkt3D p1, Punkt3D p2) {
            return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2) + pow(p1.getZ() - p2.getZ(), 2));
        }

        double berechneUmfang() {return abstand1 + abstand2 + abstand3;}

    public:
        void init(Punkt3D p1, Punkt3D p2, Punkt3D p3) {
            abstand1 = berechneAbstand(p1, p2);
            abstand1 = berechneAbstand(p2, p3);
            abstand1 = berechneAbstand(p3, p1);
            umfang = berechneUmfang();
        }

        bool isGleichschenklig() const {return abstand1 == abstand2 || abstand1 == abstand3 || abstand2 == abstand3;}

        double getUmfang() const {return umfang;}
};

int main(void) {
    Punkt3D p1, p2, p3;
    double x, y, z;

    std::cout << "Eingabe eines neuen Punktes" << std::endl;
    std::cout << "Bitte geben Sie x ein: " << std::endl;
    std::cin >> x;
    std::cout << "Bitte geben Sie y ein: " << std::endl;
    std::cin >> y;
    std::cout << "Bitte geben Sie z ein: " << std::endl;
    std::cin >> z;
    p1.init(x, y, z);

    std::cout << "Eingabe eines neuen Punktes" << std::endl;
    std::cout << "Bitte geben Sie x ein: " << std::endl;
    std::cin >> x;
    std::cout << "Bitte geben Sie y ein: " << std::endl;
    std::cin >> y;
    std::cout << "Bitte geben Sie z ein: " << std::endl;
    std::cin >> z;
    p2.init(x, y, z);

    std::cout << "Eingabe eines neuen Punktes" << std::endl;
    std::cout << "Bitte geben Sie x ein: " << std::endl;
    std::cin >> x;
    std::cout << "Bitte geben Sie y ein: " << std::endl;
    std::cin >> y;
    std::cout << "Bitte geben Sie z ein: " << std::endl;
    std::cin >> z;
    p3.init(x, y, z);

    Dreieck d;
    d.init(p1, p2, p3);
    std::cout << "Umfang: " << d.getUmfang() << std::endl;
    if (d.isGleichschenklig())
        std::cout << "Dieses Dreieck ist gleichschenklig!" << std::endl;
    else
        std::cout << "Dieses Dreieck ist nicht gleichschenklig!" << std::endl;

    return 0;
}