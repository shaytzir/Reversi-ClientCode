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
#include "LocalPlayer.h"

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
        Client* client = new Client("127.0.0.1", 8000);
        try {
            int sign = client->connectToServer();
            player1 = new LocalPlayer(sign, client);
            player2 = new RemotePlayer(sign, client);
            if (sign == 2) {
                GeneralPlayer* temp = player1;
                player1 = player2;
                player2 = temp;
            }
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
    delete player2;
    delete screen;
    return 0;
}