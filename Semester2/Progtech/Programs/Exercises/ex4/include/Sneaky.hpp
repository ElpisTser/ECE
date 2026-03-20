#ifndef SNEAKY_HPP
#define SNEAKY_HPP

#include "Player.hpp"

class Sneaky: public Player {
public:
    Sneaky(const std::string &n);
    ~Sneaky();

    const std::string &getType() const override;
    Move play(const State &s) override;

private:
    static std::string type;
};

#endif