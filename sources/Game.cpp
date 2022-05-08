//
// Created by itamarq on 4/30/22.
//

#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

using namespace std;
namespace coup {

    Game::Game() {
        turnNum = 1;
        currentPlayer = NULL;
        gameOver = false;
        position = 0;
        numOfPlayers = 0;
    }

    string Game::turn() {
        return currentPlayer->getName();
    }

    string Game::winner() {
        if (!gameOver) {
            throw "The Game Is Not Over Yet!\n";
        }
        string winnerName;
        for (uint i = 0; i < numOfPlayers; ++i) {
            Player *currPlayer = playersArray.at(i);
            if (currPlayer->isAlive()) {
                winnerName = currPlayer->getName();
            }
        }
        return winnerName;
    }

    vector<string> Game::players() {
        vector<string> players;
        for (Player *player: playersArray) {
            if (player->isAlive()) {
                players.push_back(player->getName());
            }
        }
        return players;
    }

    void Game::addToGame(Player &player) {
        if (turnNum > 1) {
            throw invalid_argument("You Can't Add A Player After The Game Has Begun!\n");
        }
        if (numOfPlayers >= MAX_PLAYERS) {
            throw invalid_argument("Max Number Of Players Is 6!\n");
        }
            validateNotInTheGame(*this, player);
            playersArray.push_back(&player);
            numOfPlayers++;
            if (numOfPlayers == 1) {
                currentPlayer = &player;
            }

        }

        bool Game::isInTheGame(Player &player) {
            for (Player *currPlayer: playersArray) {
                if (currPlayer == &player && currPlayer->isAlive()) {
                    return true;
                }
            }
            return false;
        }


        void Game::nextTurn() {
            turnNum++;
            Player *playedLastTurn = currentPlayer;
            bool foundNextPlayer = false;
            while (!foundNextPlayer) {
                position++;
                uint currentPosition = position % numOfPlayers;
                Player *candidateForNextTurn = playersArray.at(currentPosition);
                if (candidateForNextTurn->isAlive()) {
                    currentPlayer = candidateForNextTurn;
                    foundNextPlayer = true;
                }
            }
            if (currentPlayer == playedLastTurn) {
                cout << "The Game Is over! We Have A Winner!\n";
                gameOver = true;
            }
        }

        void validateNotInTheGame(Game &game, Player &player) {
            for (Player *playerInGame: game.playersArray) {
                if (&player == playerInGame) {
                    throw "The Player Is Already In The Game!\n";
                }
            }
        }
    }