//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_CONSOLE_H
#define EX2_CONSOLE_H

#include "Visualization.h"
#include "Board.h"

class Console : public Visualization {
public:
    /**
    * printOut.
    * @param gameBoard print this board on screen.
    */
    virtual void printOut(Board* b) const;
    /**
    * printError.
    * Print this massage if the input from the player is not from the options.
    */
    virtual void printError() const;
    /**
    * printNoMoreMoves.
    * @param player the current player.
    * Print this massage if there are no more move possible moves.
    */
    virtual void printNoMoreMoves(char player) const;
    /**
    * printOptions.
    * @param player the current player.
    * @param moves Print out all the player possible moves.
    */
    virtual void printOptions(char player, vector <cell_t> moves) const;
    /**
    * printScore.
    * @param player1 the firs player.
    * @param player2 the second player.
    * Print the current scores of the players.
    */
    virtual void printScore(GeneralPlayer* player1, GeneralPlayer* player2) const;
    /**
    * printWinner.
    * @param winner the winner player.
    * Print out the winner of this game.
    */
    virtual void printWinner(char winner) const;
    /**
    * openScreen.
    * Print out the main menu of the game.
    */
    virtual void openScreen();

    /**
 * print the last move of the last player
 */
    virtual void printWhichMovePlayed(char player, string move);
private:
    /**
    * options.
    * @param moves Print out the player possible moves.
    */
    void options(vector <cell_t> moves) const;
    /**
    * isAlreadyIn.
    * @param print the vector of the possible moves withput duplicate options.
    * @param c the cell to check if his in the vector.
    * @return if this c is in the vector already.
    * Check duplicate options.
    */
    bool isAlreadyIn(vector <cell_t*> print, cell_t c) const;
};

#endif //EX2_CONSOLE_H
