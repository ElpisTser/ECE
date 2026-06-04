#include <iostream>
using namespace std;

class One {
protected:
    double s;
public:
    One(double x) : s(x) {}
    One(const One& o) : s(o.s) {}
    virtual double f() { return s; }
};

class Two : public One {
public:
    Two(double x) : One(x) {}
    double f () override { return s * s;}
};

int main() {
    One a(3);
    Two b(6);
    One *p = &a, *q = &b, c(b);
    cout << p->f() << " " << q->f() << " " << c.f() << endl;
}

