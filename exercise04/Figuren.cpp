#include <iostream>

class Figur {
protected:
    float x, y;

public:
    Figur(float x, float y) : x(x), y(y) {}

    void anzeigen(std::ostream& os) const { os << "X=" << x << " Y=" << y; }
};

class Rechteck : public Figur {
protected:
    float laenge, breite;

public:
    Rechteck(float laenge, float breite) : Figur(laenge/2, breite/2), laenge(laenge), breite(breite) {}

    float oberflaeche(void) const { return breite * laenge; }
    float getLaenge(void) const { return laenge; }
    float getBreite(void) const { return breite; }
    void anzeigen(std::ostream& os) {
        Figur::anzeigen(os);
        os << " Laenge=" << laenge << " Breite=" << breite;
    }
};

class Kreis : public Figur {
private:
    float radius;

public:
    Kreis() : Figur() {}
    Kreis(float radius, float x = 0.0f, float y = 0.0f) : Figur(x, y), radius(radius) {}

    float oberflaeche(void) const { return 2 * 3.141 * (radius * radius); }
    float getRadius(void) const { return radius; }
    void setRadius(float radius) { this->radius = radius; }
    void setMitte(float x, float y) { this->x = x; this->y = y; }
    void anzeigen(std::ostream& os) const {
        Figur::anzeigen(os);
        os << " Radius=" << radius;
    } 
};

class buntesRechteck : public Rechteck {
private:
    unsigned farbe;

public:
    buntesRechteck(float laenge, float breite, unsigned farbe) : Rechteck(laenge, breite), farbe(farbe)  {}

    unsigned getFarbe(void) const { return farbe; }
};

int main(void) { 
    buntesRechteck recht(4.3f, 12.5f, 4u); 
    std::cout << recht.getLaenge() << std::endl; 
    recht.anzeigen(std::cout); 
    std::cout << std::endl; 

    Kreis kr; 
    kr.setMitte(2.3f, 4.5f); 
    kr.setRadius(12.2f); 
    kr.anzeigen(std::cout); 
    std::cout << std::endl; 
    return 0;
}