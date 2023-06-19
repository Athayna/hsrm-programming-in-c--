#include <iostream>
#include <cmath>

class Punkt3D {
protected:
    double x, y, z;

public:
    // 4.3 a) replace init function with a constructor
    Punkt3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // print function is now virtual to allow overriding/polymorphism in derived classes and ostream parameter is now passed by reference
    virtual void print(std::ostream& os) const {
        os << "(" << x << ", " << y <<", " << z << ")" << std::endl;
    }

    // 4.3 a) replaced "vergleichen" function with an overloaded equality operator
    virtual bool operator==(Punkt3D const& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
 
    // getters
    double getX(void) const { return x; }
    double getY(void) const { return y; }
    double getZ(void) const { return z; }

    // setters
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }
};

class Vektor : public Punkt3D {
public:
    // constructor using base class constructor
    Vektor(double x, double y, double z) : Punkt3D(x, y, z) {}

    // 4.3 b) overload addition-assignment operator
    Vektor& operator+=(Vektor const& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    // 4.3 b) overload subtraction-assignment operator
    Vektor& operator-=(Vektor const& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    // 4.3 b) overload negative Vektor
    const Vektor operator-(void) const {
        return Vektor(-x, -y, -z);
    }

    // 4.3 b) overload multiplication-assignment operator
    Vektor& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    // 4.3 b) norm of Vektor
    double norm(void) const {
        return std::sqrt(x * x + y * y + z * z);
    }
};

// 4.3 b) overload addition operator
const Vektor operator+(Vektor v1, const Vektor& v2) {
    v1.setX(v1.getX() + v2.getX());
    v1.setY(v1.getY() + v2.getY());
    v1.setZ(v1.getZ() + v2.getZ());
    return v1;
}

// 4.3 b) overload subtraction operator
const Vektor operator-(Vektor v1, const Vektor& v2) {
    v1.setX(v1.getX() - v2.getX());
    v1.setY(v1.getY() - v2.getY());
    v1.setZ(v1.getZ() - v2.getZ());
    return v1;
}

// 4.3 b) overload multiplication operator
const Vektor operator*(Vektor v, double scalar) {
    v.setX(v.getX() * scalar);
    v.setY(v.getY() * scalar);
    v.setZ(v.getZ() * scalar);
    return v;
}

// 4.3 b) overload multiplication operator
const Vektor operator*(double scalar, Vektor const& v) {
    return Vektor(v.getX() * scalar, v.getY() * scalar, v.getZ() * scalar);
}

// 4.3 b) overload scalar product of two Vektors
double operator*(Vektor const& v1, Vektor const& v2) {
    return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

// 4.3 b) calculate angle between two Vektors
double angle(Vektor const& v1, Vektor const& v2){ 
    return std::acos((v1 * v2) / (v1.norm() * v2.norm())); 
} 

int main(void) {
    // 4.3 c) test methods (output set to match the professor's output on the exercise sheet)
    // setup Vektors for testing
    Vektor v1(1, 2, -0.1), v2(2.6, 3.5, 4.1);
    
    // test print and setup of Vektors
    std::cout << "Vektor V1: ";
    v1.print(std::cout);
    std::cout << "Vektor V2: ";
    v2.print(std::cout);

    // test addition of V1 and V2
    std::cout << "V1 + V2: ";
    (v1 + v2).print(std::cout);

    // test subtraction of V1 and V2
    std::cout << "V1 - V2: ";
    (v1 - v2).print(std::cout);

    // test negative Vektor of V1
    std::cout << "-V1: ";
    (-v1).print(std::cout);

    // test scarar-Vektor multiplication
    std::cout << "3.2 * V1: ";
    (3.2 * v1).print(std::cout);

    // test scalar product of V1 and V2
    std::cout << "V1 * V2: " << v1 * v2 << std::endl;

    // test norm of Vektors
    std::cout << "Normale von V1: " << v1.norm() << std::endl;
    std::cout << "Normale von V2: " << v2.norm() << std::endl;
    std::cout << "Normale von V1+V2: " << (v1 + v2).norm() << std::endl;

    // test angle between two Vektors
    std::cout << "Winkel zwischen V1 und V2: " << angle(v1, v2) << std::endl;
    std::cout << "Winkel zwischen V2 und V1: " << angle(v2, v1) << std::endl;

    return 0;
}