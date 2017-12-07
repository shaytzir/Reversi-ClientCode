//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include "Board.h"
#include "GeneralPlayer.h"
#include <iostream>
#include <sstream>
using namespace std;

/**
 * constructor.
 * @param wid width of table.
 * @param len length of table.
 * @param first sign of first player.
 * @param second sugn of second player.
 */
Board::Board(int wid, int len, char first, char second) {
    width_ = wid;
    length_ = len;
    verticalSep_ = '|';
    horizontalSep_ = '-';
    //creating a dynamic array
    matrix_ = new char*[width_];
    //which holds arrays
    for (int i = 0; i < width_; i++) {
        matrix_[i] = new char[length_];
    }
    //setting all board to be empty disks
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < length_; j++) {
            matrix_[i][j] = ' ';
        }
    }
    //setting start of the game
    int midRow = width_ / 2;
    int midCol = length_ / 2;
    matrix_[midRow - 1][midCol - 1] = second;
    matrix_[midRow + 1 - 1 ][midCol + 1 -1] = second;
    matrix_[midRow - 1][midCol + 1 - 1] = first;
    matrix_[midRow + 1 - 1][midCol - 1] = first;
}
/**
 * copy constructor.
 * @param b the board to copy.
 */
Board::Board(Board *b) {
    width_ = b->width_;
    length_ = b->length_;
    verticalSep_ = b->verticalSep_; //vertical seperator
    horizontalSep_ = b->horizontalSep_; //horizontal
    //creating a dynamic array
    matrix_ = new char*[width_];
    //which holds arrays
    for (int i = 0; i < width_; i++) {
        matrix_[i] = new char[length_];
    }
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < length_; j++) {
            matrix_[i][j] = b->matrix_[i][j];
        }
    }
    size = b->size;
}
/**
 * printBoard.
 * @return the board as string for sending him to the visual class.
 */
string Board::printBoard() {
    //creating the upper border of the table
    stringstream boardToShow;
    boardToShow << " curent board is: " << endl;
    for (int i = 0; i < width_; i++) {
        boardToShow << " | " << i+1;
    }
    boardToShow << " " << verticalSep_ << endl;
    for (int i = 0; i < width_; i++) {
        //creating a seperator line of '-'
        for (int j = 0; j < ((width_ * 2) + 1) * 2; j++) {
            boardToShow << horizontalSep_;
        }
        boardToShow << endl;
        for (int c = 0; c < length_; c++) {
            //mark which line it is
            if (c == 0) {
                boardToShow << i + 1 << verticalSep_;
                //if the table hold a player - print it's mark
            }
            if (matrix_[i][c] != ' ') {
                boardToShow << ' ' << matrix_[i][c]
                            << ' ' << verticalSep_;
            } else { //keep clear
                boardToShow << "   " << verticalSep_;
            }
        }
        boardToShow << endl;
    }
    //adds the last line of '-'
    for (int j = 0; j < ((width_ * 2) + 1) * 2; j++) {
        boardToShow << horizontalSep_;
    }
    boardToShow << endl;
    return boardToShow.str();
}
/**
 * a destructor.
 */
Board::~Board() {
    //frees all arrays kept in the main array
    for (int i = 0; i < width_; i++)
        delete [] matrix_[i];
    //deletes main array
    delete [] matrix_;
}
/**
 *getWidth.
 * @return width of matrix
 */
int Board::getWidth() {
    return this->width_;
}
/**
 *getHeight.
 * @return length of matrix
 */
int Board::getHeight() {
    return this->length_;
}
/**
 *getSign.
 * @param row
 * @param col
 * @return  the disk which is in row,col cell
 */
char Board::getSign(int row, int col) {
    return matrix_[row][col];
}
/**
 *setSign.
 * @param row
 * @param col
 * @param sign setting the disk at the row,col cell to have another sign
 */
void Board::setSign(int row, int col, char sign) {
    matrix_[row][col] = sign;
}
/**
 *isInBorders.
 * @param row
 * @param col
 * @return yes if row,col if part of the matrix
 */
bool Board::isInBorders(int row, int col) {
    if ((!(row < 0)) && (!(row > getHeight() - 1)) && (!(col < 0)) &&
        (!(col > getWidth() - 1))) {
        return true;
    }
    return false;
}
/**
 *fullBoard.
 * @return true if of all cells are set, otherwise false
 */
bool Board::fullBoard() {
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < length_; j++) {
            if (matrix_[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
/**
* getMatrix.
* @return this board current matrix.
*/char** Board::getMatrix() const{
    return this->matrix_;
}
