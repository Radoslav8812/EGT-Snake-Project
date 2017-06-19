#include "House.h"
#include <iostream>
#include <string>

using namespace std;

House::House(string location,double price,Doors& Dr,Windows& Wd): Dr(Dr),Wd(Wd)
{
    this -> location = location;
    this -> price = price;
    this -> Dr = Dr;
    this -> Wd = Wd;
}
///
void House:: setLocation(string location)
{
    this -> location = location;
}
void House:: setPrice(double price)
{
    this -> price = price;
}
void House:: setDoors(Doors& Dr)
{
    this -> Dr = Dr;
}
void House:: setWindows(Windows& Wd)
{
    this -> Wd = Wd;
}
///
string House:: getLocation()
{
    return this -> location;
}
double House:: getPrice()
{
    return this -> price;
}
Doors& House:: getDoors()
{
    return this -> Dr;
}
Windows& House:: getWindows()
{
    return this -> Wd;
}
///
void House:: print()
{
    cout << getLocation() <<" " <<getPrice()<< endl;
    Dr.print();
    Wd.print();
}
