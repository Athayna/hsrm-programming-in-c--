#include <iostream>
#include <string>
using namespace std;

// Diese Funktion zeigt die Daten eines Kunden an
void kundendatenAnzeigen(string name, string stadt,
    double kontostand1, double kontostand2) {
    cout << "Kunde " << name << " aus " << stadt << endl;
    cout << "   Privatkonto : " << kontostand1 << " Euro" << endl;
    cout << "   Sparkonto : " << kontostand2 << " Euro" << endl;
}

// Diese Funktion verzinst den Kontostand eines Kontos
double kontoVerzinsung(double kontostand, double zinssatz) {
    double zinsen(zinssatz * kontostand);
    double neuerkontostand(kontostand + zinsen);
    return neuerkontostand;
}

int main()
{
    // Daten aller Privatkonten (Zinssätze)
    double zinssatz1(0.01);
    // Daten aller Sparkonten (Zinssätze) :
    double zinssatz2(0.02);
    // Daten des ersten Kunden (Name und Stadt) :
    string name1("Pedro");
    string stadt1("Berlin");
    // Daten des Privatkontos des ersten Kunden (Kontostand) :
    double kontostand1ErsterKunde(1000.0);
    // Daten des Sparkontos des ersten Kunden (Kontostand) :
    double kontostand2ErsterKunde(2000.0);
    // Daten des zweiten Kunden (Name und Stadt) :
    string name2("Alexandra");
    string stadt2("Bonn");
    // Daten des Privatkontos des zweiten Kunden (Kontostand) :
    double kontostand1zweiterKunde(3000.0);
    // Daten des Sparkontos des zweiten Kunden (Kontostand) :
    double kontostand2zweiterKunde(4000.0);

    cout << "Daten vor Abschluss der Konten:" << endl;
    // Daten des ersten Kunden anzeigen:
    kundendatenAnzeigen(name1, stadt1, kontostand1ErsterKunde, kontostand2ErsterKunde);
    // Daten des zweiten Kunden anzeigen:
    kundendatenAnzeigen(name2, stadt2, kontostand1zweiterKunde, kontostand2zweiterKunde);

    // Verzinsung des Privatkontos des ersten Kunden:
    kontostand1ErsterKunde = kontoVerzinsung(kontostand1ErsterKunde, zinssatz1);
    // Verzinsung des Sparkontos des ersten Kunden:
    kontostand2ErsterKunde = kontoVerzinsung(kontostand2ErsterKunde, zinssatz2);
    // Verzinsung des Privatkontos des zweiten Kunden:
    kontostand1zweiterKunde = kontoVerzinsung(kontostand1zweiterKunde, zinssatz1);
    //Verzinsung des Sparkontos des zweiten Kunden:
    kontostand2zweiterKunde = kontoVerzinsung(kontostand2zweiterKunde, zinssatz2);

    cout << "Daten nach Abschluss der Konten:" << endl;
    // Daten des ersten Kunden anzeigen:
    kundendatenAnzeigen(name1, stadt1, kontostand1ErsterKunde, kontostand2ErsterKunde);
    // Daten des zweiten Kunden anzeigen:
    kundendatenAnzeigen(name2, stadt2, kontostand1zweiterKunde, kontostand2zweiterKunde);

    return 0;
}
