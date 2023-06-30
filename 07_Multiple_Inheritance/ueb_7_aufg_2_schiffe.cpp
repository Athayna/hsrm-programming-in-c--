#include <iostream>
#include <cmath>
#include<cxxabi.h>
using namespace std;

enum Flagge {JollyRogers, CompagnieDuSenegal, CompagnieDOstende};

enum Zustand {Intakt, Beschaedigt, Versunken};

int sq(int x)
{
  return x*x;
}

class Koordinaten
{
public:
  Koordinaten(int ein_x, int ein_y) : x_(ein_x), y_(ein_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Koordinaten const& wert); // unten zu definieren
private:
  int x_;
  int y_;
};

/*****************************************************
 * Ab hier fügen Sie Ihren Code hinzu
 *****************************************************/

// 7.2 a) overloaded << operator for class Koordinaten
std::ostream& operator<<(std::ostream& os, Koordinaten const& wert) {
    os << "(" << wert.x() << ", " << wert.y() << ")";
    return os;
}

// 7.2 a) implemented a function to measure distances between coordinates
double entfernung(Koordinaten const& wert1, Koordinaten const& wert2) {
    return std::sqrt(sq(wert1.x() - wert2.x()) + sq(wert1.y() - wert2.y()));
}

// 7.2 a) defined overloading of += operator for class Koordinaten
void Koordinaten::operator+=(Koordinaten const& wert)
{
    //hier definieren
    x_ += wert.x();
    y_ += wert.y();
}

// 7.2 a) overloaded << operator for enum Flagge
std::ostream& operator<<(std::ostream& os, Flagge const& wert) {
    switch(wert) {
        case JollyRogers:
            os << "Piraten";
            break;
        case CompagnieDuSenegal:
            os << "Frankreich";
            break;
        case CompagnieDOstende:
            os << "Österreich";
            break;
        default:
            os << "Unbekannt";
            break;
    }
    return os;
}

// 7.2 a) overloaded << operator for enum Zustand
std::ostream& operator<<(std::ostream& os, Zustand const& wert) {
    switch(wert) {
        case Intakt:
            os << "intakt";
            break;
        case Beschaedigt:
            os << "beschädigt";
            break;
        case Versunken:
            os << "versunken";
            break;
        default:
            os << "unbekannter Zustand";
            break;
    }
    return os;
}

class Schiff
{
protected:
    // 7.2 b) defined attributes for class Schiff
    Koordinaten position_;
    Flagge flagge_;
    Zustand zustand_;
    const int radius_zusammentreffen = 10;

public:
    // 7.2 b) constructor taking two integers and a Flagge, setting zustand_ always to Zustand::Intakt
    Schiff(int x, int y, Flagge flagge) : position_(x, y), flagge_(flagge), zustand_(Intakt) {}

    // 7.2 b) a function that returns the position coordinates
    Koordinaten position(void) const { return position_; }

    Zustand zustand(void) const { return zustand_; }

    // 7.2 b) function that moves the ship, using the overloaded += operator of class Koordinaten
    void bewegen(int einheiten_x, int einheiten_y) {
        if (zustand_ == Versunken) return;
        position_ += Koordinaten(einheiten_x, einheiten_y);
    }

    // 7.2 b) function to reset the ships zustand_
    void aufsteigen(void) { zustand_ = Intakt; }

    // 7.2 b) print function that represents the current status of the ship
    void anzeigen(std::ostream& os) const {
        os << abi::__cxa_demangle(typeid(this).name(), nullptr, nullptr, nullptr) << " an " << position_ << ", mit Flagge " << flagge_ << ", " << zustand_;
    }

    // 7.2 c) encounter function
    void begegnen(Schiff& schiff) {
        if (this->zustand_ == Versunken || schiff.zustand_ == Versunken) { return; }
        if (entfernung(this->position_, schiff.position_) > this->radius_zusammentreffen) { return; }
        angreifen(schiff);
        wehren(schiff);
    }

    // 7.2 c) pure virtual/abstract functions for all encounter cases
    virtual void angreifen(Schiff& schiff) = 0;
    virtual void wehren(Schiff& schiff) = 0;
    virtual void getroffen(void) = 0;
};

class Piratenschiff : public virtual Schiff {
public:
    Piratenschiff(int x, int y, Flagge flagge) : Schiff(x, y, flagge) {}

    // 7.2 c) implementation if abstract functions for Piratenschiff
    virtual void angreifen(Schiff& schiff) {
        std::cout << "Einsteigen!" << std::endl;
        schiff.getroffen();
    };

    virtual void wehren(Schiff& schiff) {
        if (schiff.zustand() == Versunken) { return; }
        std::cout << "Wir werden angegriffen, lasst uns zurückschlagen!" << std::endl;
        angreifen(schiff);
    }

