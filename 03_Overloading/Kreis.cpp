#include <cmath>
#include <iostream>

class Kreis {
    private:
        double x, y, radius;

    public:
        double flaeche(void) const {return 2 * M_PI * pow(radius, 2);}
        bool istImInneren(double x, double y) const {return hypot(this->x - x, this->y - y) <= radius;}

        //getters and setters
        void setMittelpunkt(double x, double y) {
            this->x = x;
            this->y = y;
        }
        void getMittelpunkt(void) const {std::cout << "X=" << x << " Y=" << y << std::endl;}
        void setRadius(double radius) {this->radius = radius;}
        double getRadius(void) const {return radius;}
        double getX(void) const {return x;}
        double getY(void) const {return y;}  
};

//additional operator overload for exercise 3.1
std::ostream& operator<<(std::ostream& os, const Kreis& kreis) {
    os << "X=" << kreis.getX() << " Y=" << kreis.getY() << " Raduis=" << kreis.getRadius();
    return os;
}

int main (void) {
    //init
    Kreis k1, k2;
    k1.setMittelpunkt(17, 17);
    k1.setRadius(2);
    k2.setMittelpunkt(5, 5);
    k2.setRadius(3);

    //flaeche() tests
    std::cout << "Flaeche von k1=" << k1.flaeche() << std::endl;
    std::cout << "Flaeche von k2=" << k2.flaeche() << std::endl;

    //istImInneren() tests
    std::cout << "Punkt (16|16) liegt in k1=" << k1.istImInneren(16, 16) << std::endl;
    std::cout << "Punkt (3|4) liegt in k1=" << k1.istImInneren(3, 4) << std::endl;
    std::cout << "Punkt (5|8) liegt in k2=" << k2.istImInneren(5, 8) << std::endl;
    std::cout << "Punkt (8|8) liegt in k2=" << k2.istImInneren(8, 8) << std::endl;

    //test << operator override for exercise 3.1
    std::cout << k1 << std::endl;

    return 0;
}