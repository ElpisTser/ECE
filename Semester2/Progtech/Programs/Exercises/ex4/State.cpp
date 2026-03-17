#include "State.hpp"

using namespace std;

State::State(int h, const int c[], int n):
    heaps(h), players(n), playing(0) {
        coins = new int[heaps];
        for (int i=0; i<heaps; i++) 
            coins[i] = c[i];
    }

State::~State() {
    delete [] coins;
}

void State::next(const Move &move) {
    if ((move.getSource() > heaps - 1) || (move.getSource() < 0))
        throw logic_error("Invalid source heap");

    if ((move.getTarget() > heaps - 1) || (move.getTarget() < 0))
        throw logic_error("Invalid target heap");

    if ((move.getSourceCoins() > coins[move.getSource()]) || (move.getSourceCoins() < 0)) 
        throw logic_error("Invalid coins for source heap");

    if ((move.getTargetCoins() < 0) || (move.getTargetCoins() > move.getSourceCoins()))
        throw logic_error("Invalid coins for target heap");

    if (move.getSource() == move.getTarget())
        throw logic_error("Source and target  heap cannot be the same");

    coins[move.getSource()] -= move.getSourceCoins();
    coins[move.getTarget()] += move.getTargetCoins();
    
    if (playing == players -1)
        playing = 0;
    else
        playing++;
}

bool State::winning() const {
    for (int i=0; i<heaps; i++)
        if (coins[i] == 0) return true;
    return false;
}

int State::getHeaps() const { return heaps; }

int State::getCoins(int h) const { 
    if ((h < 0) || h > heaps - 1)
        throw logic_error("Tried to get coins from invalid heap");

    return coins[h]; 
}

int State::getPlayers() const { return players; }

int State::getPlaying() const { return playing; }

ostream & operator << (ostream & out, const State &state) {
    for (int i=0; i<state.heaps; i++)
        out << state.coins[i] << ", ";
    out << "with " << state.playing << "/" << state.players - 1 << " playing next";

    return out;
}