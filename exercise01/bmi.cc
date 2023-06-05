#include <iostream>

class Patient {
private:
    double weight, height;

public:
    // init method replacing a constructor
    void init(double weight, double height) {
        this->weight = (weight <= 0) ? 0 : weight;
        this->height = (height <= 0) ? 0 : height;
    }

    // method to display the patient's weight and height
    void anzeigen(void) const {
        std::cout << "Patient: " << weight << " kg für " << height << " m." << std::endl;
    }

    // getter method to return the patient's weight
    double gewicht(void) const { return weight; }
    // getter method to return the patient's height
    double groesse(void) const { return height; }
    // method to calculate and return the patient's BMI
    double bmi(void) const { return ((height == 0) ? 0 : weight / (height * height)); }
};

int main() {
    // given code by the professor to test the class (translated output to German)
    Patient jemand;
    double gewicht, groesse;
    do {
        std::cout << "Gewicht (kg) und Groesse (m): ";
        std::cin >> gewicht >> groesse;
        jemand.init(gewicht, groesse);
        jemand.anzeigen();
        std::cout << "BMI: " << jemand.bmi() << std::endl;
    } while (gewicht * groesse != 0.0);
    return 0;
}
