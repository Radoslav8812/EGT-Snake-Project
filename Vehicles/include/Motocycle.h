#ifndef MOTOCYCLE_H
#define MOTOCYCLE_H
#include "Bicycle.h"
#include <iostream>
#include <string>

using namespace std;

class Motocycle:public Bicycle
{
public:
    Motocycle(string,string,string);

        void setEngine(string);
            string getEngine();

        void print();

private:
    string engine;
};

#endif // MOTOCYCLE_H
