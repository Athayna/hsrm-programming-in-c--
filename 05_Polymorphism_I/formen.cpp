#include <iostream>

class Form {
protected:
public:
    virtual void beschreibung() { std::cout << "Dies ist eine Form!" << std::endl; }
    void anzeigeBeschreibung(Form& f) { f.beschreibung(); }
};

class Kreis : public Form {
private:
public:
    void beschreibung() override { std::cout << "Dies ist ein Kreis!" << std::endl; }
};

int main(void) {
    // test the classes and output with code provided by the professor
    Form f;
    Kreis k;
    f.beschreibung();
    k.beschreibung();

    Form f2(k);
    f2.beschreibung();

    f2.anzeigeBeschreibung(f2);

    return 0;
}