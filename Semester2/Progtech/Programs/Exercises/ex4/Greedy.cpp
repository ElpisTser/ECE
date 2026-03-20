#include "Greedy.hpp"

using namespace std;

string Greedy::type = "Greedy";

Greedy::Greedy(const string &n): Player(n) {}

Greedy::~Greedy() {}

const string & Greedy::getType() const { return type; }

Move Greedy::play(const State &s) {
    int maxHeap = 0;

    for (int i=1; i<s.getHeaps(); i++) {
        if (s.getCoins(i) > s.getCoins(maxHeap))
            maxHeap = i;
    }

    int targetHeap = (maxHeap + 1) % s.getHeaps(); // ensures target != source due to State::next() constraint

    return Move(maxHeap, s.getCoins(maxHeap), targetHeap, 0);
}

