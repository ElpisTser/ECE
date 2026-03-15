#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool abs_compare (int x, int y) {
    return abs(x) < abs(y);
}

int main() {
    vector<int> v = {-2, 1, 5, -4, 9, 7};

    sort(v.begin(), v.end(), abs_compare);

    for (int i : v)
        cout << i << " ";
    cout << endl;    
}