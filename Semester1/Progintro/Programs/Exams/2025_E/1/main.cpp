#include <cstdio>
using namespace std;

int a = 7 , b = 2, c = 4;

void p(int &x, int c) {
    int y = x++ + b++;
    printf("%d %d %d %d %d\n", a, b, c, x, y);
    if (a > y++) p(y,x);
    printf("%d %d %d %d %d\n", a, b, c, x, y);
}

int main() {
    p(c,c);
    printf("%d %d %d\n", a, b, c);
}