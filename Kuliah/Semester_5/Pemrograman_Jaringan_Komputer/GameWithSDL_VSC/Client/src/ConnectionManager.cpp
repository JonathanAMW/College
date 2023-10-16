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

int ConnectionManager::SendData(const void* data, int dataLength) {
    if (clientSocket) {
        int sentBytes = SDLNet_TCP_Send(clientSocket, data, dataLength);
        if (sentBytes <= 0) {
            // std::cerr << "Failed to send data" << std::endl;
            // Handle send error
            return -1;
        }
    }

    return 0; // Success
}

int ConnectionManager::ReceiveData(void* data, int maxDataLength) {
    if (serverSocket) {
        int receivedBytes = SDLNet_TCP_Recv(serverSocket, data, maxDataLength);
        if (receivedBytes <= 0) {
            // std::cerr << "Failed to receive data" << std::endl;
            // Handle receive error or connection closed
            return -1;
        }

        return receivedBytes;
    }

    return 0; // No data received
}
