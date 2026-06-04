#include <iostream>
using namespace std;

class C {
public:
    static void setX(int a) { x = a; }
    C(int b) : y(b) {}
    void status() const { cout << x << y; }
private:
    static int x;
    int y;
};

int C::x = 0;

int main() {
    C c1(1); c1.status(); c1.setX(3);
    C c2(4); c2.status(); c2.setX(2);
    C c3(5); c3.status(); cout << endl;
}