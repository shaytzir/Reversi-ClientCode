#include <sstream>
#include <algorithm>
#include "../include/AIPlayer.h"


AIPlayer::AIPlayer(char playerSign) {
    sign_ = playerSign;
    disksNum_ = 2;
}

void AIPlayer::scoreUp(int num) {
    disksNum_ = disksNum_ + num;
}

char AIPlayer::getSign() const {
    return sign_;
}

int AIPlayer::getScore() const {
    return disksNum_;
}

void AIPlayer::scoreDown(int num) {
    disksNum_ = disksNum_ - num;
}

string AIPlayer::getNextMove(Board* gameBoard) {
    int bestChoice[4], score = 0, alreadyChecked = -1;
    //The move to return as string.
    string choice;
    choice.clear();
    //Check the optional moves for AIPlayer.
    vector<cell_t> moves = getMovesForPlayer(gameBoard, this->sign_);
    //Get the first choice score.
    //In bestChoice[0] - put the row choice.
    bestChoice[0] = moves[0].x + 1;
    //In bestChoice[1] - put the column choice.
    bestChoice[1] = moves[0].y + 1;
    //In bestChoice[2] - put the minimum score of the maximum score of the other player.
    bestChoice[2] = setPlayerDisk(moves[0], gameBoard);
    //In bestChoice[3] - put the index of this choice in the moves vector, for after check.
    bestChoice[3] = 0;
    //Check the other scores for etch possible choice,
    // if that score is min - put it into bestChoice.
    for (int i = 1; i < moves.size(); i++) {
        if (bestChoice[2] > (score = setPlayerDisk(moves[i], gameBoard))) {
            //Else, if there is lower score than the current best score, replace them.
            bestChoice[0] = moves[i].x + 1;
            bestChoice[1] = moves[i].y + 1;
            bestChoice[2] = score;
            bestChoice[3] = i;
        }
    }
    //Return the best choice as string.
    stringstream c;
    c << bestChoice[0] << "," << bestChoice[1];
    choice = c.str();
    return choice;
}

vector<cell_t> AIPlayer::getMovesForPlayer(Board* gameBoard, char sign) const {
    vector<cell_t> movesForCurrentPlayer;
    //finding out all locations of the current player on the board
    vector<point_t> locations = getLocationsOfPlayerOnBoard(sign, gameBoard);
    vector<point_t> movesPoints;
    bool add = true;
    //for each location of the current player -
    for (int i = 0; i < locations.size(); i++) {
        //look for optional moves.
        vector<cell_t> possibleMoves =
                possibleMovesForOneDisk(sign, locations[i], gameBoard);
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
            if ((movesForCurrentPlayer[i].x == pointX)
                && (movesForCurrentPlayer[i].y == pointY)) {
                sharedPoints.insert(sharedPoints.end(),
                                    movesForCurrentPlayer[i].flip.begin(),
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

vector<point_t> AIPlayer::getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const {
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

vector<cell_t> AIPlayer::possibleMovesForOneDisk(char current, point_t point, Board* &gameBoard) const {
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


int AIPlayer::setPlayerDisk(cell_t cell, Board* gameBoard) const {
    int otherScore = -1, i, maxScore = 0;
    vector<cell_t> movesForOtherPlayer;
    char otherSign;
    Board* boardCopy = new Board(gameBoard);
    int playerAIScore = this->getScore();
    int otherPlayerScore = 0;
    //Set the cell with this player disc.

    boardCopy->getMatrix()[cell.x][cell.y] = this->sign_;
    playerAIScore += 1;
    //Set all the fliping cells of this choice with this player disc.
    for (i = 0; i < cell.flip.size(); i ++) {
        boardCopy->getMatrix()[cell.flip[i].x][cell.flip[i].y] = this->sign_;
        playerAIScore += 1;

    }
    //Check the other player sign.
    for (i = 0; i < boardCopy->getHeight(); i++) {
        for (int j = 0; j < boardCopy->getWidth(); j++) {
            if (boardCopy->getMatrix()[i][j] != this->sign_ && boardCopy->getMatrix()[i][j] != ' ') {
                otherSign = boardCopy->getMatrix()[i][j];
                otherPlayerScore += 1;
            }
        }
    }
    //Check the other player options after AIPlayer played his optional move.
    movesForOtherPlayer = getMovesForPlayer(boardCopy, otherSign);
    //If other player have optional moves, set score with the maximum score he can get.
    for (int j = 0; j < movesForOtherPlayer.size(); j++) {

        int otherScore = otherPlayerScore + 1 + movesForOtherPlayer[j].flip.size() -
                         (playerAIScore - movesForOtherPlayer[j].flip.size());
        if (otherScore > maxScore) {
            maxScore = otherScore;
        }
    }
    delete boardCopy;

    return otherScore;
}

void AIPlayer::printMyOptions(Visualization *screen, vector<cell_t> myoptions) const {
    screen->printOptions(this->getSign(), myoptions);
}


void AIPlayer::passTurn() {
    //gets an input and ignores it
    string key;
    cin >> key;
}

void AIPlayer::noMovesForMe(Visualization *screen) {
    //prints normally the message of  "no moves. type anything.."
    screen->printNoMoreMoves(this->getSign());

}
void AIPlayer::printItsnAOption(Visualization* screen) const {
    screen->printError();
}