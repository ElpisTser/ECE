#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void print_vector(const vector<int> &v) {
    for (int x : v)
        cout << x;
}

// sort(first, last)
// sort(first, last, compare) 

int main() {
    vector<int> v1 = {3, 2, 9, 7, 5};
    vector<int> v2 = {4, 3, 6, 5, 1, 8, 7};

    // normal(asc) sort
    cout << "v1: ";
    print_vector(v1);
    cout << endl;

    sort(v1.begin(), v1.end());
    cout << "v1 sorted: ";
    print_vector(v1);
    cout << endl;

    //desc sort
    cout << "v2: ";
    print_vector(v2);
    cout << endl;

    sort(v2.begin(), v2.end(), greater<int>()); // need to include <functional> to use greater<int>()
    cout << "v2 sorted in descending order: ";
    print_vector(v2);
    cout << endl;
}