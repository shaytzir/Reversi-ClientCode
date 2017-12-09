//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include "../include/GeneralPlayer.h"
#include "../include/HumanP.h"
#include "../include/AIPlayer.h"
#include "../include/Visualization.h"
#include "../include/GameFlow.h"
#include "../include/Console.h"
#include "../include/Client.h"
#include "../include/RemotePlayer.h"
#include "../include/LocalPlayer.h"

int main() {
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
        //read client configuration and connect to server
        ifstream inFile;
        inFile.open("./exe/ClientConfig.txt");
        string ip;
        const char* IP;
        int port;
        inFile >> ip;
        inFile >> port;
        IP = ip.c_str();
        try {
            //Client* client = new Client(ip.c_str(), port); //doesnt work with reading from file
            Client* client = new Client(IP, port);
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