#include <iostream>

class Singleton 
{
private:
    
    int data;
    inline static Singleton *instance {nullptr};
    
    //Constructor
    Singleton()
    {
        data = 0;
    }

    //Destructor
    ~Singleton(){}

public:
    //Disable cloning
    Singleton(Singleton &other) = delete;
    
    //Disable assigning
    void operator=(const Singleton &) = delete;

    //Mengambil instance class ini
    static Singleton *getInstance()
    {
        if(instance == nullptr)
        {
            std::cout<<"instance baru\n";
            instance = new Singleton;
        }
        else
        {
            std::cout<<"instance sudah ada\n";
        }
        return instance;   
    }

    int getData()
    {
        return data;
    }

    void setData(int data)
    {
        this->data = data;
    }
};

// initializing instance = NULL
//Singleton *Singleton::instance = NULL;

   
int main()
{
    Singleton *s = s->getInstance();
    std::cout << s->getData() << std::endl;
    s->setData(10);
    std::cout << s->getData() << std::endl;
    std::cout << "Address: " << &s << std::endl;

    Singleton *t = t->getInstance();
    std::cout << t->getData() << std::endl;
    t->setData(110);
    std::cout << t->getData() << std::endl;
    std::cout << "Address: " << &t << std::endl;


    return 0;
}