    virtual void getroffen(void) {
        if (zustand_ == Intakt) { zustand_ = Beschaedigt; }
        else if (zustand_ == Beschaedigt) { zustand_ = Versunken; }
    }
};

class Handelsschiff : public virtual Schiff {
public:
    Handelsschiff(int x, int y, Flagge flagge) : Schiff(x, y, flagge) {}

    // 7.2 c) implementation if abstract functions for Piratenschiff
    virtual void angreifen(Schiff& schiff) { std::cout << "Wir kriegen euch! (Beleidigungen)" << std::endl; };

    virtual void wehren(Schiff& schiff) {
        return;
    }

    virtual void getroffen(void) {
        if (zustand_ == Versunken) {
            std::cout << "Nicht einmal Angst!" << std::endl;
            return;
        }
        zustand_ = Versunken;
        std::cout << "SOS ich sinke!" << std::endl;
    }
};

class Verraeterschiff : public Handelsschiff, public Piratenschiff {
public:
    Verraeterschiff(int x, int y, Flagge flagge) : Handelsschiff(x, y, flagge), Piratenschiff(x, y, flagge), Schiff(x, y, flagge) {}
    void angreifen(Schiff& schiff) { Piratenschiff::angreifen(schiff); }
    void wehren(Schiff& schiff) { Handelsschiff::wehren(schiff); }
    void getroffen(void) { Piratenschiff::getroffen(); }
};

// 7.2 b) function to return the distance between two ships, using the entfernung function for coordinates
double entfernung(Schiff const& schiff1, Schiff const& schiff2) {
    return entfernung(schiff1.position(), schiff2.position());
}

// 7.2 b) overloaded << operator for class Schiff, using Schiff::anzeigen()
std::ostream& operator<<(std::ostream& os, Schiff const& wert) {
    wert.anzeigen(os);
    return os;
}

/*******************************************
 * Ab hier nichts mehr ändern
 *******************************************/

void zusammentreffen(Schiff& schiff1, Schiff& schiff2)
{
  cout << "Vor dem Zusammentreffen: " << endl;
  cout << schiff1 << endl;
  cout << schiff2 << endl;
  cout << "Entfernung : " << entfernung(schiff1, schiff2) << endl;
  schiff1.begegnen(schiff2);
  cout << "Nach dem Zusammentreffen: " << endl;
  cout << schiff1 << endl;
  cout << schiff2 << endl;
}

int main()
{
  // Test Teil 1
  cout << "===== Test Teil 1 =====" << endl << endl;

  // Ein Piratenschiffnschiff bei 0,0
  Piratenschiff schiff1(0, 0, JollyRogers);
  cout << schiff1 << endl;

  // Ein Handelsschiff bei 25,0
  Handelsschiff schiff2(25, 0, CompagnieDuSenegal);
  cout << schiff2 << endl;

  cout << "Entfernung : " << entfernung(schiff1, schiff2) << endl;

  cout << "Die Schiffe bewegen sich..." << endl;
  cout << "hoch und nach rechts:" << endl;
  // Bewegt sich 75 Einheiten nach rechts und 10 nach oben
  schiff1.bewegen(75, 10);
  cout << schiff1 << endl;

  cout << "nach unten: " << endl;
  schiff1.bewegen(0, -5);
  cout << schiff1 << endl;

  cout << endl << "===== Test Teil 2 =====" << endl << endl;

  cout << "Verfeindetes Piratenschiff und Handelsschiff (zu weit auseinander):" << endl;
  zusammentreffen(schiff1, schiff2);

  cout << endl << "Verfeindetes Piratenschiff und Handelsschiff (nah):" << endl;
  schiff1.bewegen(-40, -2);
  schiff2.bewegen(10, 2);
  zusammentreffen(schiff1, schiff2);

  cout << endl << "Zwei verfeindete Piratenschiffen sind intakt (nah):" << endl;
  Piratenschiff schiff3(33, 8, CompagnieDOstende);
  zusammentreffen(schiff1, schiff3);

  cout << endl << "Beschaedigte Piratenschiffe, verfeindet:" << endl;
  zusammentreffen(schiff1, schiff3);

  cout << endl << "Verfeindete Handelsschiffe:" << endl;
  Handelsschiff schiff4(21, 7, CompagnieDuSenegal);
  Handelsschiff schiff5(27, 2, CompagnieDOstende);
  zusammentreffen(schiff4, schiff5);

  cout << endl << "Piratenschiff vs. Verräterschiff:" << endl;
  schiff3.aufsteigen();
  Verraeterschiff schiff6(32, 10, CompagnieDuSenegal);
  zusammentreffen(schiff3, schiff6);

  cout << endl << "Verraeterschiff vs. Piratenschiff:" << endl;
  zusammentreffen(schiff6, schiff3);

  return 0;
}
