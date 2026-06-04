#include <iostream>
using namespace std;

class one {
protected:
    int n;
public:
    one(int i) : n(i) {}
    int get() const {
        return n;
    }
    virtual void set(int i) {
        n = i;
    }
};

class two: public one {
public:
    two(int i) : one(2 * i) {}
    virtual void set(int i) override { 
        n *= i;
    }
};

int main() {
    one a(5);
    two b(5);

    one *p = &a, *q = &b;

    p->set(7);
    b.set(3);
    q->set(2);
    
    cout << a.get() << " " << b.get() << endl;
}