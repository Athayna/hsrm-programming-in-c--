#include <iostream>
using namespace std;

class Patient {
  private:
    double weight, height;

  public:
    void init(double weight, double height) {
      if (weight <= 0) {this->weight = 0;}
      else {this->weight = weight;}
      if (height <= 0) {this->height = 0;}
      else {this->height = height;}
    }

    void anzeigen() const {
      cout << "Patient: " << weight << " kg für " << height <<" m." << endl;
    }

    double gewicht() const {return weight;}
    double groesse() const {return height;}
    double bmi() const {
      if (height == 0)
        return 0;
      else
        return weight / (height * height);
    }
};

int main()
{
  Patient jemand;
  double gewicht, groesse;
  do {
    cout << "Entrez un gewicht (kg) et une groesse (m) : ";
    cin >> gewicht >> groesse;
    jemand.init(gewicht, groesse);
    jemand.anzeigen();
    cout << "bmi : " << jemand.bmi() << endl;
  } while (gewicht * groesse != 0.0);
  return 0;
}
