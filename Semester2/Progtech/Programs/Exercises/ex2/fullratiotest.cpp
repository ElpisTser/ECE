#include <iostream>
#include "fullratio.hpp"
using namespace std;

int main() {
    rational a(1,2);
    rational b(3, 4);
    rational c(3, 8);

    cout << a << " " << b << endl;
    cout << a + b << endl << a - b << endl << a * b << endl << a / b << endl;
    cout << a + b + c << endl;
    cout << a - b + c << endl;
}