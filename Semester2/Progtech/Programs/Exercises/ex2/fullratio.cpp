#include <iostream>
#include "fullratio.hpp"
using namespace std;

rational::rational(int n, int d): nom(n), den(d) {}

int rational::gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (a > 0 && b > 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

rational operator + (const rational &x, const rational &y) {
    int n = x.nom * y.den + y.nom * x.den;
    int d = x.den * y.den;
    int g = rational::gcd(n,d);
    return rational(n/g, d/g);
}

rational operator - (const rational &x, const rational &y) {
    int n = x.nom * y.den - y.nom * x.den;
    int d = x.den * y.den;
    int g = rational::gcd(n,d);
    return rational(n/g, d/g);
}

rational operator * (const rational &x, const rational &y) {
    int n = x.nom * y.nom;
    int d = x.den * y.den;
    int g = rational::gcd(n,d);
    return rational(n/g, d/g);
}

rational operator / (const rational &x, const rational &y) {
    int n = x.nom * y.den;
    int d = x.den * y.nom;
    int g = rational::gcd(n,d);
    return rational(n/g, d/g);
}

ostream& operator << (ostream &out, const rational &r) {
    out << r.nom << '/' << r.den;
    return out;
}