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

        void anzeige() const {
            std::cout << "X=" << x << ", Y=" << y <<", Z=" << z << std::endl;
        }

        bool vergleichen(Punkt3D other) {
            return x == other.getX() && y == other.getY() && z == other.getZ();
        }

        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}
};

int main(void) {
    Punkt3D p1, p2, p3;
    p1.init(1, 2, 3);
    p2.init(1, 2, 3);
    p3.init(1, 2, 4);

    p1.anzeige();
    p2.anzeige();
    p3.anzeige();

    std::cout << "p1 == p2 = " << p1.vergleichen(p2) << std::endl;
    std::cout << "p1 == p3 = " << p1.vergleichen(p3) << std::endl;

    return 0;
}