#include "Face.h"

#include <iostream>

using namespace std;

Face::Face(string skin, Nose& n,Eyes& e) : noseObject(n),eyeObject(e)
{
    this -> skin = skin;

}

///
void Face:: setSkin(string)
{
    this -> skin = skin;
}
void Face:: setEyes(Eyes& e)
{
    this -> eyeObject = e;
}
void Face:: setNose(Nose& n)
{void setFuelCapacity(int FielCapacity);
        int getFuelCapacity();
    this -> noseObject = n;
}

string Face:: getSkin()
{
    return this -> skin;
}

void Face::print()
{
    cout << getSkin() << endl;
    noseObject.print();
    eyeObject.print();
}

