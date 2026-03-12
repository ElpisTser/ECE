#include <iostream>

class complex {
public:
    complex (double r=0.0, double i=0.0);
    complex add(complex c);
    void print(std::ostream& out);
private:
    double re, im;
};

complex::complex (double r, double i) {
    re = r;
    im = i;
}

complex complex::add(complex c) {
    return complex(re + c.re, im + c.im);
}

void complex::print(std::ostream& out) {
    out << re << "+" << im << "i" << std::endl;
}

int main() {
    complex c1(3,4), c2(1,2);
    complex c = c1.add(c2);
    c.print(std::cout);
}



