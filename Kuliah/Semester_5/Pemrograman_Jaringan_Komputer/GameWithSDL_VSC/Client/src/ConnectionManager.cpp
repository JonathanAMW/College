#include <chrono>

#include "ConnectionManager.hpp"

const char* SERVER_IP = "127.0.0.1"; // Change this to the server's IP

ConnectionManager::ConnectionManager() : serverSocket(nullptr), clientSocket(nullptr) {
    if (SDLNet_Init() == -1) {
        std::cerr << "SDLNet_Init() failed: " << SDLNet_GetError() << std::endl;
        // Handle initialization error
    }
}

ConnectionManager::~ConnectionManager() {
    if (serverSocket) {
        SDLNet_TCP_Close(serverSocket);
    }

    if (clientSocket) {
        SDLNet_TCP_Close(clientSocket);
    }

    SDLNet_Quit();
}

int ConnectionManager::Init(std::string connectionType) {
    if (connectionType == "Server") {
        return RunAsServer();
    } else if (connectionType == "Client") {
        return RunAsClient();
    } else {
        return -1;
    }
}

int ConnectionManager::RunAsServer() {
    IPaddress serverIP;

    if (SDLNet_ResolveHost(&serverIP, nullptr, SERVER_PORT) == -1) {
        std::cerr << "SDLNet_ResolveHost() failed: " << SDLNet_GetError() << std::endl;
        return -1;
    }

    serverIP.host = INADDR_ANY;

    serverSocket = SDLNet_TCP_Open(&serverIP);
    if (!serverSocket) {
        std::cerr << "SDLNet_TCP_Open() failed: " << SDLNet_GetError() << std::endl;
        return -1;
    }

    std::cout << "Server started on port " << SERVER_PORT << std::endl;

    std::cout << "Waiting for client on port " << SERVER_PORT << std::endl;

    // Accept incoming client connections
    clientSocket = nullptr;
    while (!clientSocket) {
        clientSocket = SDLNet_TCP_Accept(serverSocket);
    }

    std::cout << "Found client on port " << SERVER_PORT << std::endl;


    return 0; // Success
}

int ConnectionManager::RunAsClient() {
    IPaddress clientIP;

    if (SDLNet_ResolveHost(&clientIP, SERVER_IP, SERVER_PORT) == -1) {
        std::cerr << "SDLNet_ResolveHost() failed: " << SDLNet_GetError() << std::endl;
        return -1;
    }

    clientSocket = SDLNet_TCP_Open(&clientIP);
    if (!clientSocket) {
        std::cerr << "SDLNet_TCP_Open() failed: " << SDLNet_GetError() << std::endl;
        return -1;
    }

    std::cout << "Connected to server at " << SERVER_IP << ":" << SERVER_PORT << std::endl;

    return 0; // Success
}

/*
IMPLEMENT LATENCY HANDLING 
BY USING TIMESTAMP
*/
bool ConnectionManager::SendData(const GameState& gameState, ClientMode connectionType) {
    char buffer[sizeof(GameState)];
    gameState.Serialize(buffer, sizeof(buffer));

    if (connectionType == ClientMode::SERVER && serverSocket) {
        // Add a time stamp to the data
        std::chrono::high_resolution_clock::time_point timeStamp = std::chrono::high_resolution_clock::now();
        memcpy(buffer + sizeof(GameState), &timeStamp, sizeof(timeStamp));

        int sentBytes = SDLNet_TCP_Send(clientSocket, buffer, sizeof(buffer));
        if (sentBytes <= 0) {
            std::cerr << "Server Failed to send data: " << SDLNet_GetError() << std::endl;
            return false; // Data not sent
        }
    } else if (connectionType == ClientMode::CLIENT && clientSocket) {
        // Add a time stamp to the data
        std::chrono::high_resolution_clock::time_point timeStamp = std::chrono::high_resolution_clock::now();
        memcpy(buffer + sizeof(GameState), &timeStamp, sizeof(timeStamp));

        int sentBytes = SDLNet_TCP_Send(clientSocket, buffer, sizeof(buffer));
        if (sentBytes <= 0) {
            std::cerr << "Client Failed to send data: " << SDLNet_GetError() << std::endl;
            return false; // Data not sent
        }
    } else {
        std::cerr << "Unknown connection type or no socket available in Send" << std::endl;
        return false; // Unknown connection type or no socket available
    }

    return true; // Data sent successfully
}

