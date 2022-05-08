//
// Created by itamarq on 4/30/22.
//

#include "Contessa.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
#include "Characters.hpp"

void validateContessaCanBlock(coup::Player &target){
    Character targetRoleType = target.getRoleType();
    if(targetRoleType != Character::ASSASSIN){
        throw "Contessa Can Only Block Assassin!\n";
    }
    if(!target.getSpecialMove()){
        throw "Contessa Can Only Block Assassin That Assassinated!\n";
    }
}
namespace coup {
    Contessa::Contessa(coup::Game &game, string const &name) {
        this->name = name;
        this->game = &game;
        this->roleType = Character::CONTESSA;
        game.addToGame(*this);
    }

    void Contessa::block(Player &assassin) {
        validateContessaCanBlock(assassin);
        Player* assassinationVictim = assassin.getTarget();
        assassinationVictim->setAlive(true);
        assassin.setSpecialMove(false);
        this->blocked = true;
    }


}
