//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include "GameFlow.h"

/**
 * run.
 * This function runs the game according to a certain game logic.
 * Stops when the game is over.
 */
void GameFlow::run() {
    //as long as the game isnt over, keep switching turns
    do {
        currentGame_->nextTurn();
    } while (!currentGame_->gameover());
    currentGame_->whoWon();
}
/**
 * constructor
 * @param black first player
 * @param white second player
 * @param screen a visualization variable - defined how to show the game
 */
GameFlow::GameFlow(GeneralPlayer* first,
                   GeneralPlayer* second, Visualization* screen) {
    currentGame_ = new ReversiRules(first, second, screen);
    this->screen_ = screen;
}
/**
 * destructor
 */
GameFlow::~GameFlow() {
    delete currentGame_;
}
