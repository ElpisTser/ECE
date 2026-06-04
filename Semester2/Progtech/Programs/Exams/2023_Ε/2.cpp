#include <iostream>
using namespace std;

class A{
public:
    A() { cout << "A"; }
    ~A() { cout << "~A"; }
    void o() { cout << "a"; }
};

class B: public A {
public:
    B() { cout << "B"; }
    ~B() { cout << "~B"; }
    void o() { cout << "b"; }
};

int main() {
    B a;
    A *b = &a;
    b->o();
    a.o();
}