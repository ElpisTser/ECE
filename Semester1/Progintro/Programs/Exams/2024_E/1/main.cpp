#include <iostream>
using namespace std;

int a = 6, b = 2, c = 15;

void f(int a, int& c) {
    int b = c-- + a;
    cout << a << " " << b << " " << c << endl;
    if ( a < c) { 
        f(b, c);
        cout << ++a << " " << b++ << " " << c << endl;
    } else {
        a /= 2;
        cout << a << " " << b-- << " " << --c << endl;
    }
}

int main() {
    f(b, a);
    cout << a << " " << b << " " << c << endl;
}