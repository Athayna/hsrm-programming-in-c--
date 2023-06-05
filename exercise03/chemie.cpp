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
      Vervollständigen Sie den Code hier
    *******************************************************/

};

/*******************************************
 * Ändern Sie nach dieser Zeile nichts mehr.
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
    Flakon flakon2("Salzsäure", 500.0, 2.0);
    Flakon flakon3("Perchlorsäure", 800.0, 1.5);

    anzeige_mix(flakon1, flakon2);
    anzeige_mix(flakon2, flakon3);

    return 0;

}
