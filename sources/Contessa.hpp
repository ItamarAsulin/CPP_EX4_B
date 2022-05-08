//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_CONTESSA_HPP
#define EX4_A_CONTESSA_HPP
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    class Contessa : public Player {
    public:
        Contessa(coup::Game &game, string const &name);

        void block(Player &assassin);
    };
}
#endif //EX4_A_CONTESSA_HPP
