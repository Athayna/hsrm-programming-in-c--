#include <iostream>

class Tier {
public:
    Tier() { std::cout << "Tier created" << std::endl; }
    ~Tier() { std::cout << "Tier destroyed" << std::endl; }
};

class Vivipare : public virtual Tier {
protected:
    unsigned term;

public:
    Vivipare(unsigned term = 270) : term(term) { std::cout << "Vivipar mit term = " << term << std::endl; }

    void geburt(std::ostream& os) const {
        os << "Nach " << term << " Schwangerschaftstagen habe ich gerade ein neues Baby zur Welt gebracht." << std::endl;
    }
};

class Ovipare : public virtual Tier {
protected:
    unsigned eggs;

public:
    Ovipare(unsigned eggs) : eggs(eggs) { std::cout << "Ovipar mit eggs = " << eggs << std::endl; }

    void geburt(std::ostream& os) const {
        os << "Ich habe gerade etwa " << eggs << " Ei(er) gelegt." << std::endl;
    }
};

class Ovovivipare : public Vivipare, public Ovipare {
protected:
    bool rare;

public:
    Ovovivipare(unsigned term, unsigned eggs, bool rare = false) : Vivipare(term), Ovipare(eggs), rare(rare) {}
    
    void geburt(std::ostream& os) const {
        os << "Nach " << term << " Schwangerschaftstagen habe ich gerade " << eggs << " Baby(s) zur Welt gebracht" << std::endl;
    }
};

int main(void) {
    Ovovivipare o(200, 5, true);
    o.Vivipare::geburt(std::cout);
    o.geburt(std::cout);
    return 0;
}