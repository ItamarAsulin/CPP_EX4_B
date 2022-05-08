//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_GAME_HPP
#define EX4_A_GAME_HPP

#include <iostream>
#include <vector>
#include "Player.hpp"

using namespace std;
namespace coup {
    const int MAX_PLAYERS = 6;
    const int MIN_PLAYERS = 2;
    class Player;
    class Game {
    protected:
        vector<Player *> playersArray;
        size_t turnNum = 0;
        Player *currentPlayer = NULL;
        bool gameOver;
        size_t position;

    public:
        uint numOfPlayers;

        Game();

        string turn();

        string winner();

        vector<string> players();

        bool isInTheGame(Player &player);

        void addToGame(Player &player);

        void nextTurn();

        friend void validateNotInTheGame(Game &game, Player& player);
    };
}


#endif //EX4_A_GAME_HPP
