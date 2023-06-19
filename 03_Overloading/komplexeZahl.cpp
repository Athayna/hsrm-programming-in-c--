#include <iostream>

class KomplexeZahl {
private:
    double real, imaginary;

public:
    // 3.2 b) default constructor necessary for instantiation without parameters
    KomplexeZahl() {}
    // 3.2 b) constructor to set real and imaginary part of complex number
    KomplexeZahl(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // 3.2 c) internally overload equality operator
    bool operator==(KomplexeZahl const& z2) {
        return this->real == z2.real && this->imaginary == z2.imaginary;
    }

    // getters for real and imaginary part
    double getReal(void) const {return real;}
    double getImaginary(void) const {return imaginary;}
};

// 3.2 c) externally overload << operator to print complex number
std::ostream& operator<<(std::ostream& os, const KomplexeZahl& zahl) {
    os << zahl.getReal() << ((zahl.getImaginary() > 0) ? "+" : "-") << zahl.getImaginary() << "i";
    return os;
}

// 3.2 d) externally overload addition operator to add two complex numbers
const KomplexeZahl operator+(KomplexeZahl z1, KomplexeZahl const& z2) {
    
}

int main(void) {
    // test code with given examples from exercise sheet

    // 3.2 b (constructors)
    KomplexeZahl default_zahl; 
    KomplexeZahl null_zahl(0.0, 0.0); 
    KomplexeZahl eins(1.0, 0.0); 
    KomplexeZahl i(0.0, 1.0); 
    KomplexeZahl j;

    // 3.2 c (operators == and <<)
    std::cout << null_zahl << " ==? " << default_zahl; 
    if (null_zahl == default_zahl) std::cout << " ja" << std::endl; 
    else std::cout << " nein" << std::endl; 
    std::cout << null_zahl << " ==? " << i; 
    if (null_zahl == i) std::cout << " ja" << std::endl; 
    else std::cout << " nein" << std::endl;

    // 3.2 d (arithmetic operators)
    j = eins + i; 
    std::cout << eins << " + " << i << " = " << j << std::endl; 
    KomplexeZahl drei(eins); 
    drei += eins; 
    drei += 1.0; 
    std::cout << eins << " + " << eins << " + 1.0 = " << drei << std::endl; 
    KomplexeZahl zwei(drei); 
    zwei -= eins; 
    std::cout << drei << " - " << eins << " = " << zwei << std::endl; 
    drei = 1.0 + zwei; 
    std::cout << "1.0 + " << zwei << " = " << drei << std::endl;

    // 3.2 e (multiplication and division)
    KomplexeZahl z(i* i); 
    std::cout << i << " * " << i << " = " << z << std::endl; 
    std::cout << z << " / " << i << " = " << z / i << " = "; 
    std::cout << (z /= i) << std::endl;

    // 3.2 f (leftover operators)
    KomplexeZahl k(2.0,-3.0); 
    z = k; 
    z *= 2.0; 
    z *= i; 
    std::cout << k << " * 2.0 * " << i << " = " << z << std::endl; 
    z = 2.0 * k * i / 1.0; 
    std::cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << std::endl;

    return 0;
}