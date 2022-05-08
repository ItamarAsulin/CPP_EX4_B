//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_ASSASIN_HPP
#define EX4_A_ASSASIN_HPP
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
using namespace std;
namespace coup {
    class Assassin : public Player{
    public:
        Assassin(Game &game, string const &name);
    };
}
#endif //EX4_A_ASSASIN_HPP
