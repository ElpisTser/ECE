#include <iostream>

class Complex {
public:
    Complex(double r, double i);
    Complex(const Complex &c);
    double norm() const;
    bool operator>(const Complex& c);
    Complex operator=(const Complex& c);
    friend std::ostream& operator<<(std::ostream& out, Complex c);
private:
    double re, im;
};