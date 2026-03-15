#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// nth_element(first, nth, last) 
// nth_element(first, nth, last, compare)

// min_element(first, last) 
// min_element(first, last, compare) 

// max_element(first, last) 
// max_element(first, last, compare) 

int main() {
    vector<int> v = {4, 67, 5, 90, 36, 22, 10};

    nth_element(v.begin(), v.begin()+3, v.end()); 
    // Places the 4th smallest element at index 3; elements before are <= it, after are >= it (not sorted)

    for (int x : v)         
        cout << x << " ";
    cout << endl;

    vector<int>::iterator min, max;
    min = min_element(v.begin(), v.end());
    // Returns an iterator pointing to the smallest element, doesn't modify the container
    cout << *min << endl;

    max = max_element(v.begin(), v.end());
    // Returns an iterator pointing to the biggest element, doesn't modify the container
    cout << *max << endl;
}