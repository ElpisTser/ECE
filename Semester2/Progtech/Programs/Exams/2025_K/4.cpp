#include <iostream>
using namespace std;

class S {
private:
    int a;
    static int b;
public:
    S(int n) : a(b) { b = n; }
    ~S() { b = a; }
    void status() const { cout << a << " " << b << " "; }
};

int S::b = 0;

void foo(const S& z) {
    S y(7);
    y.status();
    z.status();
}

int main() {
    S x(5);
    x.status();
    foo(x);
    x.status();
}