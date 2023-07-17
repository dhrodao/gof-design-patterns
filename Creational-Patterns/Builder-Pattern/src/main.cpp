// The Builder Pattern

#include "../include/common.h"

struct CarWheels
{
    int grip = 5;
    CarWheels(int auxGrip): grip(auxGrip){}
};

struct SportWheels : CarWheels
{
    SportWheels(): CarWheels(10){}
};

struct DriftWheels : CarWheels
{
    DriftWheels(): CarWheels(2){}
};

struct CarEngine
{
    int hp = 100;
    CarEngine(int auxHp): hp(auxHp){}
};

struct SportEngine : CarEngine
{
    SportEngine(): CarEngine(450){}
};

struct DriftEngine : CarEngine
{
    DriftEngine(): CarEngine(250){}
};

struct Car
{
    CarWheels *wheels = nullptr;
    CarEngine *engine = nullptr;

    virtual ~Car()
    {
        if(wheels) delete wheels;
        if(engine) delete engine;
    }

    friend std::ostream& operator<< (std::ostream& stream, const Car& car)
    {
        stream << "Car with engine power of " << car.engine->hp << " hp and "
               << car.wheels->grip << " wheel grip";

        return stream;
    }
};

struct CarBuilder
{
    Car *car = nullptr;

    virtual ~CarBuilder() 
    {
        if(car) delete car;
    }

    virtual void buildCar() = 0;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
};

struct SportsCarBuilder : CarBuilder
{
    void buildCar() override
    {
        car = new Car;
    }
    
    void buildEngine() override
    {
        car->engine = new SportEngine;
    }
    
    void buildWheels() override
    {
        car->wheels = new SportWheels;
    }
};

struct DriftCarBuilder : CarBuilder
{
    void buildCar() override
    {
        car = new Car;
    }
    
    void buildEngine() override
    {
        car->engine = new DriftEngine;
    }
    
    void buildWheels() override
    {
        car->wheels = new DriftWheels;
    }
};

int main()
{
    SportsCarBuilder sportsCar;
    sportsCar.buildCar();
    sportsCar.buildEngine();
    sportsCar.buildWheels();

    DriftCarBuilder driftCar;
    driftCar.buildCar();
    driftCar.buildEngine();
    driftCar.buildWheels();

    cout << "SportsCar: " << *sportsCar.car << std::endl;
    cout << "DriftCar: " << *driftCar.car << std::endl;

    return 0;
}