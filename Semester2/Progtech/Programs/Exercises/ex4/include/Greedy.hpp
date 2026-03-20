#ifndef GREEDY_HPP
#define GREEDY_HPP

#include "Player.hpp"

class Greedy: public Player {
public:
    Greedy(const std::string &n);
    ~Greedy();

    const std::string & getType() const override;
    Move play(const State &s) override;

private:
    static std::string type;
};

#endif