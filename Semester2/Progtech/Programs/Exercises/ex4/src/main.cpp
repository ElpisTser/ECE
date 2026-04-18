#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Greedy.hpp"
#include "Spartan.hpp"
#include "Sneaky.hpp"
#include "Righteous.hpp"
#include "Game.hpp"

using namespace std;

int main() {
   Game specker(3, 4);
   specker.addHeap(10);
   specker.addHeap(20);
   specker.addHeap(17);
   specker.addPlayer(new Sneaky("Tom"));
   specker.addPlayer(new Spartan("Mary"));
   specker.addPlayer(new Greedy("Alan"));
   specker.addPlayer(new Righteous("Robin"));
   specker.play(cout);
}

