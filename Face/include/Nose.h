#ifndef NOSE_H
#define NOSE_H

#include "Eyes.h"
#include "Nose.h"
class Nose
{
public:
    Nose(string,int);

    void setSizze(string);
    void setHoles(int);

    string getSizze();
    int getHoles();

    void print();

private:
    string sizze;
    int holes;
};

#endif // NOSE_H
