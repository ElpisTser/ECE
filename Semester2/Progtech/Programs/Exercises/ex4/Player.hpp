#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "State.hpp"

class Player {
public:
    Player(const std::string &n);
    virtual ~Player();

    virtual const std::string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend std::ostream & operator << (std::ostream &out, const Player &player);

protected:
    std::string name;
};

#endif