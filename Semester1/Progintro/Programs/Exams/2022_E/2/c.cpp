#include <iostream> 

int main() {
    int* p = new int;
    int* q = new int;
    int* t = new int;
    *p = *q = 17;
    *t = 5 * *p/2;
    q = p;
    *q /= 2;
    *q = *t + *p;
    *t += *q + *p;
    std::cout << *p + *q + *t;
}