bool ConnectionManager::ReceiveData(GameState& gameState, ClientMode connectionType) {
    char buffer[sizeof(GameState) + sizeof(std::chrono::high_resolution_clock::time_point)];

    if (connectionType == ClientMode::SERVER && clientSocket) {
        int receivedBytes = SDLNet_TCP_Recv(clientSocket, buffer, sizeof(buffer));
        if (receivedBytes <= 0) {
            std::cerr << "Server Failed to receive data: " << SDLNet_GetError() << std::endl;
            return false; // Data not received
        }
        gameState.Deserialize(buffer, sizeof(GameState));

        // Extract the time stamp from the received data
        std::chrono::high_resolution_clock::time_point receivedTimeStamp;
        memcpy(&receivedTimeStamp, buffer + sizeof(GameState), sizeof(receivedTimeStamp));

        // Calculate the latency
        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> latency = std::chrono::duration_cast<std::chrono::duration<double>>(now - receivedTimeStamp);

        std::cout << "Latency: " << latency.count() << " seconds" << std::endl;

        return true; // Data received successfully
    } else if (connectionType == ClientMode::CLIENT && clientSocket) {
        int receivedBytes = SDLNet_TCP_Recv(clientSocket, buffer, sizeof(buffer));
        if (receivedBytes <= 0) {
            std::cerr << "Client Failed to receive data: " << SDLNet_GetError() << std::endl;
            return false; // Data not received
        }
        gameState.Deserialize(buffer, sizeof(GameState));

        // Extract the time stamp from the received data
        std::chrono::high_resolution_clock::time_point receivedTimeStamp;
        memcpy(&receivedTimeStamp, buffer + sizeof(GameState), sizeof(receivedTimeStamp));

        // Calculate the latency
        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> latency = std::chrono::duration_cast<std::chrono::duration<double>>(now - receivedTimeStamp);

        std::cout << "Latency: " << latency.count() << " seconds" << std::endl;

        return true; // Data received successfully
    }

    std::cerr << "Unknown connection type or no socket available in Receive" << std::endl;
    return false; // Unknown connection type or no socket available
}


/*
bool ConnectionManager::SendData(const GameState& gameState, ClientMode connectionType) {
    char buffer[sizeof(GameState)];
    gameState.Serialize(buffer, sizeof(buffer));

    if (connectionType == ClientMode::SERVER && serverSocket) {
        int sentBytes = SDLNet_TCP_Send(clientSocket, buffer, sizeof(buffer));
        if (sentBytes <= 0) {
            std::cerr << "Server Failed to send data: " << SDLNet_GetError() << std::endl;
            return false; // Data not sent
        }
    } else if (connectionType == ClientMode::CLIENT && clientSocket) {
        int sentBytes = SDLNet_TCP_Send(clientSocket, buffer, sizeof(buffer));
        if (sentBytes <= 0) {
            std::cerr << "Client Failed to send data: " << SDLNet_GetError() << std::endl;
            return false; // Data not sent
        }
    } else {
        std::cerr << "Unknown connection type or no socket available in Send" << std::endl;
        return false; // Unknown connection type or no socket available
    }

    return true; // Data sent successfully
}

bool ConnectionManager::ReceiveData(GameState& gameState, ClientMode connectionType) {
    char buffer[sizeof(GameState)];

    if (connectionType == ClientMode::SERVER && clientSocket) {
        int receivedBytes = SDLNet_TCP_Recv(clientSocket, buffer, sizeof(buffer));
        if (receivedBytes <= 0) {
            std::cerr << "Server Failed to receive data: " << SDLNet_GetError() << std::endl;
            return false; // Data not received
        }
        gameState.Deserialize(buffer, sizeof(buffer));
        return true; // Data received successfully
    } else if (connectionType == ClientMode::CLIENT && clientSocket) {
        int receivedBytes = SDLNet_TCP_Recv(clientSocket, buffer, sizeof(buffer));
        if (receivedBytes <= 0) {
            std::cerr << "Client Failed to receive data: " << SDLNet_GetError() << std::endl;
            return false; // Data not received
        }
        gameState.Deserialize(buffer, sizeof(buffer));
        return true; // Data received successfully
    }

    std::cerr << "Unknown connection type or no socket available in Receive" << std::endl;
    return false; // Unknown connection type or no socket available
}
*/