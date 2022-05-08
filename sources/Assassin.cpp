//
// Created by itamarq on 4/30/22.
//

#include "Assassin.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"

namespace coup {
    Assassin::Assassin(coup::Game &game, string const &name) {
        this->name = name;
        this->game = &game;
        this->roleType = Character::ASSASSIN;
        game.addToGame(*this);
    }

}

