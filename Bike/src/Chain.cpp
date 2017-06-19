#include "Chain.h"
#include <iostream>
#include <string>
using namespace std;

Chain::Chain(int Dents,int Lengh)
{
    this -> dents = Dents;
    this -> lengh = Lengh;
}
void Chain:: setDents(int Dents)
{
    this -> dents = Dents;
}
void Chain:: setLengh(int Lengh)
{
    this -> lengh = Lengh;
}
///
int Chain:: getDents()
{
    return this -> dents;
}
int Chain:: getLengh()
{
    return this -> lengh;
}
void Chain:: showInfo()
{
    cout << getDents() <<" " <<getLengh() << endl;
}
