// The Adapter Pattern

#include "../include/common.h"

struct Client
{
    virtual void request() = 0;

    // ...
};

struct Adaptee
{
    void specificRequest()
    {
        cout << "specific request" << endl;
    }

    // ...
};

/*
 * The Class Adapter
 * On this approach the adapter inherits from both interfaces
 * the Client's and the Adaptee's. It inherits the interface from
 * the client and the Adaptee's implementation.
 * It adapts the Adaptee to the Client's interface.
 */

struct ClassAdapter : public Client, private Adaptee
{
    void request() override
    {
        Adaptee::specificRequest();
    }

    // ...
};

/*
 * The Object Adapter
 * On the other hand, this approach only inherits the Client's interface.
 * And the Adaptee gets injected into the Adapter object.
 * And this way the Adaptee is adapted to the Client's interface
 */

struct ObjectAdapter : public Client
{
    ObjectAdapter(Adaptee* auxAdaptee): adaptee(auxAdaptee){}

    // Here, simply the request is forwarded to the Adaptee object
    void request() override
    {
        adaptee->specificRequest();
    }

    // ...
private:
    Adaptee* adaptee;
};

int main()
{
    ClassAdapter ca;
    ca.request();

    Adaptee adaptee;
    ObjectAdapter oa(&adaptee);
    oa.request();

    return 0;
}