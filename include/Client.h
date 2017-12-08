
#ifndef EX2_CLIENT_H
#define EX2_CLIENT_H

#include "GeneralPlayer.h"

class Client{
public:
    Client(const char *serverIP, int serverPort);
    int connectToServer();
    void sendMove(char* choice);
    string getChoice();
    int getSign() const;

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX2_CLIENT_H
