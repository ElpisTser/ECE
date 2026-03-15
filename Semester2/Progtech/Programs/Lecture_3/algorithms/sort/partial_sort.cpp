#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// partial_sort(first, middle, last) 
// partial_sort(first, middle, last, compare) 

int main() {
    vector<int> v = {4, 67, 5, 90, 36, 22, 10};

    partial_sort(v.begin(), v.begin()+3, v.end());
    // Sorts the first 3 elements (the 3 smallest); the rest remain unsorted

    vector<int>::iterator i;
    for (i=v.begin(); i<v.begin()+3; ++i) 
    cout << endl;

    for (int x : v)
        cout << x << " ";
    cout << endl;
}