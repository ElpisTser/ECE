#include <iostream>
using namespace std;

int main() {
    int f[5], *p;
    for (int n=0; n<5; n++) f[n] = 0;
    p = &f[4];
    *p = 8;
    p--;
    *p = 6;
    p = &f[0];
    *p = 10;
    p += 3;
    *p = 7;
    for (int n=0; n<5; n++)
        cout << f[n] << " "; 
}