#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> m;

    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    int x;
    cin >> x;

    map<int, string>::iterator p;
    p = m.find(x);

    if (p != m.end())
        cout << p->second << endl;
    else
        cout << "Didn't find element" << endl;

}

/*
Notes about std::map

- std::map<Key, Value> is an associative container in the C++ STL.
- It stores elements as key-value pairs.
- Keys are unique and automatically sorted.
- Values are accessed via the key.

Two common ways to insert elements:
1. Using insert() with std::pair:
       m.insert(make_pair(key, value));
   This syntax works but is less commonly used in modern C++.

2. Using the subscript operator []:
       m[key] = value;
   This is simpler and more frequently used.

Finding elements:
- m.find(key) returns an iterator to the element if the key exists.
- If the key is not found, it returns m.end().

Accessing values via iterators:
- Once you have an iterator p from find(), use p->second to get the value.
- p->first is the key.

Other common operations:
- m.erase(key)      -> removes element with the given key
- m.size()          -> returns number of key-value pairs
- Iteration:
      for (const auto &pair : m)
          cout << pair.first << " -> " << pair.second << endl;

Notes:
- std::map guarantees O(log n) complexity for insert, find, and erase.
- Values cannot be modified without knowing the key.
- Use std::unordered_map if you don’t need keys sorted and want faster average lookups (O(1)).

When maps are useful:
- When you need to associate a value with a unique key.
- When you need fast lookups by key.
- When you want keys kept in sorted order automatically.
*/