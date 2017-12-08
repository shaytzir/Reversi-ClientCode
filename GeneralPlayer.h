//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_GENERALPLAYER_H
#define EX2_GENERALPLAYER_H

#include <string>
#include "Board.h"
#include "Cell.h"
#include "Visualization.h"

using namespace std;

class GeneralPlayer {
public:
    /**
     *ScoreUp.
     * @param num number of disks to add to the player's score
     */
    virtual void scoreUp(int num) = 0;
    /**
     * scoreDown.
     * @param num a number to reduce from this player score
     */
    virtual void scoreDown(int num) = 0;
    /**
     * getSign.
     * @return the sign of this player
     */
    virtual char getSign() const = 0;
    /**
     * getScore.
     * @return the score of this player
     */
    virtual int getScore() const = 0;
    /**
     * getNextMove.
     * @param b the board to check the next move in.
    **/
    virtual string getNextMove(Board* b) = 0;
    /**
     * passes the turn to the other player.
     */
    virtual void passTurn() = 0;

    /**
     * print there no moves for current player;
     */
    virtual void noMovesForMe(Visualization* screen) = 0;
    /**
     * getMovesForPlayer.
     * @param gameBoard the board to check on.
     * @param sign the player sign.
     * @return the optional moves.
     */
    virtual vector<cell_t> getMovesForPlayer(Board* gameBoard, char sign) const = 0;
    /**
     * prints the player options to the screen
     * @param screen screen
     * @param myoptions list of optional moves
     */
    virtual void printMyOptions(Visualization* screen, vector<cell_t> myoptions) const = 0;
protected:
    char sign_;
    int disksNum_;
};

#endif //EX2_GENERALPLAYER_H
