#include <iostream>
#include "Complex.hpp"
using namespace std;

int main() {
    Complex c1(1,3);
    Complex c2(2,4);
    cout << "C2: " << c1 << endl << "C2: " <<c2 << endl;
    cout << "Norm of C1 = " << c1.norm() << endl;
    cout << "Norm of C2 = " << c2.norm() << endl;
    if (c2 > c1) cout << "C2 bigger than C1";
}