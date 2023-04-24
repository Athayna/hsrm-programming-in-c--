#include <iostream>
using namespace std;

/*******************************************
 * Schreiben Sie Ihren Code hier
 *******************************************/

class Sparschwein {
  private:
    double betrag;

  public:
    void anzeigen() const {
      if (betrag <= 0) {cout << "Sie sind pleite" << endl;}
      else {cout << "Sie haben " << betrag << " Euro in Ihrem Sparschwein" << endl;}
    }

    void schuetteln() const {if (betrag > 0) {cout << "Bling bling" << endl;}}

    void fuellen(double betrag) {if (betrag > 0) {this->betrag += betrag;}}

    void leeren() {betrag = 0;}

    void entnehmen(double betrag) {
      if (betrag > 0) {
        if (betrag >= this->betrag) {this->betrag = 0;}
        else {this->betrag -= betrag;}
      }
    }

    bool ausreichend_geld(double betrag, double& saldo) const {
      if (betrag <= 0) {
        saldo = this->betrag;
        return true;
      } else if (betrag > this->betrag) {
        saldo = (this->betrag - betrag) * (-1);
        return false;
      } else {
        saldo = this->betrag - betrag;
        return true;
      }
    }

    double getBetrag() const {return betrag;}
};

/*******************************************
 * Ändern Sie nichts mehr nach dieser Zeile
 *******************************************/

int main()
{
  Sparschwein schweinchen;

  schweinchen.leeren();
  schweinchen.schuetteln();
  schweinchen.anzeigen();

  schweinchen.entnehmen(20.0);
  schweinchen.schuetteln();
  schweinchen.anzeigen();

  schweinchen.fuellen(550.0);
  schweinchen.schuetteln();
  schweinchen.anzeigen();

  schweinchen.entnehmen(10.0);
  schweinchen.entnehmen(5.0);
  schweinchen.anzeigen();

  cout << endl;

  // das Budget Ihres Traumurlaubes.
  double budget;

  cout << "Geben Sie das Budget für Ihren Urlaub ein : ";
  cin >> budget;

  // das was im Sparschwein nach dem Urlaub bleibt

  double saldo(0.0);

  if (schweinchen.ausreichend_geld(budget, saldo)) {
    cout << "Sie haben ausreichend, um in den Urlaub zu fahren!"
         << endl
         << "Ihnen bleiben noch " << saldo << " Euro"
         << " bei der Rückkehr." << endl << endl;
    schweinchen.entnehmen(budget);
  } else {
    cout << "Ihnen fehlen " << saldo << " Euro"
         << ", um in den Urlaub zu gehen!" << endl << endl;
  }
  return 0;
}
