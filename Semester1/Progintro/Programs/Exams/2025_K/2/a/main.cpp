#include <iostream>
using namespace std;

int f(int x, int c) {
    x /= 2;
    if (x < 1) return 1;
    c = 2 * c;
    return c + f(x,c);
}

int main() {
    cout << f(5,7);
}