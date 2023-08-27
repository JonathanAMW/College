#include <iostream>

class Database
{
private:
    static Database *instance;
    Database()
    {
        std::cout << "Construct the Database\n";
    };

public:
    static Database *getInstance()
    {
        if(instance == NULL)
        {
            instance = new Database();
        }
        return instance;
    }

};
