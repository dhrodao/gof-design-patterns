// The Bridge Pattern

#include "../include/common.h"

//          Client
//             | uses
//             v       v Bridge v
//        Abstraction ------------> Implementor
//        /         \    contains   /          \ 
//  ConcreteAbsA ConcreteAbsB     ConcreteImplA ConcreteImplB    

/*
 * The Implementor class is and abstract class which defines
 * th interface for the implementation classes
 */
struct Implementor
{
    virtual ~Implementor() = default;

    virtual void action() = 0;
};

struct ConcreteImplA : public Implementor
{
    void action() override
    {
        cout << "concrete action A" << endl;
    }
};

struct ConcreteImplB : public Implementor
{
    void action() override
    {
        cout << "concrete action B" << endl;
    }
};


/*
 * The Abstraction class defines the interface (operations)
 * for the Concrete Abstractions. It will point to an instance
 * of Implementor.
 */
struct Abstraction
{
    Abstraction(Implementor* auxImpl): _impl(auxImpl){}
    virtual ~Abstraction() = default;

    virtual void operation() = 0;
protected:
    Implementor* _impl;
};

struct RefinedAbstraction : public Abstraction
{
    RefinedAbstraction(Implementor* auxImpl): Abstraction(auxImpl){}

    void operation() override
    {
        _impl->action();
    }
};

int main()
{
    ConcreteImplA implA;
    ConcreteImplB implB;

    RefinedAbstraction absA(&implA);
    RefinedAbstraction absB(&implB);

    absA.operation();
    absB.operation();

    return 0;
}