//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include "GeneralPlayer.h"

class AIPlayer : public GeneralPlayer {
public:
    /**
    * constructor
    * @param playerSign sets the player sign, and sets 2 disks for player
    */
    AIPlayer(char playerSign);
    /**
    *
    * @param num number of disks to add to the player's score
    */
    void scoreUp(int num);
    /**
     * setter
     * @param num a number to reduce from this player score
     */
    void scoreDown(int num);
    /**
     * getter
     * @return the sign of this player
     */
    char getSign() const;
    /**
     * getter
     * @return the score of this player
     */
    int getScore() const;
    /**
    *getMovesForPlayer.
    * @param gameBoard the board to check on the possible moves.
    * @param sign the player sign.
    * @return the possible moves in vector of type cell.
    */
    vector<cell_t> getMovesForPlayer(Board* gameBoard, char sign) const;
    /**
    * getNextMove.
    * @param gameBoard the board that we need to check the player moves on it.
    * @return the AIPlayer best move to do.
    */
    string getNextMove(Board* b) ;




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
    vector<cell_t> possibleMovesForOneDisk(char current, point_t point, Board* &gameBoard) const ;
    /**
    *setPlayerDisk.
    * @param cell the locetion of the move that we check the score of the other player options.
    * @param gameBoard the board to check on.
    * @return the maximum score that the other player can get from after AIPlayer set his disc on this cell.
    */
    int setPlayerDisk(cell_t cell, Board* gameBoard) const ;
};

#endif //EX2_AIPLAYER_H
