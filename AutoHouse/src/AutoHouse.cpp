#include "AutoHouse.h"
#include <string>
#include <iostream>

using namespace std;

AutoHouse::AutoHouse(string Brand, int ID)
{
    this-> Brand = Brand;
    this-> ID = ID;
}

///
void AutoHouse:: setBrand(string Brand)
{
    this ->  Brand = Brand;
}
void AutoHouse:: setID(int ID)
{
    this ->  ID = ID;
}
///
string AutoHouse:: getBrand()
{
    return this -> Brand;
}
int AutoHouse:: getID()
{
    return this -> ID;
}
///
void AutoHouse::showinfo()
{
    cout << getBrand() <<" "<< getID()<<" " << endl;
}
