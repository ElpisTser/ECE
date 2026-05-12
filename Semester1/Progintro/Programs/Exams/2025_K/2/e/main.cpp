#include <iostream>
using namespace std;

void solve(int rings, int source, int target, int auxil) {
    if (rings == 0) return;
    solve(rings-1, source, auxil, target);
    cout << "from " << source << " to " << target << endl;
    solve(rings-1, auxil, target, source);
}

int main () {
    solve(4,1,2,3);
}
