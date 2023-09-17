#include <iostream>
#include <winsock2.h>
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

    // Send and receive struct data
    MyStruct dataToSend;

    while (true)
    {
        std::string message;

        // Prompt the user for input
        std::cout << "Enter a message (or 'exit' to quit): ";
        std::getline(std::cin, message);
        // std::string message = "anjing"; // Replace with the message you want to send
        
        if (message == "exit")
        {
            break;
        }

        // Get the current time using std::chrono
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        struct std::tm *timeInfo = std::localtime(&currentTime);

        // Populate MyStruct with the current time and message
        dataToSend.hour = timeInfo->tm_hour;
        dataToSend.minute = timeInfo->tm_min;
        dataToSend.second = timeInfo->tm_sec;
        strncpy(dataToSend.message, message.c_str(), sizeof(dataToSend.message) - 1);
        dataToSend.message[sizeof(dataToSend.message) - 1] = '\0';

        // Send the MyStruct data as binary
        int bytesSent = send(clientSocket, reinterpret_cast<const char *>(&dataToSend), sizeof(dataToSend), 0);
        if (bytesSent == SOCKET_ERROR)
        {
            std::cerr << "Send failed." << std::endl;
            break;
        }

        // Receive the struct data as binary
        MyStruct receivedData;
        int bytesReceived = recv(clientSocket, reinterpret_cast<char *>(&receivedData), sizeof(receivedData), 0);
        if (bytesReceived <= 0)
        {
            std::cerr << "Connection closed by the server." << std::endl;
            break;
        }

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
