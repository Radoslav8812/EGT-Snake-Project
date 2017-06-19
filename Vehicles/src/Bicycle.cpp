#include "Bicycle.h"
#include <iostream>
#include <string>2

using namespace std;

Bicycle::Bicycle(string chain,string tyres)
{
    this -> chain = chain;
    this -> tyres = tyres;
}
///
void Bicycle:: setChain(string chain)
{
    this -> chain = chain;
}
void Bicycle:: setTyres(string tyres)
{
    this -> tyres = tyres;
}
///
string Bicycle:: getChain()
{
    return this -> chain;
}
string Bicycle:: getTyres()
{
    return this -> tyres;
}
///
void Bicycle:: print()
{
    cout <<"/ chain : "<< getChain() <<"/ tyres : "<< getTyres() << endl;
}

