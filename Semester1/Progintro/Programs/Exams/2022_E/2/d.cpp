#include <iostream>

int fun(int n) {
    if (n <= 1) return 1;
    else return 2 * fun(n-2);
}

int main() {
    std::cout << fun(17);
}