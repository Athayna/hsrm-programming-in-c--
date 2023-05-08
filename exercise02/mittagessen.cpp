#include <iostream>

class Vorspeise {
public:
    Vorspeise(void) {
        std::cout << "Es ist Zeit fuer das Mittagessen. Vorspeise?" << std::endl;
    }

    ~Vorspeise(void) {
        std::cout << "Dann kommt die Hauptspeise!" << std::endl;
    }

    void zugabe(void) {
        std::cout << "Nachschlag?" << std::endl;
    }
};

int main(void) { 
    Vorspeise amuse_bouche; 
    std::cout << "Gerne!" << std::endl; 
    amuse_bouche.zugabe(); 
    std::cout << "Nein, danke." << std::endl; 
    return 0; 
}