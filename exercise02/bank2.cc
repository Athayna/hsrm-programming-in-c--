#include <iostream>
#include <string>

class Konto {
private:
    double kontostand;
    double zinssatz;

public:
    Konto(double kontostand, double zinssatz) : kontostand(kontostand), zinssatz(zinssatz) {}

    double getKontostand(void) const {return kontostand;}

    void kontoVerzinsung(void) {kontostand += (zinssatz * kontostand);}
};

class Kunde {
private:
    std::string name;
    std::string stadt;
    bool weiblich;
    Konto privat;
    Konto spar;

public:
    Kunde(std::string name, std::string stadt, bool weiblich, double privat, double spar)
    : name(name), stadt(stadt), weiblich(weiblich), privat(Konto(privat, 0.01)), spar(Konto(spar, 0.02)) {}

    void kundendatenAnzeigen(void) const {
        std::cout << (weiblich ? "Kundin " : "Kunde ") << name << " aus " << stadt << std::endl
        << "   Privatkonto : " << privat.getKontostand() << " Euro" << std::endl
        << "   Sparkonto : " << spar.getKontostand() << " Euro" << std::endl;
    }

    void kontoVerzinsung(void) {
        
        privat.kontoVerzinsung();
        spar.kontoVerzinsung();
    }
};

int main(void) {
    Kunde pedro("Pedro", "Berlin", false, 1000.0, 2000.0);
    Kunde alexandra("Alexandra", "Bonn", true, 3000.0, 4000.0);

    std::cout << "Daten vor Abschluss der Konten:" << std::endl;
    pedro.kundendatenAnzeigen();
    alexandra.kundendatenAnzeigen();

    pedro.kontoVerzinsung();
    alexandra.kontoVerzinsung();

    std::cout << "Daten nach Abschluss der Konten:" << std::endl;
    pedro.kundendatenAnzeigen();
    alexandra.kundendatenAnzeigen();

    return 0;
}