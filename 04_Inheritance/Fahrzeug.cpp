#include <iostream>
#include <string>
#include <vector>

class Fahrzeug {
protected:
    std::string marke;
    int datum;
    float kaufpreis, preis;

public:
    // 4.2 a) constructor with initialization parameters
    Fahrzeug(std::string marke, int datum, float kaufpreis) : marke(marke), datum(datum), kaufpreis(kaufpreis) {}

    // 4.2 b) method to print the objects attribute's current values
    virtual void anzeigen(std::ostream& os) const {
        os << "Marke: " << marke << ", Kaufdatum: " << datum
        << ", Kaufpreis: " << kaufpreis << ", aktueller Preis: " << preis << std::endl;
    }

    // 4.2 e) method to calculate the current price of the object based on the year of purchase and the current year
    virtual void berechnePreis(void) {
        preis = kaufpreis * (1 - 0.01 * (2015 - datum));
    }
};

// 4.2 c) class Auto derived from Fahrzeug with additional attributes
class Auto : public Fahrzeug {
private:
    float hubraum;
    int tueren, leistung, kmstand;

public:
    // 4.2 d) constructor with initialization parameters and initialization of base class
    Auto(std::string marke, int datum, float kaufpreis, float hubraum, int tueren, int leistung, int kmstand)
        : Fahrzeug(marke, datum, kaufpreis), hubraum(hubraum), tueren(tueren), leistung(leistung), kmstand(kmstand) {}

    // 4.2 d) override method to print the objects attribute's current values using base class method 
    void anzeigen(std::ostream& os) const {
        os << "---- Auto ----" << std::endl;
        Fahrzeug::anzeigen(os);
        os << hubraum << " Liter, " << tueren << " Tueren, " << leistung << " PS, " << kmstand << "km." << std::endl;
    }

    // 4.2 f) override method to calculate the current price of the object based on the year of purchase, the kilometers driven and the brand
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

// additional enum for to distinguish between propeller and jet planes
enum Flugzeug_Typ { PROPELLER, DUESENFLUGZEUG };

// 4.2 c) class Flugzeug derived from Fahrzeug with additional attributes
class Flugzeug : public Fahrzeug {
private:
    Flugzeug_Typ typ;
    int flugstunden;

public:
    // 4.2 d) constructor with initialization parameters and initialization of base class
    Flugzeug(std::string marke, int datum, float kaufpreis, Flugzeug_Typ typ, int flugstunden)
        : Fahrzeug(marke, datum, kaufpreis), typ(typ), flugstunden(flugstunden) {}

    // 4.2 d) override method to print the objects attribute's current values using base class method 
    void anzeigen(std::ostream& os) const {
        os << "---- Flugzeug mit " << (typ==PROPELLER ? "Propeller " : "Duesen ") << " ----" << std::endl;
        Fahrzeug::anzeigen(os);
        os << flugstunden << " Flugstunden." << std::endl;
    }

    // 4.2 f) override method to calculate the current price of the object based on the flight hours and the type of plane
    void berechnePreis(void) {
        preis = kaufpreis * (1.0 - 0.1 * (flugstunden / (typ==PROPELLER ? 100 : 1000)));
        if (preis < 0) preis = 0;
    }
};

int main(void){ 
    // test the classes and output with given code by the professor

    // create a vector for each type of vehicle
    std::vector<Auto> garage; 
    std::vector<Flugzeug> flugplatz; 

    // add vehicles to the vectors
    garage.push_back(Auto("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 12000)); 
    garage.push_back(Auto("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320)); 
    garage.push_back(Auto("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000)); 
    flugplatz.push_back(Flugzeug("Cessna", 1972, 1230673.90, PROPELLER, 250)); 
    flugplatz.push_back(Flugzeug("Unbekannt", 1992, 4321098.00, DUESENFLUGZEUG, 1300)); 
    
    // calculate and print the vehicles' current state for each car
    for (auto pkw : garage) { 
        pkw.berechnePreis(); 
        pkw.anzeigen(std::cout); 
    }
    
    // calculate and print the vehicles' current state for each plane
    for (auto flugzeug : flugplatz) { 
        flugzeug.berechnePreis(); 
        flugzeug.anzeigen(std::cout); 
    }

    return 0;
}