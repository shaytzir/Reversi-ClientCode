//
// Created by shay on 12/6/17.
//

#ifndef EX2_CLIENT_H
#define EX2_CLIENT_H

#include "GeneralPlayer.h"

class Client : public GeneralPlayer{
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
    char getSign();

    /**
 *scoreUp.
 * @param num number of disks to add to the player's score
 */
    void scoreUp(int num){};
    /**
     * scoreDown.
     * @param num a number to reduce from this player score
     */
    void scoreDown(int num){};
    /**
     * getSign.
     * @return the sign of this player
     */
    char getSign() const;
    /**
     * getScore.
     * @return the score of this player
     */
    int getScore() const{};
    /**
     * getNextMove.
     * @param b the board to check the next move in.
     * @return the next move choice.
     */
    string getNextMove(Board* b){};
    /**
     * getMovesForPlayer.
     * @param gameBoard the board to check on.
     * @param sign the player sign.
     * @return the optional moves.
     */
    vector<cell_t> getMovesForPlayer(Board* gameBoard, char sign) const {};
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    void setSign();
    bool canContinue;
};


#endif //EX2_CLIENT_H
