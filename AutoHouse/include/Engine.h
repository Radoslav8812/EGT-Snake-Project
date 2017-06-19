#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include <iostream>

class Engine
{
public:
        Engine(int,string);
        void setFuelCapacity(int FielCapacity);
        int getFuelCapacity();
        void setFuelType(string FuelType);
        string getFuelCapacity();
private:
    int FuelCapacity;
    string FuelType;
};

#endif // ENGINE_H
