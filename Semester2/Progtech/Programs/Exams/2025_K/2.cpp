#include <iostream>
using namespace std;

class object {
public:
    object() { cout << 1; }
    object(const object& x) { cout << 2;}
    ~object() { cout << 3; }
    void operator=(const object& x) { cout << 4; }
};

int main() {
    object a;
    object b(a);
    object c = a;
    object d;
    d = b;
}