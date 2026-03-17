#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Greedy.hpp"

using namespace std;

int main() {
   int coins[] = {2, 3, 5, 6};

   State s(4, coins, 3);
   cout << s << endl;

   Greedy g("Elpis");
   Move m = g.play(s);
   s.next(m);
   cout << g << " " << m << endl << s << endl;

   Move m2 = g.play(s);
   s.next(m2);
   cout << g << " " << m2 << endl << s << endl;

   Move m3 = g.play(s);
   s.next(m3);
   cout << g << " " << m3 << endl << s << endl;
}