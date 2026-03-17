#include "Move.hpp"

using namespace std;

Move::Move(int sh, int sc, int th, int tc):
    source(sh), sourceCoins(sc), target(th), targetCoins(tc) {}

int Move::getSource() const { return source; }

int Move::getSourceCoins() const { return sourceCoins; }

int Move::getTarget() const { return target; }

int Move::getTargetCoins() const { return targetCoins; }

ostream & operator << (ostream & out, const Move &move) {
    out << "takes " << move.sourceCoins << " coins from heap " << move.source << " and puts ";
    if (move.targetCoins == 0) out << "nothing";
    else out << move.targetCoins << " coins to heap " << move.target;

    return out;
}