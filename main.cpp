//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <cstdlib>
#include <unistd.h>
#include "GeneralPlayer.h"
#include "HumanP.h"
#include "AIPlayer.h"
#include "Visualization.h"
#include "GameFlow.h"
#include "Console.h"
#include "Client.h"
#include "RemotePlayer.h"

int main() {
    int num1, num2;
    char op;
    GeneralPlayer *player1, *player2;
    Visualization* screen = new Console();
    int choice;
    screen->openScreen();
    cin >> choice;
    //create two players
    if (choice == 1) {
        player1 = new HumanP('X');
        player2 = new HumanP('O');
    } else if (choice == 2) {
        player1 = new HumanP('X');
        player2 = new AIPlayer('O');
    } else if (choice == 3) {
        player1 = new Client("127.0.0.1", 8000);
        try {
            player1->connectToServer();
            player1->setSign();
            char sign = player1->getSign();
            player2 = new RemotePlayer(sign);
        } catch (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
            exit(-1);
        }
    }

    //creates new game
    GameFlow game(player1, player2, screen);
    //runs the game
    game.run();
    delete player1;
    delete player1;
    delete screen;
    return 0;
}