#ifndef CONNECTION_MANAGER_HPP
#define CONNECTION_MANAGER_HPP

#include <iostream>
#include <SDL2/SDL_net.h>


#include "Config.hpp"
#include "GameState.hpp"

const int SERVER_PORT = 12345; // Change to your desired port

class ConnectionManager {
public:
    ConnectionManager();
    ~ConnectionManager();

    int Init(std::string connectionType);
    int RunAsServer();
    int RunAsClient();
    int SendData(const GameState& gameState, ClientMode clientMode);
    int ReceiveData(GameState& gameState, ClientMode clientMode);

private:
    TCPsocket serverSocket;
    TCPsocket clientSocket;
};

#endif // CONNECTION_MANAGER_HPP
