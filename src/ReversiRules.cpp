

#include <cstring>
#include "../include/ReversiRules.h"

ReversiRules::ReversiRules(GeneralPlayer* black, GeneralPlayer* white, Visualization* screen) {
    this->board_ = new Board(4, 4, black->getSign(), white->getSign());
    this->whiteP_ = white;
    this->blackP_ = black;
    now_ = blackP_;
    later_ = whiteP_;
    this->screen_ = screen;
    movesForCurrentPlayer = now_->getMovesForPlayer(this->board_, now_->getSign());
}

ReversiRules::~ReversiRules() {
    delete board_;
}

void ReversiRules::nextTurn() {
    int row = 0, col = 0;
    string choice, key;
    const char* choiceToSend;
    this->screen_->printOut(this->board_);
    this->screen_->printScore(blackP_->getSign(), blackP_->getScore(),
                              whiteP_->getSign(),whiteP_->getScore());
    //if the current player has no optional moves
    // he presses any key and the turn goes for the other player
    if (this->movesForCurrentPlayer.size() == 0) {
        //notify player he has no moves
        this->now_->noMovesForMe(this->screen_);
        this->now_->passTurn();
        //switch between players and updated movesforcurrentplayer
        this->movesForCurrentPlayer.clear();
        switchPlayers();
        this->movesForCurrentPlayer =
                now_->getMovesForPlayer(this->board_, now_->getSign());
        return;
        //if he has moves, let him choose one of them
    } else {
        now_->printMyOptions(this->screen_, this->movesForCurrentPlayer);
        choice = this->now_->getNextMove(this->board_);
        //if he didnt type a valid choice, make him choose again
        while(!thisIsAOption(choice)) {
            now_->printItsnAOption(this->screen_);
            //cin >> choice;
            choice.clear();
            choice = this->now_->getNextMove(this->board_);
        }
        //while (!isThatAnOption(choice)) {
            //this->screen_->printError();
            //cin >> choice;
        //}
    }
    choiceToSend = choice.c_str();
    this->now_->sendMove(choiceToSend);
    this->screen_->printWhichMovePlayed(now_->getSign(), choice);
    row = choice.at(0) -'0' - 1;
    col = choice.at(2) - '0' - 1;
    //set his choice to have his sign
    setPlayerDisk(row, col);
    //flip any disks standing in the way according to rules
    flipFrom(row, col);
    this->movesForCurrentPlayer.clear();
    //switch between players
    switchPlayers();
    this->movesForCurrentPlayer = now_->getMovesForPlayer(this->board_, now_->getSign());
}
bool ReversiRules::thisIsAOption(string choice) {
    for(int i = 0; i < this->movesForCurrentPlayer.size(); i++) {
        if(choice[0] -'0' - 1 == this->movesForCurrentPlayer[i].x && choice[2] -'0' - 1 == this->movesForCurrentPlayer[i].y) {
            return true;
        }
    }
    return false;
}
bool ReversiRules::gameover() {
    GeneralPlayer* temp = now_;
    if (board_->fullBoard()) {
        return true;
    }

    if (now_->getMovesForPlayer(this->board_, this->now_->getSign()).size() == 0) {
        if (later_->getMovesForPlayer(this->board_, this->later_->getSign()).size() == 0) {
            return true;
        }
        // switchPlayers();
    }
    return false;
}

void ReversiRules::setPlayerDisk(int row, int col) {
    //if we set it on the other player existing disk, we need to
    //reduce the other player score in 1
    if (board_->getSign(row,col)== later_->getSign()) {
        later_->scoreDown(1);
    }
    //if the desired place wasnt of the current player - add 1 to his score
    if (board_->getSign(row, col) != now_->getSign()) {
        now_->scoreUp(1);
    }
    //set the board to have this player disk in the desired position
    board_->setSign(row, col, now_->getSign());
}

void ReversiRules::flipFrom(int row, int col) {
    for (int i = 0; i < movesForCurrentPlayer.size(); i++) {
        if ((movesForCurrentPlayer[i].x == row) && (movesForCurrentPlayer[i].y == col)) {
            for (int j = 0; j < movesForCurrentPlayer[i].flip.size(); j++) {
                setPlayerDisk(movesForCurrentPlayer[i].flip[j].x, movesForCurrentPlayer[i].flip[j].y);
            }
        }
        movesForCurrentPlayer[i].flip.clear();
    }
}

void ReversiRules::whoWon() {
    int scoreBlackP = blackP_->getScore();
    int scoreWhiteP = whiteP_->getScore();
    char winner;
    this->screen_->printOut(this->board_);
    if (scoreBlackP > scoreWhiteP) {
        winner = blackP_->getSign();
    } else if (scoreWhiteP > scoreBlackP) {
        winner = whiteP_->getSign();
    } else {
        winner = 'T';
    }
    this->screen_->printScore(blackP_->getSign(), blackP_->getScore(), whiteP_->getSign(),whiteP_->getScore());
    this->screen_->printWinner(winner);

}

void ReversiRules::switchPlayers() {
    GeneralPlayer* temp = now_;
    this->now_ = later_;
    later_ = temp;
}
