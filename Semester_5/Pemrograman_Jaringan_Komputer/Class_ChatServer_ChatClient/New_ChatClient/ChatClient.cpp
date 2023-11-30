#include <iostream>
#include <winsock2.h>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

#include "MyClass.h"

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
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    // Set up the server address and port to connect to
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to the server's IP address
    serverAddr.sin_port = htons(12345);                  // Use the same port as the server

    // Connect to the server
    if (connect(clientSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Failed to connect to the server." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to the server." << std::endl;

    while (true)
    {
        std::string message;

        // Prompt the user for input
        std::cout << "Enter a message (or 'exit' to quit): ";
        std::getline(std::cin, message);

        if (message == "exit")
        {
            break;
        }

        // Get the current time using std::chrono
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        struct std::tm *timeInfo = std::localtime(&currentTime);

        // Create a MyData object
        MyData dataToSend(timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, message);

        // Serialize the MyData object
        int bufferSize = sizeof(MyData) + message.size() + 1;
        char buffer[bufferSize];
        dataToSend.Serialize(buffer, bufferSize);

        // Send the serialized data
        int bytesSent = send(clientSocket, buffer, bufferSize, 0);
        if (bytesSent == SOCKET_ERROR)
        {
            std::cerr << "Send failed." << std::endl;
            break;
        }

        // Receive the struct data as binary
        MyData receivedData;
        int bytesReceived = recv(clientSocket, buffer, bufferSize, 0);
        if (bytesReceived <= 0)
        {
            std::cerr << "Connection closed by the server." << std::endl;
            break;
        }

        // Deserialize the received data
        receivedData.Deserialize(buffer, bytesReceived);

        // Process and print the received struct data
        std::cout << "Server has accepted the data:" << std::endl;
        std::cout << "Hour: " << receivedData.hour << std::endl;
        std::cout << "Minute: " << receivedData.minute << std::endl;
        std::cout << "Second: " << receivedData.second << std::endl;
        std::cout << "With the sent message: " << receivedData.message << std::endl;
    }

    // Close the socket and cleanup
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
