// The Factory Method Pattern

#include "../include/common.h"

// Objects to fabricate

struct AbstractObjectA
{
    AbstractObjectA(){ cout << "Creating AbstractObjectA" << endl; };
    virtual ~AbstractObjectA() = default;
};

struct ConcreteObjectA : AbstractObjectA
{
    ConcreteObjectA(){ cout << "Creating ConcreteObjectA" << endl; };
    virtual ~ConcreteObjectA() = default;
};

struct AbstractObjectB
{
    AbstractObjectB(){ cout << "Creating AbstractObjectB" << endl; };
    virtual ~AbstractObjectB() = default;
};

struct ConcreteObjectB : AbstractObjectB
{
    ConcreteObjectB(){ cout << "Creating ConcreteObjectB" << endl; };
    virtual ~ConcreteObjectB() = default;
};

struct Creator
{
    Creator(){ cout << "Creating Creator" << endl; };

    // Factory Methods
    virtual AbstractObjectA* createObjectA() = 0;
    virtual AbstractObjectB* createObjectB() = 0;
    // ...
};

struct ConcreteCreator : Creator
{
    ConcreteCreator(){ cout << "Creating ConcreteCreator" << endl; };

    AbstractObjectA* createObjectA()
    {
        return new ConcreteObjectA;
    }

    AbstractObjectB* createObjectB()
    {
        return new ConcreteObjectB;
    }

    // Other Class Methods
    // ...
};

int main()
{
    ConcreteCreator concreteCreator;

    AbstractObjectA* a = concreteCreator.createObjectA();
    AbstractObjectB* b = concreteCreator.createObjectB();

    delete a;
    delete b;

    return 0;
}