//
// Created by itamarq on 4/30/22.
//

#include "Duke.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
#include "Characters.hpp"

void validateDukeCanBlock (coup::Player &target) {
    if(!target.getForeignAid()){
        throw "Duke Can Only Block A Player That Used Foreign Aid!\n";
    }
}

namespace coup {
    Duke::Duke(coup::Game &game, string const &name) {
        this->name = name;
        this->game = &game;
        this->roleType = Character::DUKE;
        game.addToGame(*this);
    }

    void Duke::tax() {
        validateCanPlay(*this);
        validateLessThanTenCoins(*this);
        int currentBalance = this->coins();
        this->setCoins(currentBalance + 3);
        game->nextTurn();
    }

    void Duke::block(Player &player) {
        validateDukeCanBlock(player);
        int playerBalance = player.coins();
        player.setForeignAid(false);
        player.setCoins(playerBalance - 2);
        this->blocked = true;
    }


}
