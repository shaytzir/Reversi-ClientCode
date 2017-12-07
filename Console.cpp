//
// Shay Tzirin
// ID: 315314930
// YUval Hoch
// 204468474
//

#include <cstdlib>
#include "Console.h"
/**
 * printScore.
 * @param player1 the firs player.
 * @param player2 the second player.
 * Print the current scores of the players.
 */
void Console::printScore(GeneralPlayer *player1, GeneralPlayer *player2) const {
    cout << "----------------------" << '\n' << "    Current score:" << endl;
    cout << "      " << player1->getSign() << ":" << player1->getScore() << "    "
         << player2->getSign() << ":" << player2->getScore() << '\n' << "----------------------" << endl;
}
/**
 * printOut.
 * @param gameBoard print this board on screen.
 */
void Console::printOut(Board* gameBoard) const {
    cout << gameBoard->printBoard();
}
/**
 * printError.
 * Print this massage if the input from the player is not from the options.
 */
void Console::printError() const {
    cout << "Your input is not from the options." << endl;
}
/**
 * printNoMoreMoves.
 * @param player the current player.
 * Print this massage if there are no more move possible moves.
 */
void Console::printNoMoreMoves(char player) const {
    cout << player << " played his move." << '\n'
         << "No possible moves. Play passes back to the other player. Press eny key to continue.";
}
/**
 * printOptions.
 * @param player the current player.
 * @param moves Print out all the player possible moves.
 */
void Console::printOptions(char player, vector <cell_t> moves) const {
    cout << player << ": It's your move." << '\n' << "Your possible moves: " << flush;
    this->options(moves);
    cout << '\n' << "Please enter your move row,col: " <<endl;
}
/**
 * options.
 * @param moves Print out the player possible moves.
 */
void Console::options(vector <cell_t> moves) const {
    //print - a vector without duplication options.
    vector < cell_t * > print;
    print.push_back(&moves.at(0));
    //For all the possible moves, check if there are to cells the same.
    for (int i = 0; i < moves.size(); i++) {
        if (!isAlreadyIn(print, moves.at(i))) {
            //If the option does'nt already in print, push back into print.
            print.push_back(&moves.at(i));
        }
    }
    //For all the non-duplicate options - print them out.
    for (int i = 0; i < print.size(); i++) {
        cout << "(" << print.at(i)->x + 1 << "," << print.at(i)->y + 1 << ")";
    }
}
/**
 * isAlreadyIn.
 * @param print the vector of the possible moves withput duplicate options.
 * @param c the cell to check if his in the vector.
 * @return if this c is in the vector already.
 * Check duplicate options.
 */
bool Console::isAlreadyIn(vector <cell_t*> print, cell_t c) const {
//For teh option in print - if c is already in - return false, else return true.
    for (int i = 0; i < print.size(); i++) {
        if (c.x == print.at(i)->x && c.y == print.at(i)->y) {
            return true;
        }
    }
    return false;
}
/**
 * printWinner.
 * @param winner the winner player.
 * Print out the winner of this game.
 */
void Console::printWinner(char winner) const {
    cout << "Game over!" << endl;
    if (winner == 'T') {
        cout << "It's a tie!" << endl;
        return;
    }
    cout << winner << " is the winner!!!" << endl;
}
/**
 * openScreen.
 * Print out the main menu of the game.
 */
void Console::openScreen() {
    cout << "Please enter your option:\n(1) Two humen players.\n(2) Play against the computer.\n(3) Play against remote player." << endl;
}

/**
* print the last move of the last player
*/
void Console::printWhichMovePlayed(char player, string move) {
    cout <<endl;
    cout << "Player " << player << " played " << move << endl;

}
