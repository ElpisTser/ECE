#include <iostream>
#include <cmath>
#include "Complex.hpp"
using namespace std;

Complex::Complex(double r, double i) :
    re(r), im(i) {}

Complex::Complex(const Complex& c):
    re(c.re), im(c.im) {}

double Complex::norm() const{
    return sqrt(re * re + im * im);
}

bool Complex::operator>(const Complex& c) {
    return norm() > c.norm();
}

Complex Complex::operator=(const Complex& c) {
    im = c.im;
    re = c.re;
    return *this;
}

ostream& operator<<(ostream& out, Complex c) {
    out << c.re << " + " << c.im << "i";
    return out;
}