#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   vector<int> v(100);
   v[55] =42;
   
   int x;
   cin >> x;

   vector<int>::iterator i = find(v.begin(), v.end(), x);
   if (i != v.end()) {
    *i = 99;
    cout << "Found at index: " << (i - v.begin()) << endl;
    cout << v[55] << endl;
   } else {
    cout << "not found" << endl;
   }
}

// We can use binary search if the container is sorted, e.g.
// vector<int>::iterator i = 
// binary_search(v.begin(), v.end(), 42);