#include <iostream>
using namespace std;

int a = 17, b = 7, c = 42;

void p(int a, int& c) {
    int b = 2*c++;
    cout << a << " " << b << " " << c << endl;
    if (a > c) {
        p(++b/5, c);
        cout << a << " " << b << " " << c << endl;
    } else {
        c *= 3;
    }
}

int main() {
    p(c,b);
    cout << a << " " << b << " " << c << endl;
}