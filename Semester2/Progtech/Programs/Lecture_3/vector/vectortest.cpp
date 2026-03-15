#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> x(100), y(200, 42); 
    cout << x[55] << endl; // 0
    cout << y[199] << endl; // 42
    cout << x.size() << endl; // 100

    x.push_back(17);
    cout << x[100] << endl; // 17
    cout << x.size() << endl; // 101

    x.pop_back();
    cout << x.size() << endl; // 100
}

/*
Notes about std::vector<T>

- vector<T> is a container that behaves similarly to an array, but it is part of the C++ STL.
- Unlike std::array, a vector has variable size: elements can be added or removed dynamically.
- Insertion and removal are efficient at the end of the container.

Common operations:
    push_back(value)  -> adds an element to the end of the vector
    pop_back()        -> removes the last element

Other useful features:
    size()            -> returns the current number of elements
    operator[]        -> access elements like an array

Special case:
    vector<bool> has a special optimized implementation that stores bits
    instead of full boolean values to save memory.
*/