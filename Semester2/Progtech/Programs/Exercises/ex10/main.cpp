#include <iostream>
#include "lexicon.hpp"

using namespace std;

int main() {
    lexicon l;
    l.insert("drop");
    l.insert("banana");
    l.insert("apple");
    l.insert("cheese");
    l.insert("zed");
    l.insert("banana");

    cout << l;
}