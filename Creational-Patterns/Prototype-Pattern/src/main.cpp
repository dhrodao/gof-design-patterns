// The Prototype Pattern

#include "../include/common.h"

struct CarEnginePrototype
{
    int hp = 100;
    CarEnginePrototype(int auxHp): hp(auxHp){}
    virtual ~CarEnginePrototype() = default;

    CarEnginePrototype(const CarEnginePrototype& other)
    {
        this->hp = other.hp;
    }

    friend std::ostream& operator<< (std::ostream& stream, const CarEnginePrototype& engine)
    {
        stream << "Engine power of " << engine.hp << " hp";

        return stream;
    }

    virtual CarEnginePrototype* Clone() = 0;
};

struct SportEnginePrototype : CarEnginePrototype
{
    SportEnginePrototype(): CarEnginePrototype(450){}

    CarEnginePrototype* Clone()
    {
        return new SportEnginePrototype(*this);
    }
};

struct DriftEnginePrototype : CarEnginePrototype
{
    DriftEnginePrototype(): CarEnginePrototype(250){}

    CarEnginePrototype* Clone()
    {
        return new DriftEnginePrototype(*this);
    }
};

class PrototypeManager
{
public:
    static void init()
    {
        prototypes[0] = new SportEnginePrototype;
        prototypes[1] = new DriftEnginePrototype;
    }

    static void remove()
    {
        delete prototypes[0];
        delete prototypes[1];
    }

    static CarEnginePrototype* make(int index)
    {
        if(index > 1 || index < 0)
            return nullptr;

        return prototypes[index]->Clone();
    }
private:
    static std::array<CarEnginePrototype*, 2> prototypes;
};

std::array<CarEnginePrototype*, 2> PrototypeManager::prototypes;

int main()
{
    PrototypeManager::init();

    CarEnginePrototype* sportsEngine = PrototypeManager::make(0);
    CarEnginePrototype* driftEngine = PrototypeManager::make(1);

    PrototypeManager::remove();

    cout << *sportsEngine << endl;
    cout << *driftEngine << endl;

    delete sportsEngine;
    delete driftEngine;

    return 0;
}