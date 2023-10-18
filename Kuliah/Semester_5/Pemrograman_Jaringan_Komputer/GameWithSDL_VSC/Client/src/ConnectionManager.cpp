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

    if (SDLNet_ResolveHost(&serverIP, NULL, SERVER_PORT) == -1) {
        std::cerr << "SDLNet_ResolveHost() failed: " << SDLNet_GetError() << std::endl;
        // Handle resolving host error
        return -1;
    }

    // Set the server to listen on any available network interface
    serverIP.host = INADDR_ANY;

    serverSocket = SDLNet_TCP_Open(&serverIP);
    if (!serverSocket) {
        std::cerr << "SDLNet_TCP_Open() failed: " << SDLNet_GetError() << std::endl;
        // Handle socket open error
        return -1;
    }

    std::cout << "Server started on port " << SERVER_PORT << std::endl;

    // Implement server logic here

    return 0; // Success
}

int ConnectionManager::RunAsClient() {
    IPaddress clientIP;

    if (SDLNet_ResolveHost(&clientIP, SERVER_IP, SERVER_PORT) == -1) {
        std::cerr << "SDLNet_ResolveHost() failed: " << SDLNet_GetError() << std::endl;
        // Handle resolving host error
        return -1;
    }

    clientSocket = SDLNet_TCP_Open(&clientIP);
    if (!clientSocket) {
        std::cerr << "SDLNet_TCP_Open() failed: " << SDLNet_GetError() << std::endl;
        // Handle socket open error
        return -1;
    }

    std::cout << "Connected to server at " << SERVER_IP << ":" << SERVER_PORT << std::endl;

    // Implement client logic here

    return 0; // Success
}

int ConnectionManager::SendData(const GameState& gameState, ClientMode clientMode) {
    // char buffer[sizeof(GameState)];
    // gameState.Serialize(buffer, sizeof(buffer));

    // Sending data:
    char buffer[sizeof(TankState)];
    gameState.Serialize(buffer, sizeof(buffer));


    if (clientMode == ClientMode::SERVER) {
        if (clientSocket) {
            int sentBytes = SDLNet_TCP_Send(clientSocket, buffer, sizeof(buffer));
            if (sentBytes <= 0) {
                std::cerr << "Failed to send data: " << SDLNet_GetError() << std::endl;
                return -1;
            }
        }
        
    } else if (clientMode == ClientMode::CLIENT) {
        if (serverSocket) {
            int sentBytes = SDLNet_TCP_Send(serverSocket, buffer, sizeof(buffer));
            if (sentBytes <= 0) {
                std::cerr << "Failed to send data: " << SDLNet_GetError() << std::endl;
                return -1;
            }
        }
    }

    return 0; // Success
}

int ConnectionManager::ReceiveData(GameState& gameState, ClientMode clientMode) {
    // char buffer[sizeof(GameState)];

    // Receiving data:
    char buffer[sizeof(TankState)];
   
    if (clientMode == ClientMode::SERVER) {
        if (clientSocket) {
            int receivedBytes = SDLNet_TCP_Recv(clientSocket, buffer, sizeof(buffer));
            if (receivedBytes <= 0) {
                std::cerr << "Failed to receive data: " << SDLNet_GetError() << std::endl;
                return -1;
            }
            // gameState.Deserialize(buffer, sizeof(buffer));
            gameState.Deserialize(buffer, sizeof(buffer));

            return receivedBytes;
        }
    } else if (clientMode == ClientMode::CLIENT) {
        if (serverSocket) {
            int receivedBytes = SDLNet_TCP_Recv(serverSocket, buffer, sizeof(buffer));
            if (receivedBytes <= 0) {
                std::cerr << "Failed to receive data: " << SDLNet_GetError() << std::endl;
                return -1;
            }
            // gameState.Deserialize(buffer, sizeof(buffer));
            gameState.Deserialize(buffer, sizeof(buffer));

            return receivedBytes;
        }
    }

    return 0; // No data received
}


