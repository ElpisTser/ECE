#ifndef RIGHTEOUS_HPP 
#define RIGHTEOUS_HPP

#include "Player.hpp"

class Righteous: public Player {
public:
    Righteous(const std::string &n);
    ~Righteous();

    const std::string &getType() const override;
    Move play(const State &s) override;

private:
    static std::string type;
};

#endif