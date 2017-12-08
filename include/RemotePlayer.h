

#ifndef EX2_REMOTEPLAYER_H
#define EX2_REMOTEPLAYER_H


#include "GeneralPlayer.h"
#include "Client.h"

class RemotePlayer : public GeneralPlayer {
public:
    RemotePlayer(int sign, Client* c);
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
    string getNextMove(Board* b);
    /**
     * the remote player doesnt need to know his options, waiting for answer from the other client
     * @param screen screen
     * @param myoptions list of options
     */
    void printMyOptions(Visualization* screen, vector<cell_t> myoptions) const;

    /**
 * passes the turn to te other player
 */
    void passTurn();

    /**
     *
     *
     * print there no moves for current player;
     */
    void noMovesForMe(Visualization* screen);
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
    Client* client;

};


#endif //EX2_REMOTEPLAYER_H
