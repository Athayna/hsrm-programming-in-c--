#include <iostream>
#include <string>
#include <vector>


// classes Fahrzeug, Auto and Flugzeug copied from exercise 4
class Fahrzeug {
protected:
    std::string marke;
    int datum;
    float kaufpreis, preis;

public:
    Fahrzeug(std::string marke, int datum, float kaufpreis) : marke(marke), datum(datum), kaufpreis(kaufpreis) {}
    virtual ~Fahrzeug() {}

    virtual void anzeigen(std::ostream& os) const {
        os << "Marke: " << marke << ", Kaufdatum: " << datum
        << ", Kaufpreis: " << kaufpreis << ", aktueller Preis: " << preis << std::endl;
    }

    virtual void berechnePreis(void) {
        preis = kaufpreis * (1 - 0.01 * (2015 - datum));
    }
};

class Auto : public Fahrzeug {
private:
    float hubraum;
    int tueren, leistung, kmstand;

public:
    Auto(std::string marke, int datum, float kaufpreis, float hubraum, int tueren, int leistung, int kmstand)
        : Fahrzeug(marke, datum, kaufpreis), hubraum(hubraum), tueren(tueren), leistung(leistung), kmstand(kmstand) {}

    void anzeigen(std::ostream& os) const {
        os << "---- Auto ----" << std::endl;
        Fahrzeug::anzeigen(os);
        os << hubraum << " Liter, " << tueren << " Tueren, " << leistung << " PS, " << kmstand << "km." << std::endl;
    }

    void berechnePreis(void) {
        float abzugDatum = 2 * (2015 - datum);
        float abzugKM = 5 * (kmstand / 10000);
        if ((kmstand % 10000) >= 5000) abzugKM += 5;
        float abzug10 = 0;
        float abzug20 = 0;
        if (marke == "Renault" || marke == "Fiat") abzug10 = 10;
        else if (marke == "Ferrari" || marke == "Porsche") abzug20 = 20;
        preis = kaufpreis * (1.0 - (abzugDatum + abzugKM + abzug10 + abzug20) / 100.0);
    }
};

enum Flugzeug_Typ { PROPELLER, DUESENFLUGZEUG };

class Flugzeug : public Fahrzeug {
private:
    Flugzeug_Typ typ;
    int flugstunden;

public:
    Flugzeug(std::string marke, int datum, float kaufpreis, Flugzeug_Typ typ, int flugstunden)
        : Fahrzeug(marke, datum, kaufpreis), typ(typ), flugstunden(flugstunden) {}

    void anzeigen(std::ostream& os) const {
        os << "---- Flugzeug mit " << (typ==PROPELLER ? "Propeller " : "Duesen ") << " ----" << std::endl;
        Fahrzeug::anzeigen(os);
        os << flugstunden << " Flugstunden." << std::endl;
    }

    void berechnePreis(void) {
        preis = kaufpreis * (1.0 - 0.1 * (flugstunden / (typ==PROPELLER ? 100 : 1000)));
        if (preis < 0) preis = 0;
    }
};

class Flughafen {
private:
    std::vector<Fahrzeug*> fahrzeuge;

public:
    void fahrzeuge_anzeigen(std::ostream& os) const { for (auto fahrzeug : fahrzeuge) fahrzeug->anzeigen(os); }
    void fahrzeuge_hinzufuegen(Fahrzeug* fahrzeug) { fahrzeuge.push_back(fahrzeug); }
    void fahrzeuge_leeren(void) { 
        for (auto fahrzeug : fahrzeuge) delete fahrzeug;
        fahrzeuge.clear();
    }
    void fahrzeuge_loeschen(void) {  }
};   

int main(void) {
    // test the classes and output with code provided by the professor

    // instaciate Flughafen
    Flughafen ffm;

    // add vehicles
    ffm.fahrzeuge_hinzufuegen(new Auto("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 12000));
    ffm.fahrzeuge_hinzufuegen(new Auto("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
    ffm.fahrzeuge_hinzufuegen(new Flugzeug("Cessna", 1972, 1230673.90, PROPELLER, 250));
    ffm.fahrzeuge_hinzufuegen(new Flugzeug("Unbekannt", 1992, 4321098.00, DUESENFLUGZEUG, 1300));
    ffm.fahrzeuge_hinzufuegen(new Auto("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));
    
    // test polymorphism for fahrzeuge_anzeigen()
    ffm.fahrzeuge_anzeigen(std::cout);
    // free manually allocated memory
    ffm.fahrzeuge_leeren();
    return 0;
}