#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Greedy.hpp"
#include "Spartan.hpp"
#include "Sneaky.hpp"
#include "Righteous.hpp"

using namespace std;

int main() {
   int coins[] = {8, 3, 5, 6};

   State s(4, coins, 3);
   cout << s << endl;

   Greedy gr("Elpis");
   Move m = gr.play(s);
   s.next(m);
   cout << gr << " " << m << endl << s << endl;

   Spartan sp("Babis");
   Move m2 = sp.play(s);
   s.next(m2);
   cout << sp << " " << m2 << endl << s << endl;

   Sneaky sn("Bobos");
   Move m3 = sn.play(s);
   s.next(m3);
   cout << sn << " " << m3 << endl << s << endl;

   Righteous ri("Akis");
   Move m4 = ri.play(s);
   s.next(m4);
   cout << ri << " " << m4 << endl << s << endl;
}

