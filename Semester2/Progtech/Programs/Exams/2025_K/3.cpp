#include <iostream>
using namespace std;

int f(int x, int& c) {
    if (x == 100) return x;
    if (x > 100) throw x;
    ++c;
    return f(x+2, c);
}

int main() {
    int counter = 0, result = 0;
    try {
        result += f(1, counter);
    } catch (int e) {
        result += e;
    }
    cout << counter << " " << result << endl;
}