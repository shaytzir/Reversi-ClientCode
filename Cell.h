//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H

#include <vector>
#include "Point.h"
using namespace std;

/**
 * cell_t.
 * A struct for every cell in the board.
 */
struct cell_t{
    //Column.
    int x;
    //Row.
    int y;
    //All the cells that the player flips if he choose this cell.
    vector <point_t> flip;
};

#endif //REVERSI_CELL_H