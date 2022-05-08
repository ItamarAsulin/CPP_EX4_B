//
// Created by itamarq on 4/30/22.
//

#include "Ambassador.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
#include "Characters.hpp"
void validateAmbassadorCanBlock( coup::Player &target);
void validateCanTransfer(coup::Player& ambassador, coup::Player &playerFrom, coup::Player& playerTo);

namespace coup {


    Ambassador::Ambassador(coup::Game &game, string const &name) {
        this->name = name;
        roleType = Character::AMBASSADOR;
        this->game = &game;
        game.addToGame(*this);
    }

    void Ambassador::transfer(Player &playerFrom, Player &playerTo) {
        validateCanPlay(*this);
        validateCanTransfer(*this, playerFrom, playerTo);
        int playerFromCoins = playerFrom.coins();
        int playerToCoins = playerTo.coins();
        playerFrom.setCoins(playerFromCoins -1);
        playerTo.setCoins(playerToCoins + 1);
        game->nextTurn();
    }

    void Ambassador::block(Player &player) {
        validateAmbassadorCanBlock(player);
        int playerCoins = player.coins();
        Player *theftVictim = player.getTarget();
        int targetCoins = theftVictim->coins();
        player.setCoins(playerCoins - 2);
        theftVictim->setCoins(targetCoins + 2);
        player.setSpecialMove(false);
        this->blocked = true;
    }


}
void validateCanTransfer(coup::Player& ambassador, coup::Player &playerFrom, coup::Player& playerTo) {
    validateLessThanTenCoins(ambassador);
    if(playerFrom.coins()== 0){
        throw "You can't Take From A Player With No Coins!\n";
    }if(ambassador.coins() >= coup::COINS_MUST_COUP){
        throw "You Can't preform Transfer With 10 Or More Coins, You Must Preform A Coup!\n";
    }
}

void validateAmbassadorCanBlock( coup::Player &target) {
    Character targetRoleType = target.getRoleType();
    if(targetRoleType != Character::CAPTAIN){
        throw "Ambassador Can Only Block Captain!\n";
    }
    if(!target.getSpecialMove()){
        throw "Ambassador Can Only Block A Captain That Has Stolen!\n";
    }
}

