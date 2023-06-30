#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flakon
{
private:
    string name;
    double volumen;
    double pH;

public:
    /*****************************************************
      Vervollst�ndigen Sie den Code hier
    *******************************************************/
    // 3.4 b) constructor to set name, volumen and pH of flakon (no default constructor necessary)
    Flakon(std::string name, double volumen, double pH) : name(name), volumen(volumen), pH(pH) {}

    // 3.4 c) etikett function to print the flakon state
    std::ostream& etikett(std::ostream& ausgabe) const {
        ausgabe << name << ": " << volumen << " ml, pH " << pH;
        return ausgabe;
    }

    // 3.4 a) getter for name, volumen and pH
    std::string getName(void) const {return name;}
    double getVolumen(void) const {return volumen;}
    double getpH(void) const {return pH;}

    // 3.4 f) internally overload += operator to add a flakon to another flakon
    Flakon& operator+=(Flakon const& f2) {
        this->name += " + " + f2.getName();
        this->volumen += f2.getVolumen();
        this->pH = -log10((this->volumen * pow(10.0, -this->pH) + f2.getVolumen() * pow(10.0, -f2.getpH())) / (this->volumen + f2.getVolumen()));
        return *this;
    }
};

// 3.4 d) externally overload << operator to print flakon using etikett function
std::ostream& operator<<(std::ostream& os, Flakon const& flakon) {
    return flakon.etikett(os);
}

// 3.4 e) externally overload + operator to mix two flakons
const Flakon operator+(Flakon const& f1, Flakon const& f2) {
    std::string name = f1.getName() + " + " + f2.getName();
    double volumen = f1.getVolumen() + f2.getVolumen();
    double pH = -log10((f1.getVolumen() * pow(10.0, -f1.getpH()) + f2.getVolumen() * pow(10.0, -f2.getpH())) / (f1.getVolumen() + f2.getVolumen()));
    return Flakon(name, volumen, pH);
}

/*******************************************
 * �ndern Sie nach dieser Zeile nichts mehr.
 *******************************************/

void anzeige_mix(Flakon const& f1, Flakon const& f2)
{
    cout << "Mische ich " << endl;
    cout << "\t\"" << f1 << "\"" << endl;
    cout << "mit" << endl;
    cout << "\t\"" << f2 << "\"" << endl;
    cout << "erhalte ich:" << endl;
    cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
    Flakon flakon1("Wasser", 600.0, 7.0);
    Flakon flakon2("Salzs�ure", 500.0, 2.0);
    Flakon flakon3("Perchlors�ure", 800.0, 1.5);

    anzeige_mix(flakon1, flakon2);
    anzeige_mix(flakon2, flakon3);

    return 0;

}
