//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include "../include/Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

using namespace std;
Client::Client(const char *serverIP, int serverPort, Visualization *v):
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    this->screen = v;
    screen->printMessage("Client");
}
int Client::connectToServer() {
    int sign;
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char
    *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    //////////////////////////////////////////////////////////////

    sendChoice();
    //getMessage();
    //////////////////////////////////////////////////////////////

    int n = read(clientSocket, &sign, sizeof(sign));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    if (n == 0) {
        screen->printMessage("server is closing...");
        return 0;
    }
    return sign;
}

void Client::sendMove(const char* choice) {
    // Write the desired move of the player
    int n  = write(clientSocket, choice, sizeof(choice));
    if (n == -1) {
        throw "Error writing op to socket";
    }
}

int Client::getSign() const{
    int sign;
    int n = read(clientSocket, &sign, sizeof(sign));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return sign;
}

string Client::getChoice() {
    char *userChoice = new char[10];
    // read from socket
    int n = read(clientSocket, userChoice, 10);
    if (n == -1) {
        throw "Error of reading from socket";
    }
    string choice;
    choice.clear();
    choice = userChoice;
    delete[] userChoice;
    return choice;
}

void Client::sendChoice() {
    char *commandChar, c;
    string command, command2;
    int i;
    cin >> command;
    commandChar = new char[command.length() + 1];
    strcpy(commandChar, command.c_str());
    if (command == "list_games") {
        for (i = 0; i < command.length(); i++) {
            write(clientSocket, &commandChar[i], sizeof(commandChar[i]));
        }
        getListOfGames();
    } else {
        for (i = 0; i < command.length(); i++) {
            write(clientSocket, &commandChar[i], sizeof(commandChar[i]));
        }
        cin >> command;
        commandChar = new char[command.length() + 1];
        strcpy(commandChar, command.c_str());
        c = '<';
        write(clientSocket, &c, sizeof(c));
        for (i = 0; i < command.length(); i++) {
            write(clientSocket, &commandChar[i], sizeof(commandChar[i]));
        }
        c = '>';
        write(clientSocket, &c, sizeof(c));
    }
}

void Client::getMessage() {
    int messageNum;
    int n = read(clientSocket, &messageNum, sizeof(messageNum));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    if (messageNum == 1) {
        screen->printMessage("New game is available. Wait for another player to connect.");
    } else if (messageNum == 2) {
        screen->printMessage("You joined to the game.");
    }
}

void Client::getListOfGames() {
    char gameNameChar;
    string commandStr;
    do {
        read(this->clientSocket, &gameNameChar, sizeof(gameNameChar));
        commandStr.append(1u, gameNameChar);
    }while (gameNameChar != '\n');
    this->screen->gameList(commandStr);
}