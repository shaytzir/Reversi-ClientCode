//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_HUMANP_H
#define EX2_HUMANP_H

#include "GeneralPlayer.h"

class HumanP : public GeneralPlayer {
public:
    /**
     * constructor
     * @param playerSign sets the player sign, and sets 2 disks for player
     */
    HumanP(char playerSign);
    /**
     *scoreUp.
     * @param num number of disks to add to the player's score
     */
    void scoreUp(int num);
    /**
     * scoreDown.
     * @param num a number to reduce from this player score
     */
    void scoreDown(int num);
    /**
     * getSign.
     * @return the sign of this player
     */
    char getSign() const;
    /**
     * getScore.
     * @return the score of this player
     */
    int getScore() const;
    /**
     * getNextMove.
     * @param b the board to check the next move in.
     * @return the next move choice.
     */
    string getNextMove(Board* b);
    /**
     * getMovesForPlayer.
     * @param gameBoard the board to check on.
     * @param sign the player sign.
     * @return the optional moves.
     */
    vector<cell_t> getMovesForPlayer(Board* gameBoard, char sign) const ;
    /**
     * passes the turn to te other player
     */
    void passTurn();

    /**
     *
     *
     *  print there no moves for current player;
     */
    void noMovesForMe(Visualization* screen);

    void printMyOptions(Visualization* screen, vector<cell_t> myoptions) const;
    void setSign() {};
private:
    /**
    *getLocationsOfPlayerOnBoard.
    * @param sign player sign.
    * @param gameBoard the board to check on the possible moves.
    * @return vector of type point of al this player discs on board.
    */
    vector<point_t> getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const ;
    /**
    *possibleMovesForOneDisk.
    * @param current sign of the current player.
    * @param point the cell to check the possible moves for.
    * @param gameBoard the board to check on.
    * @return vector of cells that are possible moves of this player on the board.
    */
    vector<cell_t> possibleMovesForOneDisk(char current, point_t point, Board* gameBoard) const ;
};

#endif //EX2_HUMANP_H
