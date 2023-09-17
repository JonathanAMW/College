#include <iostream>
#include <winsock2.h>
#include <vector>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

#include "MyStruct.h"

int main()
{
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }

    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
    {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    // Adjust the server's maximum TCP window size
    int receiveBufferSize = 1024 * 1024; // Set the receive buffer size to 1 MB (for example)

    // Set the receive buffer size for the server socket
    if (setsockopt(serverSocket, SOL_SOCKET, SO_RCVBUF, (const char *)&receiveBufferSize, sizeof(int)) == SOCKET_ERROR)
    {
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

    if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Listen failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 12345..." << std::endl;

    std::vector<SOCKET> clientSockets;

    while (true)
    {
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(serverSocket, &readSet);

        for (SOCKET client : clientSockets)
        {
            FD_SET(client, &readSet);
        }

        // Use select to wait for activity on any socket
        int selectResult = select(0, &readSet, nullptr, nullptr, nullptr);
        if (selectResult == SOCKET_ERROR)
        {
            std::cerr << "Select failed." << std::endl;
            break;
        }

        if (FD_ISSET(serverSocket, &readSet))
        {
            // New client connection
            SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket == INVALID_SOCKET)
            {
                std::cerr << "Accept failed." << std::endl;
            }
            else
            {
                std::cout << "Client " << clientSockets.size() << " is connected." << std::endl;
                clientSockets.push_back(clientSocket);
            }
        }

        // Handle client disconnections and data reception
        for (int i = 0; i < clientSockets.size(); i++)
        {
            if (FD_ISSET(clientSockets[i], &readSet))
            {
                // Receive and process data from the client
                MyStruct receivedData;
                int bytesReceived = recv(clientSockets[i], reinterpret_cast<char *>(&receivedData), sizeof(MyStruct), 0);

                if (bytesReceived <= 0)
                {
                    std::cerr << "Connection closed by the client." << std::endl;
                    closesocket(clientSockets[i]);
                    clientSockets.erase(clientSockets.begin() + i);
                    continue; // Skip the rest of the loop for this client
                }

                // Print received data
                std::cout << "Received struct data:" << std::endl;
                std::cout << "Hour: " << receivedData.hour << std::endl;
                std::cout << "Minute: " << receivedData.minute << std::endl;
                std::cout << "Second: " << receivedData.second << std::endl;
                std::cout << "Message: " << receivedData.message << std::endl;

                // Get the current time using std::chrono
                auto now = std::chrono::system_clock::now();
                std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
                struct std::tm *timeInfo = std::localtime(&currentTime);

                // Populate MyStruct with the current time and the received message
                MyStruct newDataToSend;
                newDataToSend.hour = timeInfo->tm_hour;
                newDataToSend.minute = timeInfo->tm_min;
                newDataToSend.second = timeInfo->tm_sec;
                strncpy(newDataToSend.message, receivedData.message, sizeof(newDataToSend.message) - 1);
                newDataToSend.message[sizeof(newDataToSend.message) - 1] = '\0';

                // Echo the MyStruct data back to the client
                send(clientSockets[i], reinterpret_cast<char *>(&newDataToSend), sizeof(MyStruct), 0);
            }
        }
    }

    // Close sockets and cleanup
    for (SOCKET clientSocket : clientSockets)
    {
        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
