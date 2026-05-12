#include <cstdio>
using namespace std;

int main() {
    int a[] = { 1, 8, 9, 42, 15, 17, 20, 32, 26, 60 };

    int *p = &a[2], *q = &a[5];
    p = q--;
    printf("%d %d %d", *p, *q, a[3]);
}