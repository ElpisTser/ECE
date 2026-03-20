#ifndef STATE_HPP
#define STATE_HPP

#include "Move.hpp"

class State {
public:
    // State with h heaps, where the i-th heap starts with c[i] coins.
    // A total of n players are in the game, numbered from 0 to n-1,
    // and player 0 is the first to play.
    State(int h, const int c[], int n);
    ~State();

    void next(const Move &move); // may throw logic_error
    bool winning() const;

    int getHeaps() const;
    int getCoins(int h) const; // may throw logic_error

    int getPlayers() const;
    int getPlaying() const;

    friend std::ostream & operator << (std::ostream &out, const State &state);

private:
    int heaps,   // h number of heaps 
        players, // n number of players 
        playing; // next player to play, numbered 0 to n-1
    int *coins;  // coins left in each heap, numbered 0 to h-1
};

#endif