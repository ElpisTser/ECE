#ifndef MOVE_HPP
#define MOVE_HPP

#include <iostream>

class Move {
public:
// Take sc from heap sh and put tc coins to heap th
Move(int sh, int sc, int th, int tc);

int getSource() const;
int getSourceCoins() const;
int getTarget() const;
int getTargetCoins() const;

friend std::ostream & operator << (std::ostream &out, const Move &move);

private:
    int source,  sourceCoins, target, targetCoins;
};

#endif