#include <iostream>
using namespace std;

class one {
public:
    one() { cout << 'a'; }
    one(const one& o) { cout << 'b'; }
    ~one() { cout << 'c'; }
};

void f(one b) { cout << 'f'; }

int main() {
    one a;
    f(a);
    cout << 'm';
}
