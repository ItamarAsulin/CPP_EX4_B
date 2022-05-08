//
// Created by itamarq on 4/30/22.
//

#include "Player.hpp"
#include <exception>


namespace coup {

    string Player::getName() {
        return this->name;
    }

    void Player::setRoleType(Character role) {
        roleType = role;
    }

    Character Player::getRoleType() {
        return this->roleType;
    }

    Player *Player::getTarget() {
        return this->target;
    }

    int  Player::coins()  const{
        return this->coinsNum;
    }

    void Player::setCoins(int numOfCoins) {
        this->coinsNum = numOfCoins;
    }

    bool  Player::getSpecialMove()  const{
        return this->specialMove;
    }

    void Player::setSpecialMove(bool value) {
        this->specialMove = value;
    }

    bool  Player::getForeignAid()  const{
        return this->foreignAid;
    }

    void Player::setForeignAid(bool value) {
        this->foreignAid = value;
    }

    bool  Player::isAlive()  const{
        return this->alive;
    }

    void Player::setAlive(bool state) {
        this->alive = state;
    }

    void Player::setBlocked(bool value) {
        this->blocked = value;
    }


    void Player::income() {
        validateCanPlay(*this);
        validateLessThanTenCoins(*this);
        falsifyBools(*this);
        this->coinsNum++;
        game->nextTurn();
    }

    void Player::foreign_aid() {
        validateCanPlay(*this);
        validateLessThanTenCoins(*this);
        falsifyBools(*this);
        this->coinsNum += 2;
        foreignAid = true;
        game->nextTurn();
    }

    void Player::coup(Player &targetToCoup) {
        validateCanPlay(*this);
        if (this->roleType == Character::ASSASSIN) {
            return assassinate(targetToCoup);
        }
        validateCanCoup(*this, targetToCoup);
        falsifyBools(*this);
        this->coinsNum -= COUP_COST;
        targetToCoup.setAlive(false);
        game->nextTurn();
    }

    string Player::role() {
        Character role = this->roleType;
        switch (role) {
            case Character::AMBASSADOR:
                return "Ambassador";
                break;
            case Character::ASSASSIN:
                return "Assassin";
                break;
            case Character::CAPTAIN:
                return "Captain";
                break;
            case Character::CONTESSA:
                return "Contessa";
            case Character::DUKE:
                return "Duke";
                break;
            default:
                return "Something Wrong";
        }
    }

    void Player::assassinate(Player &targetToCoup) {
        validateCanAssassinate(*this, targetToCoup);
        falsifyBools(*this);
        targetToCoup.setAlive(false);
        int currentBalance = this->coins();
        int updatedBalance = 0;
        if (currentBalance < COUP_COST) {
            this->specialMove = true;
            this->target = &targetToCoup;
            updatedBalance = currentBalance - ASSASSIN_COUP_COST;
        }else {
            updatedBalance = currentBalance - COUP_COST;
        }
        this->setCoins(updatedBalance);
        game->nextTurn();
    }

    void validateLessThanTenCoins(Player &player) {
        if (player.coins() >= COINS_MUST_COUP) {
            throw "You Have 10 Coins Or More, you Must Preform A Coup!\n";
        }
    }

    void validateCanCoup(Player &player, Player &target) {
        if (player.coins() < COUP_COST) {
            throw "You Have Less Than 7 Coins. You Are Unable To Preform A Coup!\n";
        }
        if (!target.isAlive()) {
            throw "You Can't Preform A Coup On A Player That Is Already Dead!\n";
        }
    }

    void falsifyBools(Player &player) {
        player.setForeignAid(false);
        player.setSpecialMove(false);
        player.setBlocked(false);
    }

    void validateCanAssassinate(Player &assassin, Player &target) {
        if (assassin.coins() < ASSASSIN_COUP_COST) {
            throw "Assassin Can Only Assassinate With 3 Coins Or More!\n";
        }

        if (!target.isAlive()) {
            throw "Assassin Can Only Assassinate If The Target Is Alive!\n";
        }
    }

    void validateInTurn(Player &player){
        string playerName = player.getName();
        string currentPlayerName = player.game->turn();
        if(playerName != currentPlayerName){
            throw "You Can't Play Right Now, It Is Not Your Turn!\n";
        }
    }

    void validateCanPlay(Player &player){
        Game *playerGame = player.game;
        if(playerGame->numOfPlayers < MIN_PLAYERS){
            throw "You Can't Play With One Player";
        }
        validateInTurn(player);
    }

}