#include <iostream>

class Papier {
    private:
        int alter, betrag;
    
    public:
        void schreibPapier(int alter, int betrag) {this->alter = alter; this->betrag = betrag;}
        int getAlter() const {return alter;}
        int getBetrag() const {return betrag;}
};

class Magier {
    private:
        int alter, betrag;

    public:
        void berechneWerte(int ergebnis) {
            ergebnis += 115;
            betrag = ergebnis % 100;
            alter = ergebnis / 100;
        }
        int getAlter() const {return alter;}
        int getBetrag() const {return betrag;}
};

class Assistent {
    private:
        Papier papier;
        int ergebnis;

    public:
        void setPapier(Papier papier) {this->papier = papier;}
        void berechneErgebnis() {ergebnis = (papier.getAlter() * 2 + 5) * 50 + papier.getBetrag() - 365;}
        int getErgebnis() const {return ergebnis;}
};

class Zuschauer {
    private:
        int alter, betrag;
        Papier papier;

    public:
        void setAlter(std::istream& in) {in >> alter;}
        int getAlter() const {return alter;}
        void setBetrag(std::istream& in) {in >> betrag;}
        int getBetrag() const {return betrag;}
        Papier getPapier() const {return papier;}
};


int main(void) {
    std::cout << "[Zuschauer] (Ich betrete die Szene)" << std::endl;
    Zuschauer z;
    std::cout << "Wie alt bin ich? ";
    z.setAlter(std::cin);
    do {
        std::cout << "Wie viel Geld habe ich in meiner Tasche (<100)? ";
        z.setBetrag(std::cin);
    } while (z.getBetrag() < 0 || z.getBetrag() > 99);
    std::cout << "[Zuschauer] (Ich bin hier)" << std::endl;
    std::cout << "[Magier] ein kleiner Zaubertrick..." << std::endl;
    std::cout << "[Zuschauer] (Ich schreibe das Papier)" << std::endl;
    z.getPapier().schreibPapier(z.getAlter(), z.getBetrag());
    std::cout << "[Zuschauer] (Ich zeige das Papier)" << std::endl;
    std::cout << "[Assistent] (Ich lese das Papier)" << std::endl;
    Assistent a;
    a.setPapier(z.getPapier());
    std::cout << "[Assistent] (Ich rechne im Kopf)" << std::endl;
    a.berechneErgebnis();
    std::cout << "[Assistent] Ich sage: " << a.getErgebnis() << "!" << std::endl;
    std::cout << "[Zauberer]" << std::endl;
    Magier m;
    m.berechneWerte(a.getErgebnis());
    std::cout << "- hmm... Ich sehe, dass du " << m.getAlter() << " Jahre alt bist und " << m.getBetrag() << " Euro in der Tasche hast!" << std::endl;
    return 0;
}