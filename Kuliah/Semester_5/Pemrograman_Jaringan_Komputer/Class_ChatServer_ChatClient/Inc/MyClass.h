#include <iostream>
#include <string>
#include <cstring>

class MyData
{
public:
    int hour;
    int minute;
    int second;
    std::string message;

    // Constructor to initialize the members
    MyData(int _hour, int _minute, int _second, const std::string &_message)
        : hour(_hour), minute(_minute), second(_second), message(_message) {}

    // Default constructor
    MyData() : hour(0), minute(0), second(0), message("") {}

    void Serialize(char *buffer, int bufferSize)
    {
        // Serialize data members into a buffer
        if (bufferSize < sizeof(int) * 3)
        {
            std::cerr << "Buffer size is too small for serialization." << std::endl;
            return;
        }
        int *intBuffer = reinterpret_cast<int *>(buffer);
        intBuffer[0] = hour;
        intBuffer[1] = minute;
        intBuffer[2] = second;

        // Calculate the maximum size available for serializing the message
        int maxMessageSize = bufferSize - sizeof(int) * 3;

        if (maxMessageSize > 0)
        {
            int messageSize = static_cast<int>(message.size());
            if (messageSize <= maxMessageSize)
            {
                // Serialize the message size
                intBuffer[3] = messageSize;

                // Serialize the message if there is enough space
                memcpy(buffer + sizeof(int) * 4, message.c_str(), messageSize);
            }
        }
    }

    void Deserialize(const char *buffer, int bufferSize)
    {
        // Deserialize data members from a buffer
        if (bufferSize < sizeof(int) * 4)
        {
            std::cerr << "Buffer size is too small for deserialization." << std::endl;
            return;
        }
        const int *intBuffer = reinterpret_cast<const int *>(buffer);
        hour = intBuffer[0];
        minute = intBuffer[1];
        second = intBuffer[2];

        // Deserialize the message size
        int messageSize = intBuffer[3];

        // Calculate the maximum size available for deserializing the message
        int maxMessageSize = bufferSize - sizeof(int) * 4;

        if (maxMessageSize >= messageSize)
        {
            // Deserialize the message if available
            message.assign(buffer + sizeof(int) * 4, messageSize);
        }
        else
        {
            std::cerr << "Message size exceeds buffer capacity." << std::endl;
            message.clear();
        }
    }
};
