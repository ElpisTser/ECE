#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    for (int i=0; i<10; i++)
        l.push_back(i);

    list<int>::iterator i;
    for (i=l.begin(); i != l.end(); ++i)
        cout << *i;
    cout << endl;

    // We can do the same with the following simpler syntax
    for (int x : l)
        cout << x;
    cout << endl;

    // If we want to actually change the values we have to call by reference
    for (int &x : l)
        x = 4;

    // We can do the same as the first iteration, but passing by const reference so we don't have to acopy every element while going though the list
    for (const int &x : l)
        cout << x;
    cout << endl;
}

/*
Notes about std::list and iterators

- std::list<T> is a doubly linked list container in the C++ STL.
- Elements are not stored contiguously in memory like in std::vector or std::array.
- Each element is stored in a separate node linked to the previous and next element.

Advantages:
- Fast insertion and deletion anywhere in the list (O(1)) if you already have an iterator.
- push_back() and push_front() are efficient.

Disadvantages:
- No direct indexing (you cannot use l[3]).
- Accessing elements requires iteration, which is slower than vectors.
- Higher memory overhead due to storing pointers between nodes.

Iterators:
- l.begin() returns an iterator to the first element.
- l.end() returns an iterator one position past the last element.
- *iterator is used to access the value stored at that position.

Range-based loops:
- for (int x : l) copies each element.
- for (int &x : l) allows modifying elements.
- for (const int &x : l) avoids copying and prevents modification.

General rule:
Use std::vector by default. Use std::list only when you need frequent insertions
or deletions in the middle of the container.
*/