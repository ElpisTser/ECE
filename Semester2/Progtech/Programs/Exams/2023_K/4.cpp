#include <iostream>
using namespace std;

class S {
private:
    static int s, n;
    int data;
public:
    static void f(int a) { s += a; n++; }
    S(int b) : data(b) { f(b); }
    S() : data(0) { f(data); }
    void status() { cout << s << " " << n << " "; }
};

int S::s = 0;
int S::n = 0;

int main() {
    S c1(1);
    c1.status();
    c1.f(1);
    S c2(2);
    c2.status();
    c2.f(3);
    S c3;
    c3.status();
}