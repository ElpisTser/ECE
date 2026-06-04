#include <iostream>
using namespace std;

int f(int x) {
    try {
        if (x > 3) throw x+1;
        else return x;
    } catch (int e) {
        if (e > 5) throw e + 1;
        cout << "F" << e;
        return e;
    }
}

int main() {
    try {
        for (int i = 1; i <=3; i++)
            cout << f(i * i);
    } catch (int e) {
        cout << "M" << e;
    }
}