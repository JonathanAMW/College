#ifndef CONNECTION_MANAGER_HPP
#define CONNECTION_MANAGER_HPP

#include <iostream>
#include <SDL2/SDL_net.h>

const int SERVER_PORT = 12345; // Change to your desired port

class ConnectionManager {
public:
    ConnectionManager();
    ~ConnectionManager();

    int Init(std::string connectionType);
    int RunAsServer();
    int RunAsClient();
    int SendData(const void* data, int dataLength);
    int ReceiveData(void* data, int maxDataLength);

private:
    TCPsocket serverSocket;
    TCPsocket clientSocket;
};

#endif // CONNECTION_MANAGER_HPP
