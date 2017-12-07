//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <string>


using namespace std;

class Board {
public:
    /**
<<<<<<< HEAD
    * constructor.
    * @param wid width of table.
    * @param len length of table.
    * @param first sign of first player.
    * @param second sugn of second player.
    */
    Board(int wid, int len, char first, char second);
    /**
     * default constructor.
     */
    Board();
    /**
     * a destructor.
     */
    ~Board();
    /**
     *isInBorders.
     * @param row
     * @param col
     * @return yes if row,col if part of the matrix
     */
    bool isInBorders(int row, int col);
    /**
     *fullBoard.
     * @return true if of all cells are set, otherwise false
     */
    bool fullBoard();
    /**
     *getSign.
     * @param row
     * @param col
     * @return  the disk which is in row,col cell
     */
    char getSign(int row, int col);
    /**
     *setSign.
     * @param row
     * @param col
     * @param sign setting the disk at the row,col cell to have another sign
     */
    void setSign(int row, int col, char sign);
    /**
     *getWidth.
     * @return width of matrix
     */
    int getWidth();
    /**
     *getHeight.
     * @return length of matrix
     */
    int getHeight();
    /**
     * copy constructor.
     * @param b the board to copy.
     */
    Board(Board *b);
    /**
     * printBoard.
     * @return the board as string for sending him to the visual class.
     */
    string printBoard();
    /**
    * getMatrix.
    * @return this board current matrix.
    */
    char** getMatrix() const;
private:
    int width_;
    int length_;
    char verticalSep_; //vertical separator
    char horizontalSep_; //horizontal
    char **matrix_;
    int size;
};

#endif //EX2_BOARD_H
