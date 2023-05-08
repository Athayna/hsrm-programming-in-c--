#include <iostream>
#include <string>

class Kuscheltier {
private:
    std::string tierart;
    std::string name;
    float preis;

public:
    //constructor
    Kuscheltier(std::string tierart, std::string name, float preis)
    : tierart(tierart), name(name), preis(preis) {
        std::cout << "[Ein Kuscheltier wurde hergestellt.]" << std::endl;
    }

    //copy constructor
    Kuscheltier(Kuscheltier const& tier)
    : tierart(tier.tierart), name(tier.name + "-Kopie"), preis(tier.preis) {
        std::cout << "[Ein Kuscheltier wurde kopiert.]" << std::endl;
    }

    //destructor
    ~Kuscheltier(void) {
        std::cout << "[Das Kuscheltier " << name << " wurde gelöscht.]" << std::endl;
    }

    std::string getTierart(void) const {return tierart;}
    std::string getName(void) const {return name;}
    float getPreis(void) const {return preis;}
    void setPreis(float preis) {this->preis = preis;}
};

void etikett(Kuscheltier const& tier) {
    std::cout << "Etikett:" << std::endl
    << "Hallo, mein Name ist " << tier.getName() << std::endl
    << "Ich bin ein " << tier.getTierart() << " und koste " << tier.getPreis() << " Euro." << std::endl;
}

int main(void) {
    Kuscheltier* pingu; //pointer: doesn't instantiate
    { 
        Kuscheltier ssss("Cobra", "Ssss", 10.00F); //instance of Kuscheltier in nested scope
        pingu = new Kuscheltier("Pinguin", "Pingu", 20.00F); //pingu now instantiated
    } //end of ssss scope -> deletes object
    Kuscheltier pingu_klon(*pingu); //clones object and creates new instance
    etikett(pingu_klon);
    delete pingu; //deletes pingu
    return 0;
} //end of program -> deletes pingu_klon and generally all objects