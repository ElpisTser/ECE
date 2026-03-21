#include "Righteous.hpp"

using namespace std;

string Righteous::type = "Righteous";

Righteous::Righteous(const string &n): Player(n) {}

Righteous::~Righteous() {}

const string & Righteous::getType() const { return type; }

Move Righteous::play(const State &s) {
    int heaps = s.getHeaps();
    
    // Find heap with maximum coins (smallest index in case of tie) 
    int maxHeap = 0;
    for (int i = 1; i < heaps; i++) {
        if (s.getCoins(i) > s.getCoins(maxHeap))
            maxHeap = i;
    }

    // Find heap with minimum coins (prefer empty heap if exists)
    int minHeap = 0;
    for (int i = 0; i < heaps; i++) {
        int coins = s.getCoins(i);

        // Prefer empty heap immediately
        if (coins == 0) {
            minHeap = i;
            break;
        }

        if (coins < s.getCoins(minHeap)) {
            minHeap = i;
        }
    }


    int maxCoins = s.getCoins(maxHeap);

    // Take c/2 coins, but if only 1 coin exists, take it
    int sourceCoins = (maxCoins == 1) ? 1 : maxCoins / 2;

    // If minHeap == maxHeap, all heaps are equal → pick next heap (index 1)
    if (minHeap == maxHeap)
        minHeap++;

    return Move(maxHeap, sourceCoins, minHeap, sourceCoins - 1);
}