#include "Spartan.hpp"

using namespace std;

string Spartan::type = "Spartan";

Spartan::Spartan(const string &n): Player(n) {}

Spartan::~Spartan() {}

const string & Spartan::getType() const { return type; }

Move Spartan::play(const State &s) {
    int maxHeap = 0;

    for (int i=1; i<s.getHeaps(); i++) {
        if (s.getCoins(i) > s.getCoins(maxHeap))
            maxHeap = i;
    }

    return Move(maxHeap, 1, 0, 0);
}