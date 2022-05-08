//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_AMBASSADOR_HPP
#define EX4_A_AMBASSADOR_HPP

#include "Player.hpp"
#include <iostream>
#include "Game.hpp"

namespace coup {
    class Ambassador : public Player {
    public:
        Ambassador(coup::Game &game, string const &name);

        void transfer(Player &playerFrom, Player &playerTo);

        void block(Player &player);


    };

}

#endif //EX4_A_AMBASSADOR_HPP
