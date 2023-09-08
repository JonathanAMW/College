#include <iostream>
#include <winsock2.h>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }


    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    //adjust server maximum tcp of server socket
    int receiveBufferSize = 1024 * 1024; // Set the receive buffer size to 1 MB (for example)

    // Set the receive buffer size for the server socket
    if (setsockopt(serverSocket, SOL_SOCKET, SO_RCVBUF, (const char*)&receiveBufferSize, sizeof(int)) == SOCKET_ERROR) {
        std::cerr << "Setsockopt for server socket failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }


    // Bind the socket to a specific address and port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 12345..." << std::endl;

    std::vector<SOCKET> clientSockets;

    while (true) {
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(serverSocket, &readSet);

        for (SOCKET client : clientSockets) {
            FD_SET(client, &readSet);
        }

        // Use select to wait for activity on any socket
        int selectResult = select(0, &readSet, nullptr, nullptr, nullptr);
        if (selectResult == SOCKET_ERROR) {
            std::cerr << "Select failed." << std::endl;
            break;
        }

        if (FD_ISSET(serverSocket, &readSet)) {
            // New client connection
            SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket == INVALID_SOCKET) {
                std::cerr << "Accept failed." << std::endl;
            }
            else {
                std::cout << "Client connected." << std::endl;
                clientSockets.push_back(clientSocket);
            }
        }

        for (int i = 0; i < clientSockets.size(); i++) {
            if (FD_ISSET(clientSockets[i], &readSet)) {
                // Receive and send messages for this client
                char buffer[1024];
                int bytesReceived = recv(clientSockets[i], buffer, sizeof(buffer), 0);
                if (bytesReceived <= 0) {
                    std::cerr << "Connection closed by client." << std::endl;
                    closesocket(clientSockets[i]);
                    clientSockets.erase(clientSockets.begin() + i);
                    i--;
                }
                else {
                    buffer[bytesReceived] = '\0';
                    std::cout << "Received: " << buffer << std::endl;
                    // Echo the received message back to the client
                    send(clientSockets[i], buffer, bytesReceived, 0);
                }
            }
        }
    }

    // Close sockets and cleanup
    for (int i = 0; i < clientSockets.size(); i++) {
        // Set the receive buffer size for each client socket
        if (setsockopt(clientSockets[i], SOL_SOCKET, SO_RCVBUF, (const char*)&receiveBufferSize, sizeof(int)) == SOCKET_ERROR) {
            std::cerr << "Setsockopt for client socket failed." << std::endl;
            closesocket(clientSockets[i]);
            clientSockets.erase(clientSockets.begin() + i);
            i--; // Decrement i to account for the erased element
        }
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
