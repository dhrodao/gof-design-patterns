// The Singleton Pattern

#include "../include/common.h"

class Singleton
{
    Singleton() = default;
    Singleton(const Singleton& other) = delete;
    void operator=(const Singleton& other) = delete;

    std::string someProperty = "This is a singleton property";
public:
    static Singleton* getInstance()
    {
        static Singleton instance;
        return &instance;
    }

    std::string getSomeProperty() { return someProperty; }
};

int main()
{
    Singleton* s = Singleton::getInstance();
    Singleton* s1 = Singleton::getInstance();
    
    cout << s->getSomeProperty() << endl;

    return 0;
}