//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_REVERSIRULES_H
#define EX2_REVERSIRULES_H

#include "Cell.h"
#include "Board.h"
#include "GeneralPlayer.h"
#include "Visualization.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class ReversiRules {
public:
    /**
     *  constructor.
     * @param black first player
     * @param white  secone player
     * @param screen a screen to show the game on
     */
    ReversiRules(GeneralPlayer* black, GeneralPlayer* white, Visualization* screen);
    /**
     * destructor
     */
    ~ReversiRules();
    /**
     * nextTurn.
     * responsible for the next turn for each player
     */
    void nextTurn();
    /**
     * gameover.
     * check if the game is over
     * @return true if there no more moves
     * for both/or the board is full, false otherwise
     */
    bool gameover();
    /**
     * flipFrom.
     *after a disk was set, the func checks which other disk next to it to flip
     * @param row the new disk row in board
     * @param col the new disk col in board
     */
    void flipFrom(int row, int col);
    /**
     *isThatAnOption.
     * @param choice the string the user typed as a choice
     * @return true if its a valid choice, false otherwise
     */
    bool isThatAnOption(string choice);
    /**
     * setPlayerDisk.
     * set the board to have the current player sign at the
     * desired position, updated scores of players according to the history
     * of the disk
     * @param row wanted row in board
     * @param col wanted col in board
     */
    void setPlayerDisk(int row, int col);
    /**
     * whoWon.
     * Checks witch player has more points and sends the information to screen.
     */
    void whoWon();
private:
    Board* board_;
    GeneralPlayer* whiteP_;
    GeneralPlayer* blackP_;
    GeneralPlayer* now_;
    GeneralPlayer* later_;
    vector<cell_t> movesForCurrentPlayer;
    Visualization* screen_;
};

#endif //EX2_REVERSIRULES_H
