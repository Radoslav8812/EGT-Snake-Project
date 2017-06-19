#include "Motocycle.h"
#include <iostream>
#include <string>
#include "Bicycle.h"

using namespace std;

Motocycle::Motocycle(string chain,string tyres,string engine):Bicycle(chain,tyres)///<- inicializator na klasa!
{
    this -> engine = engine;
}
///
void Motocycle:: setEngine(string engine)
{
    this -> engine = engine;
}
///
string Motocycle:: getEngine()
{
    return this -> engine;
}
///
void Motocycle:: print()
{
    cout<<"/ Engine : " << getEngine() << " ";
    Bicycle::print();
}
