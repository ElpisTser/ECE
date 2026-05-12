#include <cstdio>
using namespace std;

int main() {
    int n = 1, s = 1, t = 0;
    do {
        n *= 2;
        s += n;
        ++t;
    } while (s <= 2000000 && t <= 24);

    printf("%d %d %d", n, s, t);
}