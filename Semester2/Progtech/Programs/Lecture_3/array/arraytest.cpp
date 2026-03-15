#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
    array<int, 10> a; // similar tp int a[10]
    array<string, 20> s;

    a[1] = 42;
    s[2] = "Hello";

    cout << a[1] << endl << s[2] << endl;
}

// <array> has similar behavior to standard arrays
// constant size, know at compile time