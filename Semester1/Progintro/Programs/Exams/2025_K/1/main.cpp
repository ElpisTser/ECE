#include <cstdio>

int a = 6, b = 8, c = 12;

void p(int a, int& c) {
    int b = c + a++;
    printf("%d %d %d\n", a, b, c);
    if (a > c) { p(a, b); printf("%d %d %d\n", a, b, c);}
    else { a *= 2; printf("%d %d %d\n", a, b, c);}
}

int main() {
    p(b, a);
    printf("%d %d %d\n", a, b, c);
}