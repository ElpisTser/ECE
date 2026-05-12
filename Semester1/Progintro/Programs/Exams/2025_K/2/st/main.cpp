#include <iostream>

int main() {
    int a[] = {32, 26, 50, 1, 8, 9, 42, 15, 17, 20};
    int* p = &a[4];
    int* q = &a[6];
    p = q--;
    std::cout << *p << " " << *q << " " << a[3];
}