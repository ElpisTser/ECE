#include "Game.hpp"
#include <stdexcept>

using namespace std;

Game::Game(int h, int p): heapsNum(h), playersNum(p), coinsIndex(0) { coins = new int[heapsNum]; }

Game::~Game() {
    delete [] coins;
}

void Game::addHeap(int c) {
    if (coinsIndex == heapsNum)
        throw logic_error("Cannot add more heaps");

    if (c < 0)
        throw logic_error("Invalid number of coins");

    coins[coinsIndex] = c;
    coinsIndex++;
}

void Game::play(ostream &out) {
    if (coinsIndex != heapsNum) 
        throw logic_error("Tried to start game with invalid number of heaps");

    if (players.size() != playersNum)
        throw logic_error("Tried to start game with invalid number of players");

    State s(heapsNum, coins, playersNum);
    out << s << endl;

    vector<Player*>::iterator i = players.begin();
    
    while (true) {
        Move m = (*i)->play(s);
        s.next(m); // State::next() internally checks for invalid moves and throws if necessary
        out << *(*i) << " " << m << endl << s << endl;
        
        if (s.winning()) break;

        i++;
        if  (i == players.end()) 
            i = players.begin();
    }
    out << *(*i) << " wins" << endl;
}

void Game::addPlayer(Player *player) {
    if (players.size() >= playersNum)
        throw logic_error("Cannot add more players");

    players.push_back(player);
}

int Game::getPlayers() const { return playersNum; }

const Player* Game::getPlayer(int p) const { 
    if (p >= players.size())
        throw logic_error("Tried to get not existing player");

    return players[p]; 
}