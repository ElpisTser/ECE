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

    int targetHeap = (maxHeap + 1) % s.getHeaps(); // ensures target != source due to State::next() constraint

    return Move(maxHeap, 1, targetHeap, 0);
}