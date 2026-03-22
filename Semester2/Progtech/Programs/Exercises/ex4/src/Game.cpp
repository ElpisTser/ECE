#include "Game.hpp"

using namespace std;

Game::Game(int h, int p): heapsNum(h), playersNum(p), coinsIndex(0) { coins = new int[heapsNum]; }

Game::~Game() {
    delete [] coins;
}

void Game::addHeap(int c) {
    coins[coinsIndex] = c;
    coinsIndex++;
}

void Game::addPlayer(Player *player) {
    players.push_back(player);
}

int Game::getPlayers() const { return playersNum; }

const Player* Game::getPlayer(int p) const { return players[p]; }