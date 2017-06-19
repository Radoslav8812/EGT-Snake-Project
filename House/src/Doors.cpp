#include "Doors.h"
#include <iostream>
#include <string>
Doors::Doors(string color,int price)
{
    this -> color = color;
    this -> price = price;
}
///
void Doors:: setColor(string color)
{
    this -> color = color;
}
void Doors:: setPrice(int price)
{
    this -> price = price;
}
///
string Doors:: getColor()
{
    return this -> color;
}
int Doors:: getPrice()
{
    return this -> price;
}
///
void Doors:: print()
{
    cout << getColor() <<" "<< getPrice() << endl;
}
