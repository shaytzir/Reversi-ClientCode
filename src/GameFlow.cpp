

#include "../include/GameFlow.h"


void GameFlow::run() {
    //as long as the game isnt over, keep switching turns
    do {
        currentGame_->nextTurn();
    } while (!currentGame_->gameover());
    currentGame_->whoWon();
}

GameFlow::GameFlow(GeneralPlayer* first,
                   GeneralPlayer* second, Visualization* screen) {
    currentGame_ = new ReversiRules(first, second, screen);
    this->screen_ = screen;
}

GameFlow::~GameFlow() {
    delete currentGame_;
}
