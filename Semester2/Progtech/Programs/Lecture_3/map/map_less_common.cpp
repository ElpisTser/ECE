#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    map<int, string> m;

    m.insert(make_pair(1, "one"));
    m.insert(make_pair(2,"two"));
    m.insert(make_pair(3,"three"));

    int x;
    cin >> x;

    map<int, string>::iterator p;
    p = m.find(x);

    if (p != m.end())
        cout << p->second << endl;
    else
        cout << "Didn't find element" << endl;
}