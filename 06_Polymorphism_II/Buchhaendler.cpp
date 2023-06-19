#include <iostream>
#include <string>
#include <vector>

// 6.1 a) added a Buch class with the given attributes
class Buch {
protected:
    std::string titel, autor;
    int seiten;
    bool bestseller;

public:
    // 6.1 a) add a constructor and virtual destructor
    Buch(std::string titel, std::string autor, int seiten, bool bestseller)
        : titel(titel), autor(autor), seiten(seiten), bestseller(bestseller) {}
    virtual ~Buch() {}

    // 6.1 a) calculate and return price with given formula
    virtual float berechne_preis(void) const { return seiten * 0.3f + (bestseller ? 50.0f : 0.0f); }
    // 6.1 a) print function inspired by exercise examples that doesn't contain the price
    virtual void anzeigen(std::ostream& os) const {
        os << "Titel: " << titel << std::endl
        << "Autor: " << autor << std::endl
        << "Anzahl Seiten: " << seiten << std::endl
        << "Bestseller: " << (bestseller ? "ja" : "nein") << std::endl
        << "Preis: " << berechne_preis() << std::endl;
    }
};

// 6.1 b) added a new class Roman that inherits from Buch and add an additional protected attribute biografie
class Roman : public Buch {
protected:
    bool biografie;

public:
    // 6.1 b) add a constructor that calls the constructor of the base class
    Roman(std::string titel, std::string autor, int seiten, bool bestseller, bool biografie)
        : Buch(titel, autor, seiten, bestseller), biografie(biografie) {}
    // 6.1 b) add a virtual empty destructor
    virtual ~Roman() {}
    // 6.1 b) a print function that calls the print function of the base class and adds the biografie attribute
    virtual void anzeigen(std::ostream& os) const {
        Buch::anzeigen(os);
        os << "Dieser Roman ist " << (biografie ? "" : "k") << "eine Biografie" << std::endl;
    }
};

// 6.1 b) added a new class Krimi that inherits from Roman
class Krimi : public Roman {
public:
    // 6.1 b) add a constructor that calls the constructor of the base class
    Krimi(std::string titel, std::string autor, int seiten, bool bestseller, bool biografie)
        : Roman(titel, autor, seiten, bestseller, biografie) {}

    // 6.1 b) override the price calculation function of the base class and subtract 10 from the price but make sure it doesn't get negative
    float berechne_preis(void) const {
        float preis = Buch::berechne_preis() - 10.0f;
        return (preis < 0.0f ? 1.0f : preis);
    }    
};

// 6.1 b) added a new class CoffeeTableBuch that inherits from Buch
class CoffeeTableBuch : public Buch {
public:
    // 6.1 b) add a constructor that calls the constructor of the base class
    CoffeeTableBuch(std::string titel, std::string autor, int seiten, bool bestseller)
        : Buch(titel, autor, seiten, bestseller) {}
    // 6.1 b) add a virtual empty destructor
    virtual ~CoffeeTableBuch() {}
    // 6.1 b) override the price calculation function of the base class and add 30 to the price
    float berechne_preis(void) const { return Buch::berechne_preis() + 30.0f; }
};

// 6.1 c) added a new class Buchladen that contains a vector of Buch pointers
class Buchladen {
private:
    std::vector<Buch*> buecher_sammlung;

public:
    // 6.1 c) function to add a Buch pointer to the vector
    void buch_hinzufuegen(Buch* buch) { buecher_sammlung.push_back(buch); }

    // 6.1 c) function to print all the books in the vector
    void anzeigen(void) const { for (auto buch : buecher_sammlung) buch->anzeigen(std::cout); }

    // 6.1 c) function to delete all the books in the vector and clear the vector
    void buchsammlung_leeren(void) {
        for (auto buch : buecher_sammlung) delete buch;        
        buecher_sammlung.clear();
    }
};

int main(void) {
    // test classes with code provided in the exercise
    Buchladen l;

    l.buch_hinzufuegen(new Krimi("Der Hund von Baskerville", "A.C.Doyle", 221, false, false));
    l.buch_hinzufuegen(new Krimi("Der Pate", "A.Cuso", 367, true, false));
    l.buch_hinzufuegen(new Roman("Bretonischer Ruhm", "J.L. Bannalec", 283, false, false));
    l.buch_hinzufuegen(new Roman ("Geronimo: Erinnerungen", "S.M. Barrett", 173, false, true));
    l.buch_hinzufuegen(new CoffeeTableBuch ("Europas Flüsse", "C. Osborne", 150, false));
    
    l.anzeigen();

    l.buchsammlung_leeren();

    return 0;
}