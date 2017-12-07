//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H

#include "ReversiRules.h"
#include "Visualization.h"

class GameFlow {
public:
    /**
     * constructor
     * @param black first player
     * @param white second player
     * @param screen a visualization variable - defined how to show the game
     */
    GameFlow(GeneralPlayer* black, GeneralPlayer* white, Visualization* screen);
    /**
     * destructor
     */
    ~GameFlow();
    /**
     * run.
     * This function runs the game according to a certain game logic.
     * Stops when the game is over.
     */
    void run();
private:
    ReversiRules* currentGame_;
    Visualization* screen_;
};

#endif //EX2_GAMEFLOW_H
