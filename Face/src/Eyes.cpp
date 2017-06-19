#include "Eyes.h"
#include <iostream>
#include <string>

using namespace std;
Eyes::Eyes(string color)
{
    this -> color = color;
}

void Eyes:: setColor(string color)
{
    this -> color = color;
}
string Eyes:: getColor()
{
    return this -> color;
}
void Eyes::print()
{
    cout << getColor() << endl;
}
