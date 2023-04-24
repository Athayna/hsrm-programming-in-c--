#include <iostream>

class Rechteck {
    private:
        int breite, laenge;

    public:
        int oberfl() const {return breite * laenge;}
        
        //getters and setters
        void setBreite(int breite) {this->breite = breite;}
        int getBreite() const {return breite;}
        void setLaenge(int laenge) {this->laenge = laenge;}
        int getLaenge() const {return laenge;}
};

int main(void) {
    Rechteck recht;
    recht.setBreite(5);
    recht.setLaenge(5);
    std::cout << recht.oberfl() << std::endl;
    return 0;
}