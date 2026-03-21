#include "Sneaky.hpp"

using namespace std;

string Sneaky::type = "Sneaky";

Sneaky::Sneaky(const string &n): Player(n) {}

Sneaky::~Sneaky() {}

const string & Sneaky::getType() const { return type; }

Move Sneaky::play(const State &s) {
    int minHeap = 0;

    // Find the first non-empty heap
    while (minHeap < s.getHeaps() && s.getCoins(minHeap) == 0)
        minHeap++;

    // Find the heap with the smallest number of coins
    for (int i = minHeap + 1; i < s.getHeaps(); i++) {
        int coins = s.getCoins(i);
        if (coins > 0 && coins < s.getCoins(minHeap)) {
            minHeap = i;
        }
    }

    return Move(minHeap, s.getCoins(minHeap), 0, 0);
}
