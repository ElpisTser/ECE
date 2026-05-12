#include <iostream>
using namespace std;

int f(int m, int k) {
    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % m ==0) continue;
        else if (i % k ==0) break;
        ++count;
    }
    return count;
}

int main() {
    cout << f(11,27);
}