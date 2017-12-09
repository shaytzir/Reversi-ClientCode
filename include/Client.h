
#ifndef EX2_CLIENT_H
#define EX2_CLIENT_H

#include "GeneralPlayer.h"

class Client{
public:
    /**
     * constructor.
     * @param serverIP the IP adress of the client.
     * @param serverPort the connection port.
     */
    Client(const char *serverIP, int serverPort);

    /**
     * connectToServer.
     * @return 1-if client is the firs player to connect, 2- if he is the second one.
     */
    int connectToServer();

    /**
     * sendMove.
     * @param choice send the choice to the server.
     */
    void sendMove(const char* choice);

    /**
     * getChoice.
     * @return the current choice of the client.
     */
    string getChoice();

    /**
     * getSign.
     * @return the client sign (if he is the first one to connect - 'X',
     * 'O' if he is the second player).
     */
    int getSign() const;
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX2_CLIENT_H