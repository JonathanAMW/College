#ifndef CONNECTION_MANAGER_HPP
#define CONNECTION_MANAGER_HPP

#include <iostream>
#include <SDL2/SDL_net.h>
#include <chrono>
#include <queue>


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
    bool SendData(const GameState& gameState, ClientMode clientMode);
    bool ReceiveData(GameState& gameState, ClientMode clientMode);

    std::chrono::milliseconds GetLatency() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(lastReceivedTime - lastSentTime);
    }


private:
    TCPsocket serverSocket;
    TCPsocket clientSocket;


    std::chrono::steady_clock::time_point lastSentTime;
    std::chrono::steady_clock::time_point lastReceivedTime;
    // std::queue<std::pair<std::chrono::steady_clock::time_point, GameState>> receivedDataQueue;


};

#endif // CONNECTION_MANAGER_HPP
