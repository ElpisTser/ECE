#include <iostream>

class complex {
public:
    complex(double r=0.0, double im=0.0);
    friend complex operator+(complex c1, complex c2);
    friend std::ostream& operator<<(std::ostream&, complex c);
private:
    double re, im;
};

complex::complex (double r, double i) {
    re = r;
    im = i;
}

complex operator+(complex c1, complex c2) {
    return complex(c1.re + c2.re, c1.im + c2.im);
}

std::ostream& operator<<(std::ostream& out, complex c) {
    out << c.re << "+" << c.im << "i";
    return out;
}

int main () {
    complex c1(3,4), c2(1,2);
    complex c = c1 + c2;
    std::cout << c << std::endl << "This is how operator oveloading works";
}