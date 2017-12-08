//
// Created by shay on 12/7/17.
//

#include <iostream>
#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(int sign, Client* c) {
    this->client = c;
    if (sign == 1) {
        this->sign_ = 'X';
    } else if (sign == 2) {
        this->sign_ = 'O';
    } else {
        this->sign_ = 'E'; //knowing thers an error;
    }
    this->disksNum_= 2;
}


/**
 *scoreUp.
 * @param num number of disks to add to the player's score
 */
void LocalPlayer::scoreUp(int num) {
    disksNum_ = disksNum_ + num;
}
/**
 * getSign.
 * @return the sign of this player
 */
char LocalPlayer::getSign() const {
    return sign_;
}
/**
 * getScore.
 * @return the score of this player
 */
int LocalPlayer::getScore() const {
    return disksNum_;
}
/**
 * scoreDown.
 * @param num a number to reduce from this player score
 */
void LocalPlayer::scoreDown(int num) {
    disksNum_ = disksNum_ - num;
}
/**
 * getMovesForPlayer.
 * @param gameBoard the board to check on.
 * @param sign the player sign.
 * @return the optional moves.
 */
vector<cell_t> LocalPlayer::getMovesForPlayer(Board* gameBoard, char sign) const {
    vector<cell_t> movesForCurrentPlayer;
    //finding out all locations of the current player on the board
    vector<point_t> locations = getLocationsOfPlayerOnBoard(sign, gameBoard);
    vector<point_t> movesPoints;
    bool add = true;
    //for each location of the current player -
    for (int i = 0; i < locations.size(); i++) {
        //look for optional moves.
        vector<cell_t> possibleMoves = possibleMovesForOneDisk(sign, locations[i], gameBoard);
        //add for the general list of the player
        for (int move = 0; move < possibleMoves.size(); move++) {
            add = true;
            struct point_t p;
            p.x =possibleMoves[move].x;
            p.y = possibleMoves[move].y;
            for (int k = 0; k < movesPoints.size(); k++) {
                if ((movesPoints[k].x == p.x) && (movesPoints[k].y == p.y)) {
                    add = false;
                }
            }
            if (add == true) {
                movesPoints.push_back(p);
            }

            movesForCurrentPlayer.push_back(possibleMoves.at(move));
        }
    }
    vector<cell_t> movesNoDuplicates;

    for (int point = 0; point < movesPoints.size(); point++) {
        int pointX = movesPoints[point].x;
        int pointY = movesPoints[point].y;
        vector<point_t> sharedPoints;
        for (int i = 0; i < movesForCurrentPlayer.size(); i++) {
            if ((movesForCurrentPlayer[i].x == pointX) && (movesForCurrentPlayer[i].y == pointY)) {
                sharedPoints.insert(sharedPoints.end(), movesForCurrentPlayer[i].flip.begin(), movesForCurrentPlayer[i].flip.end() );
            }
        }
        struct cell_t cell;
        cell.x = pointX;
        cell.y = pointY;
        cell.flip = sharedPoints;
        movesNoDuplicates.push_back(cell);
    }

    // return movesForCurrentPlayer;
    return movesNoDuplicates;
}
/**
*getLocationsOfPlayerOnBoard.
* @param sign player sign.
* @param gameBoard the board to check on the possible moves.
* @return vector of type point of al this player discs on board.
*/
vector<point_t> LocalPlayer::getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const {
    vector<point_t> locations;
    //for each row and col in the board
    for (int i = 0; i < gameBoard->getWidth(); i++) {
        for (int j = 0; j < gameBoard->getHeight(); j++) {
            //if its the same sign as we're looking for, add to the vector
            if (gameBoard->getSign(i,j) == sign) {
                struct point_t p;
                p.x = i;
                p.y = j;
                locations.push_back(p);
            }
        }
    }
    return locations;
}
/**
*possibleMovesForOneDisk.
* @param current sign of the current player.
* @param point the cell to check the possible moves for.
* @param gameBoard the board to check on.
* @return vector of cells that are possible moves of this player on the board.
*/
vector<cell_t> LocalPlayer::possibleMovesForOneDisk(char current, point_t point, Board* gameBoard) const {
    vector<cell_t> possibleMoves;
    vector<point_t> flippingPoints;
    //first checking the upper row left to right,
    // mid row left and right, lower row left to right
    for (int vertical = -1; vertical < 2; vertical++) {
        for (int horizontal = -1; horizontal < 2; horizontal++) {
            //keeping the intial values
            int verBackUp = vertical;
            int horBackUp = horizontal;
            //if the disk next to me is in another color
            // keep going that direction until its not in another color
            while (gameBoard->isInBorders(point.x + vertical, point.y + horizontal) &&
                   (gameBoard->getSign(point.x + vertical, point.y + horizontal) != current) &&
                   (gameBoard->getSign(point.x + vertical, point.y + horizontal) != ' ')) {
                //add this location as a flipping point for input point
                struct point_t flip;
                flip.x = point.x + vertical;
                flip.y = point.y + horizontal;
                flippingPoints.push_back(flip);
                vertical = vertical + verBackUp;
                horizontal = horizontal + horBackUp;

            }
            //if its empty and i moved more than one step -
            // its an optional move for the player
            if (gameBoard->isInBorders(point.x+ vertical, point.y + horizontal)) {
                if ((gameBoard->getSign(point.x + vertical,
                                        point.y + horizontal) == ' ') &&
                    ((horBackUp != horizontal) ||
                     (verBackUp != vertical))) {
                    struct cell_t possibleMove;
                    possibleMove.x = point.x +vertical;
                    possibleMove.y = point.y + horizontal;
                    possibleMove.flip = flippingPoints;
                    // flippingPoints.clear();
                    possibleMoves.push_back(possibleMove);
                }
            }
            flippingPoints.clear();
            //use the back ups to set them back to original,
            //so the changes wont harm the loop
            vertical = verBackUp;
            horizontal = horBackUp;
        }
    }
    return possibleMoves;
}
/**
 * getNextMove.
 * @param b the board to check the next move in.
 * @return the next move choice.
 */
string LocalPlayer::getNextMove(Board* b) {
    char* choice;
    cin >> choice;
    /*********************************************************
     * FIND A WAY TO CHECK VALID CHOICE
     */
    client->sendExercise(choice);
    string stringChoice = choice;
    return choice;
}

void LocalPlayer::printMyOptions(Visualization *screen, vector<cell_t> myoptions) const {
    screen->printOptions(this->getSign(), myoptions);

}


