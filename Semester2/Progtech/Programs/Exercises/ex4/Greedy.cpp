#include "Greedy.hpp"

using namespace std;

string Greedy::type = "Greedy";

Greedy::Greedy(const string &n): Player(n) {}

Greedy::~Greedy() {}

const string & Greedy::getType() const { return type; }

Move Greedy::play(const State &s) {
    // To do: better implementation
    int maxHeap = 0;
    int maxCoins = s.getCoins(0);
    int heaps = s.getHeaps();
    for (int i=1; i<heaps; i++) {
        if (s.getCoins(i) > maxCoins) {
            maxHeap = i;
            maxCoins = s.getCoins(i);
        }
    }

    int targetHeap;
    if (maxHeap == heaps - 1)
        targetHeap = maxHeap - 1;
    else    
        targetHeap = maxHeap + 1; 


    return Move(maxHeap, maxCoins, targetHeap, 0);
}

