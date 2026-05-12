#include <iostream>

int f(int &x, int& c) {
    c = c / 2;
    if (c == 0) return 1;
    x = 2 * x;
    return f(x, c) + x;
}

int main() {
    int p = 5, q = 7;
    std::cout << f(p, q) << std::endl << p << std::endl << q;
}