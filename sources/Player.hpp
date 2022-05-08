//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_PLAYER_HPP
#define EX4_A_PLAYER_HPP

#include <iostream>
#include "Characters.hpp"
#include "Game.hpp"

using namespace std;
namespace coup {
    class Game;

    const int COUP_COST = 7;
    const int COINS_MUST_COUP = 10;
    const int ASSASSIN_COUP_COST = 3;

    class Player {
    private:
        void assassinate(Player &targetToCoup);

    protected:
        string name;
        int coinsNum = 0;
        coup::Game *game;
        Player *target = NULL;
        Character roleType;
        bool foreignAid = false;
        bool alive = true;
        bool specialMove = false;
        bool blocked = false;
    public:

        string getName();

        void setRoleType(Character role);

        Character getRoleType();

        Player *getTarget();

        int coins() const;

        void setCoins(int numOfCoins);

        bool getSpecialMove() const;

        void setSpecialMove(bool value);

        bool getForeignAid() const;

        void setForeignAid(bool value);

        bool isAlive() const;

        void setAlive(bool state);

        void setBlocked(bool value);


        void foreign_aid();

        void coup(Player &target);

        void income();

        string role();

        void block(Player &targetToBlock);

        friend void validateInTurn(Player &player);

        friend void validateCanPlay(Player &player);


    };

    void validateLessThanTenCoins(Player &player);

    void validateCanCoup(Player &player, Player &target);

    void validateLessThanTenCoins(Player &player);

    void falsifyBools(Player &player);

    void validateCanAssassinate(Player &assassin, Player &targetToKill);

}

#endif //EX4_A_PLAYER_HPP
