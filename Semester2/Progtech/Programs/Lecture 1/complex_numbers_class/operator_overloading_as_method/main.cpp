#include <iostream>

class complex {
public:
    complex(double r = 0.0, double i = 0.0);

    // Overload + as a member function
    // c1 + c2 is interpreted as c1.operator+(c2)
    // The left operand (c1) is the calling object (this)
    // The right operand (c2) is passed as a parameter
    complex operator+(complex c);

    // Overload << as a non-member (friend) function
    // std::cout << c calls operator<<(std::cout, c)
    // The first operand is std::ostream, which is not our class
    // Therefore it cannot be a member function of complex    
    friend std::ostream& operator<<(std::ostream& out, complex c);
private:
    double re, im;
};

complex::complex(double r, double i) {
    re = r;
    im = i;
}

complex complex::operator+(complex c) { 
    return complex(re + c.re, im + c.im);
}

std::ostream& operator<<(std::ostream& out, complex c) {
    out << c.re << "+" << c.im << "i";
    return out;
}

int main() {
    complex c1(3,4), c2(1,2);
    complex c = c1 + c2;
    std::cout << c << std::endl << "This is how operator oveloading works" << std::endl;

    complex c3(1);
    std::cout << c3;
}

