#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <vector> 

class Game {
public:
    Game(int heaps, int players);
    ~Game();

    void addHeap(int coins);
    void addPlayer(Player *player);
    void play(std::ostream &out);

    int getPlayers() const;
    const Player * getPlayer(int p) const;

private:
    int heapsNum, playersNum, coinsIndex;
    int *coins;
    std::vector<Player*> players;
};

#endif