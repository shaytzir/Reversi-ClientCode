
#include <cstdlib>
#include "../include/Console.h"


void Console::printScore(char p1S, int player1,char p2S, int player2) const {
    cout << "----------------------" << '\n' << "    Current score:" << endl;
    cout << "      " << p1S << ":" << player1 << "    "
         << p2S << ":" << player2 << '\n' << "----------------------" << endl;
}


void Console::printOut(Board* gameBoard) const {
    cout << gameBoard->printBoard();
}


void Console::printError() const {
    cout << "Your input is not from the options." << endl;
}


void Console::printNoMoreMoves(char player) const {
    cout << player << " played his move." << '\n'
         << "No possible moves. Play passes back to the other player. Press eny key to continue.";
}

void Console::printOptions(char player, vector <cell_t> moves) const {
    cout <<  "It's "  << player << " move." << '\n' << "Your possible moves: " << flush;
    this->options(moves);
    cout << '\n' << "Please enter your move row,col: " <<endl;
}

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

bool Console::isAlreadyIn(vector <cell_t*> print, cell_t c) const {
//For the option in print - if c is already in - return false, else return true.
    for (int i = 0; i < print.size(); i++) {
        if (c.x == print.at(i)->x && c.y == print.at(i)->y) {
            return true;
        }
    }
    return false;
}


void Console::printWinner(char winner) const {
    cout << "Game over!" << endl;
    if (winner == 'T') {
        cout << "It's a tie!" << endl;
        return;
    }
    cout << winner << " is the winner!!!" << endl;
}


void Console::openScreen() {
    cout << "Please enter your option:\n(1) Two humen players.\n(2) Play against the computer.\n(3) Play against remote player." << endl;
}


void Console::printWhichMovePlayed(char player, string move) {
    cout <<endl;
    cout << "Player " << player << " played " << move << endl;

}
