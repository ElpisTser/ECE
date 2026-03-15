#include <iostream>
#include <list>

using namespace std;
 
int  main() {
    list<int> l;
    for (int i=0; i<10; i++) {
        if (i % 2 == 0) l.push_front(i);
        else l.push_back(i);
    }

    for (int i=0; !l.empty(); i++) {
        if (i%2 == 0) {
            cout << l.back();
            l.pop_back();
        } else {
            cout << l.front();
            l.pop_front(); 
        }
    }
    cout << endl;

    if (l.empty()) cout << "List is empty" << endl;
}

