#include "Tyres.h"

Tyres::Tyres(string name,int height ,int lengh)
{
    this -> name = name;
    this -> height = height;
    this -> lengh = lengh;
}
///
void Tyres:: setName(string name)
{
    this -> name = name;
}
void Tyres:: setHeight(int height)
{
    this -> height = height;
}
void Tyres:: setLengh(int lengh)
{
    this -> lengh = lengh;
}
///
string Tyres:: getName()
{
    return this -> name;
}
int Tyres:: getHeight()
{
    return this -> height;
}
int Tyres:: getLengh()
{
    return this -> lengh;
}
void Tyres:: showInfo()
{
    cout << getName() <<" "<< getHeight() <<" "<< getLengh() << endl;
}
