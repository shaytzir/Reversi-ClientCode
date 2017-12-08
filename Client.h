//
// Created by shay on 12/6/17.
//

#ifndef EX2_CLIENT_H
#define EX2_CLIENT_H

#include "GeneralPlayer.h"

class Client{
public:
    Client(const char *serverIP, int serverPort);
    int connectToServer();
    void sendExercise(char* choice);
    char* getChoice();
    int getSign() const;

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX2_CLIENT_H
