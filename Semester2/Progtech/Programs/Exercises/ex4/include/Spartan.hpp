#ifndef SPARTAN_HPP
#define SPARTAN_HPP

#include "Player.hpp"

class Spartan: public Player {
public:
    Spartan(const std::string &n);
    ~Spartan();

    const std::string & getType() const override;
    Move play(const State &s) override;

private:
    static std::string type;
};

#endif