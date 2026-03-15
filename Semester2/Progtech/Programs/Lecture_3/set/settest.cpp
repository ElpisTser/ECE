#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;

    while (true) {
        int x;
        cin >> x;

        if (s.find(x) == s.end())
            s.insert(x);
        else {
            cout << "You lose, I've seen " << x << " before!" << endl;
            break;
        }
    }
}

/*
Notes about std::set

- std::set<T> is an STL container that stores unique elements.
- If you try to insert a value that already exists, the set will not add it again.

Main properties:
- Elements are automatically kept in sorted order.
- Duplicate values are not allowed.
- Searching, inserting, and removing elements take O(log n) time.

Common operations:
    s.insert(x)    -> inserts element x into the set
    s.find(x)      -> returns an iterator to x if it exists
                      otherwise returns s.end()
    s.erase(x)     -> removes element x
    s.size()       -> number of elements in the set

Iterating through a set:
    for (const int &x : s)
        cout << x;

Important notes:
- Elements in a set cannot be modified directly because that could break
  the sorted ordering. If you need to change a value, you must erase it
  and insert the new value.

When sets are useful:
- When you need to store unique values.
- When you frequently check whether an element already exists.
- When you want elements automatically kept in sorted order.

Typical examples:
- Removing duplicates from data
- Membership testing ("have I seen this before?")
- Maintaining a sorted collection of unique items
*/