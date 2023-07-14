// The Abstract Factory Pattern

#include "../include/common.h"

// Objects to fabricate

struct AbstractObject1
{
    AbstractObject1(){ cout << "Creating AbstractObject1" << endl; };
    virtual ~AbstractObject1() = default;
};

struct ConcreteObject1A : AbstractObject1
{
    ConcreteObject1A(){ cout << "Creating ConcreteObject1A" << endl; };
    virtual ~ConcreteObject1A() = default;
};

struct ConcreteObject1B : AbstractObject1
{
    ConcreteObject1B(){ cout << "Creating ConcreteObject1B" << endl; };
    virtual ~ConcreteObject1B() = default;
};

struct AbstractObject2
{
    AbstractObject2(){ cout << "Creating AbstractObject2" << endl; };
    virtual ~AbstractObject2() = default;
};

struct ConcreteObject2A : AbstractObject2
{
    ConcreteObject2A(){ cout << "Creating ConcreteObject2A" << endl; };
    virtual ~ConcreteObject2A() = default;
};

struct ConcreteObject2B : AbstractObject2
{
    ConcreteObject2B(){ cout << "Creating ConcreteObject2B" << endl; };
    virtual ~ConcreteObject2B() = default;
};

// Abstract factory defines pure virtual methods only
struct AbstractFactory
{
    virtual AbstractObject1* createObject1() = 0;
    virtual AbstractObject2* createObject2() = 0;
};

// The concrete factories decide which type of object to create
struct ConcreteFactoryA
{
    ConcreteFactoryA(){ cout << "Creating ConcreteFactoryA" << endl; };

    AbstractObject1* createObject1()
    {
        return new ConcreteObject1A();
    }

    AbstractObject2* createObject2()
    {
        return new ConcreteObject2A();
    }
};

struct ConcreteFactoryB
{
    ConcreteFactoryB(){ cout << "Creating ConcreteFactoryB" << endl; };

    AbstractObject1* createObject1()
    {   
        return new ConcreteObject1B();
    }

    AbstractObject2* createObject2()
    {
        return new ConcreteObject2B();
    }
};

int main()
{
    ConcreteFactoryA cfa;
    AbstractObject1* ao1 = cfa.createObject1();
    AbstractObject2* ao2 = cfa.createObject2();

    cout << endl;

    ConcreteFactoryB cfb;
    AbstractObject1* bo1 = cfb.createObject1(); 
    AbstractObject2* bo2 = cfb.createObject2();

    delete ao1;
    delete ao2;
    delete bo1;
    delete bo2;

    return 0;
}