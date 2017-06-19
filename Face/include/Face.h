#ifndef FACE_H
#define FACE_H

#include <iostream>

#include "Nose.h"

#include "Eyes.h"
using namespace std;

class Face
{
public:
    Face(string,Nose&,Eyes&);
        void setSkin(string);
        string getSkin();
        void setNose(Nose&);
        Nose& getNose();
        void setEyes(Eyes&);
        Eyes& getEyes();

        void print();

private:
        string skin;
        Eyes eyeObject;
        Nose noseObject;

};

#endif // FACE_H
