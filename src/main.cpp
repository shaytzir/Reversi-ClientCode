//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <cstdlib>
#include <fstream>
#include "../include/GeneralPlayer.h"
#include "../include/HumanP.h"
#include "../include/AIPlayer.h"
#include "../include/GameFlow.h"
#include "../include/Console.h"
#include "../include/Client.h"
#include "../include/RemotePlayer.h"
#include "../include/LocalPlayer.h"

int main() {
    Client* client;
    GeneralPlayer *player1, *player2;
    Visualization* screen = new Console();
    int choice, sign;
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
        //read client configuration and connect to server
        /*ifstream inFile;
        inFile.open("ClientConfig.txt");
        string ip;
        const char* IP;
        int port;
        inFile >> ip;
        inFile >> port;*/
        string ip = "127.0.0.1";/////////////////
        int port = 8000;//////////////////
        const char* IP = ip.c_str();
        string listOfGames;
        try {
            client = new Client(IP, port, screen);
            do {
                screen->subMenuRemote();
                sign = client->connectToServer();
            }while (sign == -1);
            if (sign == 0) {
                delete screen;
                delete client;
                return 0;
            }
            player1 = new LocalPlayer(sign, client);
            player2 = new RemotePlayer(sign, client);
            if (sign == 2) {
                GeneralPlayer* temp = player1;
                player1 = player2;
                player2 = temp;
            }
        } catch (const char *msg) {
            screen->printMessage("Failed to connect to server. Reason: ");
            screen->printMessage(msg);
            exit(-1);
        }
    }

    try {
        //creates new game
        GameFlow game(player1, player2, screen);
        //runs the game
        game.run();
    } catch (const char *msg) {
        screen->printMessage("Server is shutting...");
        delete player1;
        delete player2;
        delete client;
        delete screen;
        return 0;
    }
    delete player1;
    delete player2;
    delete client;
    delete screen;
    return 0;
}