#include <iostream>
using namespace std;

int abs(int a) {
    return (a > 0) ? a : -a;
}

void f (int* a, int* c, int n) {
    for (int i = 0; i < n; i++ ) {
        c[i] = 0;
        for (int j = 0; j < n; j++) {
            c[i] += abs(a[j] - a[i]);
        }
    }
}

int main() {
    int a[4] = { 0, 0, 1, 2};
    int c[4];
    
    f(a, c, 4);

    for (int i=0; i<4; i++) {
        cout << c[i] << endl;
    }
}