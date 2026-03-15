#include <iostream>
#include <utility>

using namespace std;

int sum(const pair<int, int> &p) {
    return p.first + p.second;
}

int main() {
    pair<int, int> p(1,2);

    cout << sum(p) << endl;
    cout << sum(make_pair(3,4)) << endl;
}