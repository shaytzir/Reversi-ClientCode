//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <sstream>
#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(int playerSign, Client* c) {
    if (playerSign == 1) {
        this->sign_ = 'O';
    } else {
        this->sign_ = 'X';
    }
    this->disksNum_ = 2;
    this->client = c;
}

void RemotePlayer::scoreUp(int num) {
    disksNum_ = disksNum_ + num;
}

char RemotePlayer::getSign() const {
    return sign_;
}

int RemotePlayer::getScore() const {
    return disksNum_;
}

void RemotePlayer::scoreDown(int num) {
    disksNum_ = disksNum_ - num;
}

string RemotePlayer::getNextMove(Board* gameBoard) {
    //the remote player doesnt choose his own move, he waits for the other player move
    string choice;
    choice.clear();
    choice = this->client->getChoice();
    return choice;
}

vector<cell_t> RemotePlayer::getMovesForPlayer(Board* gameBoard, char sign) const {

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
                sharedPoints.insert(sharedPoints.end(), movesForCurrentPlayer[i].flip.begin(),
                                    movesForCurrentPlayer[i].flip.end() );
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

vector<point_t> RemotePlayer::getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const {
    vector<point_t> locations;
    //for each row and col in the board.
    for (int i = 0; i < gameBoard->getWidth(); i++) {
        for (int j = 0; j < gameBoard->getHeight(); j++) {
            //if it's the same sign as we're looking for, add to the vector.
            if (gameBoard->getMatrix()[i][j] == sign) {
                //Create naw struct point of the location.
                struct point_t p;
                p.x = i;
                p.y = j;
                locations.push_back(p);
            }
        }
    }
    return locations;
}

vector<cell_t> RemotePlayer::possibleMovesForOneDisk(char current, point_t point, Board* &gameBoard) const {
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
                   (gameBoard->getMatrix()[point.x + vertical][point.y + horizontal] != current) &&
                   (gameBoard->getMatrix()[point.x + vertical][point.y + horizontal] != ' ')) {
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
                if ((gameBoard->getMatrix()[point.x + vertical][point.y + horizontal] == ' ') &&
                    ((horBackUp != horizontal) ||
                     (verBackUp != vertical))) {
                    struct cell_t possibleMove;
                    possibleMove.x = point.x +vertical;
                    possibleMove.y = point.y + horizontal;
                    possibleMove.flip = flippingPoints;
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

void RemotePlayer::printMyOptions(Visualization *screen, vector<cell_t> myoptions) const {
    cout << "waiting for the other player move..." << endl;
}

void RemotePlayer::passTurn() {
    //waits untill it gets the "NoMove" message
    string noMove = this->client->getChoice();
}