

#ifndef EX2_LOCALPLAYER_H
#define EX2_LOCALPLAYER_H


#include "GeneralPlayer.h"
#include "Client.h"

class LocalPlayer : public GeneralPlayer{
public:
    LocalPlayer(int sign, Client* c);
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
     * print there no moves for current player;
     * */
    void noMovesForMe(Visualization* screen);
    /**
     * prints the possible choices for this player
     * @param screen a scren to send the message to
     * @param myoptions the optional moves for this player
     */
    void printMyOptions(Visualization* screen, vector<cell_t> myoptions) const;

    void setSign() {};
    void printItsnAOption(Visualization* screen) const;
    void sendMove(const char* choice) const;
private:
    Client* client;
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


#endif //EX2_LOCALPLAYER_H
