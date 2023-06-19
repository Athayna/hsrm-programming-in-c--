#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Artikel {
private:
    std::string name;
    double preis;
    bool aktion;

public:
    // constructor for articles without a sale, calling the other constructor with the sale parameter "false"
    Artikel(std::string name, double preis) : Artikel(name, preis, false) {}
    // constructor for articles with a sale
    Artikel(std::string name, double preis, bool aktion) : name(name), preis(preis), aktion(aktion) {}

    // getter methods to return the article's name, price and sale status
    std::string getName(void) const { return name; }
    double getPreis(void) const { return preis; }
    bool getAktion(void) const { return aktion; }
};

class Einkauf {
private:
    Artikel artikel;
    int menge;

public:
    // constructor initializing a purchase with the article and the amount purchased
    Einkauf(Artikel artikel, int menge) : artikel(artikel), menge(menge) {}

    // getter methods to return the article and the amount purchased
    Artikel getArtikel(void) const { return artikel; }
    int getMenge(void) const { return menge; }

    // method to print out the purchase on the console
    void anzeigen() {
        std::cout << artikel.getName() << " : " << artikel.getPreis()
        << " x " << menge << " = " << (artikel.getPreis() * menge) << " Euro"
        << (artikel.getAktion() ? " (Aktion)" : "") << std::endl;
    }
};

class Einkaufswagen {
private:
    std::vector<Einkauf> einkaeufe;

public:
    // method to add a purchase to the shopping cart with no amount specified, calling the other method with the amount parameter "1"
    void fuellen(Artikel artikel) { fuellen(artikel, 1); }
    // method to add a purchase to the shopping cart with the amount specified
    void fuellen(Artikel artikel, int menge) { einkaeufe.push_back(Einkauf(artikel, menge)); }
    // getter method to return the purchases in the shopping cart
    std::vector<Einkauf> getEinkaeufe(void) { return einkaeufe; }
};

class Kasse {
private:
    int nummer;
    double betrag;
    double gesamtbetrag;

public:
    // constructor initializing a cash register with the scanned amount of money and the total amount of money set to 0
    Kasse() : betrag(0), gesamtbetrag(0) {}
    
    // method to scan the purchases in the shopping cart, add the amount of money to the total amount of money and print out the purchases on the console
    void scannen(Einkaufswagen wagen) {
        for (Einkauf einkauf : wagen.getEinkaeufe()) {
            betrag += (einkauf.getArtikel().getPreis() * einkauf.getMenge());
            einkauf.anzeigen();
        }
        std::cout << "-----" << std::endl;
        std::cout << "Gesamtsumme Einkauf : " << betrag << " Euro" << std::endl;
        gesamtbetrag += betrag;
        betrag = 0;
    }

    // method to print out the total amount of money scanned on the console
    void anzeigen(void) const { std::cout << gesamtbetrag << " Euro" << std::endl; }
};

// following code was given by the professor for testing purposes

// ======================================================================
int main()
{
    // Im Supermarkt verkaufte Artikel
    Artikel blumenkohl("Blumenkohl extra", 3.50);
    Artikel roman("Die Leider der Sophie", 16.50, true);
    Artikel camembert("Der Cremige 100%", 5.80);
    Artikel cd("C++ in drei Tagen", 48.50);
    Artikel getraenk("Kleine-Milch", 2.50, true);
    Artikel erbsen("Erbsen TK", 4.35);
    Artikel fisch("Sardinen", 6.50);
    Artikel kekse("Omamas Gebäck", 3.20);
    Artikel birne("Williamsbirne", 4.80);
    Artikel cafe("100% Arabica", 6.90, true);
    Artikel brot("Vollkornbrot", 6.90);

    // Supermarkt Einkaufswagen, z.B. hier 3 Stück
    vector<Einkaufswagen> einkaufswaegen(3);

    // Kassen des Supermakrts, z.B. hier 2 Stück
    vector<Kasse> kassen(2);

    // Die Kunden kaufen ein:
    // Das zweite Argument der fuellen-Methode ist die Menge

    // Einkauf im ersten Einkaufwagen
    einkaufswaegen[0].fuellen(blumenkohl, 2);
    einkaufswaegen[0].fuellen(cd);
    einkaufswaegen[0].fuellen(kekse, 4);
    einkaufswaegen[0].fuellen(getraenk, 6);
    einkaufswaegen[0].fuellen(fisch, 2);

    // Einkauf im zweiten Einkaufwagen
    einkaufswaegen[1].fuellen(roman);
    einkaufswaegen[1].fuellen(camembert);
    einkaufswaegen[1].fuellen(erbsen, 2);
    einkaufswaegen[1].fuellen(birne, 2);

    // Einkauf im dritten Einkaufwagen
    einkaufswaegen[2].fuellen(cafe, 2);
    einkaufswaegen[2].fuellen(brot);
    einkaufswaegen[2].fuellen(camembert, 2);

    // Die Kunden gehen an die Kassen:
    kassen[0].scannen(einkaufswaegen[0]);
    cout << "=========================================" << endl;
    kassen[0].scannen(einkaufswaegen[1]);
    cout << "=========================================" << endl;
    kassen[1].scannen(einkaufswaegen[2]);
    cout << "=========================================" << endl;

    // Anzeige der Gesamtwerte der Kassen:
    cout << "Gesamt Tag :" << endl;
    for (size_t i(0); i < kassen.size(); ++i) {
        cout << "Kasse " << i + 1 << " : ";
        kassen[i].anzeigen();
        cout << endl;
    }

    return 0;
}