#include <iostream>
#include <stdexcept>
#include "ChessBoardArray.hpp"
using namespace std;

int main() {
    ChessBoardArray a(4,1);
    a[3][1] = 42;
    a[4][4] = 17;
    try {
        a[2][1] = 7;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    cout << a;
} 