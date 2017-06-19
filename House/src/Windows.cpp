#include "Windows.h"
#include <iostream>
#include <string>

using namespace std;

Windows::Windows(string color,float price)
{
    this -> color = color;
    this -> price = price;
}
///
void Windows:: setColor(string color)
{
    this -> color = color;
}
void Windows:: setPrice(float price)
{
    this -> price = price;
}
///
string Windows:: getColor()
{
    return this -> color;
}
float Windows:: getPrice()
{
    return this -> price;
}
///
void Windows:: print()
{
    cout << getColor() <<" "<< getPrice() << endl;
}

