#include "Nose.h"
#include <iostream>

using namespace std;
Nose::Nose(string sizze,int holes)
{
    this -> sizze = sizze;
    this -> holes = holes;
}


void Nose:: setSizze(string)
{
    this -> sizze = sizze;
}
void Nose:: setHoles(int)
{
    this -> holes = holes;
}
string Nose:: getSizze()
{
    return this -> sizze;
}
int Nose:: getHoles()
{
    return this -> holes;
}
void Nose::print()
{
    cout << getSizze() << endl;
    cout << getHoles() << endl;
}
