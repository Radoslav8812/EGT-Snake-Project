#include "Bike.h"
#include <string>
#include <iostream>
using namespace std;

Bike::Bike(string color,int price,Chain& Ch,Tyres& Ty):Ch(Ch), Ty(Ty) /// <-- inicializotor na obekti
{
    this -> color = color;
    this ->  price = price;
    this -> Ch = Ch;
    this -> Ty = Ty;
}
///
void Bike:: setColor(string color)
{
    this -> color = color;
}
void Bike:: setPrice(int price)
{
    this -> price = price;
}
void Bike:: setChain(Chain& Ch)
{
    this -> Ch = Ch;
}
void Bike:: setTyres(Tyres& Ty)
{
    this -> Ty = Ty;
}
///
string Bike:: getColor()
{
    return this -> color;
}
int Bike:: getPrice()
{
    return this -> price;
}
Chain& Bike:: getChain()
{
    return this -> Ch;
}
Tyres& Bike:: getTyres()
{
    return this -> Ty;
}
///
void Bike:: showInfo()
{
    cout << getColor() <<" "<<getPrice()<<" "<<endl;
    Ch.showInfo();
    Ty.showInfo();
}
