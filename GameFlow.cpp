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
    //stringstream toShow;
    //as long as the game isnt over, keep switching turns
    do {
        currentGame_->nextTurn();
    } while (!currentGame_->gameover());
    //when the game is over show who won
    //toShow<< "game is over" << endl;
    //this->screen_->show(toShow.str());

    currentGame_->whoWon();
}
/**
 * constructor
 * @param black first player
 * @param white second player
 * @param screen a visualization variable - defined how to show the game
 */
GameFlow::GameFlow(GeneralPlayer* black,
                   GeneralPlayer* white, Visualization* screen) {
    currentGame_ = new ReversiRules(black, white, screen);
    this->screen_ = screen;
}
/**
 * destructor
 */
GameFlow::~GameFlow() {
    delete currentGame_;
}
