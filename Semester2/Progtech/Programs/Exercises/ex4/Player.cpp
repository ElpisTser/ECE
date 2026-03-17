#include "Player.hpp"

using namespace std;

Player::Player(const string &n): name(n) {};

Player::~Player() {};

ostream & operator << (ostream & out, const Player &player) {
    out << player.getType() << " " << player.name;
    return out;
}