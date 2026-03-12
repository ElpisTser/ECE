#include <iostream>
#include "gcd.hpp"
using namespace std;

int main() {
    int a,b;
    cout << "Give me two numbers:" << endl;
    cin >> a >> b;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a,b) << endl;
}