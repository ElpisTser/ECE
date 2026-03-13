#include "babyratio.hpp"
#include <iostream>
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

rational rational::add(rational r) {
    int n = nom * r.den + r.nom *den;
    int d = den * r.den;
    int g = gcd(n,d);
    return rational(n/g, d/g);
}

rational rational::sub(rational r) {
    int n = nom * r.den - r.nom * den;
    int d = den * r.den;
    int g = gcd(n,d);
    return rational(n/g, d/g);
}

rational rational::mul(rational r) {
    int n = nom * r.nom;
    int d = den * r.den;
    int g = gcd(n,d);
    return rational(n/g, d/g);
}

rational rational::div(rational r) {
    int n = nom * r.den;
    int d = den * r.nom;
    int g = gcd(n,d);
    return rational(n/g, d/g);
}

void rational::print() {
    cout << nom << '/' << den;
}