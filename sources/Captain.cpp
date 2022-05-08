//
// Created by itamarq on 4/30/22.
//

#include "Captain.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
#include "Characters.hpp"
const int MIN_COINS_FOR_STEAL = 1;

void validateCanSteal(coup::Captain &captain, coup::Player &target) {
    coup::validateLessThanTenCoins(captain);
    if(target.coins() <MIN_COINS_FOR_STEAL){
        throw "Captain Can Only Steal From Player With One Coin Or More!\n";
    }
}

void validateCaptainCanBlock(coup::Player &target) {
    Character targetType = target.getRoleType();
    if(targetType != Character::CAPTAIN){
        throw "Captain Can Only Block Another Captain!\n";
    }
    if(!target.getSpecialMove()){
        throw "Captain You Can Only Block A Captain That Have Stolen!\n";
    }
}

namespace coup {
    Captain::Captain(coup::Game &game, string const &name) {
        this->name = name;
        this->game = &game;
        this->roleType = Character::CAPTAIN;
        game.addToGame(*this);
    }

    void Captain::steal(Player &target) {
        validateCanPlay(*this);
        validateCanSteal(*this, target);
        falsifyBools(*this);
        int targetCoins = target.coins();
        int captainCoins = this->coins();
        if(targetCoins == 1){
            target.setCoins(0);
            this->setCoins(captainCoins + 1);
        }else {
            target.setCoins(targetCoins - 2);
            this->setCoins(captainCoins + 2);
        }
        this->setSpecialMove(true);
        this->target = &target;
        game->nextTurn();
    }

    void Captain::block(Player &player) {
        validateCaptainCanBlock( player);
        int playerCoins = player.coins();
        Player *theftVictim = player.getTarget();
        int targetCoins = theftVictim->coins();
        player.setCoins(playerCoins - 2);
        theftVictim->setCoins(targetCoins + 2);
        player.setSpecialMove(false);
        this->blocked = true;
    }

}
