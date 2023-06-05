#include <iostream>
using namespace std;

/*******************************************
 * Schreiben Sie Ihren Code hier
 *******************************************/

class Sparschwein {
private:
    double betrag;

public:
    // print method that displays a message either implying that the piggy bank is empty or displaying the amount of money in the piggy bank
    void anzeigen(void) const {
        if (betrag <= 0) { std::cout << "Sie sind pleite" << std::endl; }
        else { std::cout << "Sie haben " << betrag << " Euro in Ihrem Sparschwein" << std::endl; }
    }

    // method to shake the piggy bank and print a message if it contains money
    void schuetteln(void) const { if (betrag > 0) {std::cout << "Bling bling" << std::endl;} }

    // method to fill the piggy bank with money handed in as a parameter
    void fuellen(double betrag) { if (betrag > 0) {this->betrag += betrag;} }

    // method to empty the piggy bank
    void leeren(void) { betrag = 0; }

    // method to remove money from the piggy bank if the handed in amount is positive and smaller than the amount of money in the piggy bank
    void entnehmen(double betrag) {
        if (betrag > 0) {
            this->betrag = ((betrag >= this->betrag) ? 0 : this->betrag - betrag);
        }
    }

    // method to check if the handed in amount of money is smaller than the amount of money in the piggy bank and return the remaining amount of money in the piggy bank
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

    // getter method to return the piggy bank's amount
    double getBetrag(void) const { return betrag; }
};

// following code was given by the professor to test the class

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
