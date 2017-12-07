//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_VISUALIZATION_H
#define EX2_VISUALIZATION_H

#include <iostream>
#include <string>
#include "GeneralPlayer.h"
#include "Cell.h"
#include "Board.h"
using namespace std;

class Visualization {
public:
    /**
    * printScore.
    * @param player1 the firs player.
    * @param player2 the second player.
    * Print the current scores of the players.
    */
    virtual void printScore(GeneralPlayer* player1, GeneralPlayer* player2) const = 0;
    /**
     * default constructor.
     */
    Visualization() {};
    /**
    * printOut.
    * @param gameBoard print this board on screen.
    */
    virtual void printOut(Board* gameBoard) const = 0;
    /**
    * printError.
    * Print this massage if the input from the player is not from the options.
    */
    virtual void printError() const = 0;
    /**
    * printNoMoreMoves.
    * @param player the current player.
    * Print this massage if there are no more move possible moves.
    */
    virtual void printNoMoreMoves(char player) const = 0;
    /**
    * printScore.
    * @param player1 the firs player.
    * @param player2 the second player.
    * Print the current scores of the players.
    */
    virtual void printOptions(char player, std::vector <cell_t> moves) const = 0;
    /**
    * printWinner.
    * @param winner the winner player.
    * Print out the winner of this game.
    */
    virtual void printWinner(char winner) const = 0;
    /**
    * openScreen.
    * Print out the main menu of the game.
    */
    virtual void openScreen() = 0;

    /**
     * print the last move of the last player
     */
    virtual void printWhichMovePlayed(char player, string move) = 0;
};

#endif //EX2_VISUALIZATION_H
