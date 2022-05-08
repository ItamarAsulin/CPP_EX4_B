//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_CPATAIN_HPP
#define EX4_A_CPATAIN_HPP
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    class Captain : public Player {
    public:
        Captain(coup::Game &game, string const &name);

        void steal(Player &target);

        void block(Player &player);

    };

}
#endif //EX4_A_CPATAIN_HPP
