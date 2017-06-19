#include "Engine.h"

Engine::Engine(int FuelCapacity, string FuelType)
{
    this -> FuelCapacity = FuelCapacity;
    this -> FuelType = FuelType;
}

Engine::~Engine()
{
    //dtor
}
void Engine::setFuelCapacity(int FuelCapacity)
{
    this -> FuelCapacity = FuelCapacity;
}
void Engine::setFuelType(string FuelType)
{
    this -> FuelType = FuelType;
}
int Engine::getFuelCapacity()
{
    return this -> FuelCapacity;
}
string Engine::getFuelType()
{
    return this -> FuelType;
}
