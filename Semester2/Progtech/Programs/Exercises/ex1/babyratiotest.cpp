#include <iostream>
#include "babyratio.hpp"
using namespace std;

int main() {
    rational x(1,2);
    rational y(3,4);

    x.print();
    cout << ' ';
    y.print();
    cout << endl;

    rational a = x.add(y);
    a.print();
    cout << endl;

    rational s = x.sub(y);
    s.print();
    cout << endl;

    rational m = x.mul(y);
    m.print();
    cout << endl;

    rational d = x.div(y);
    d.print();
    cout << endl;

   
}