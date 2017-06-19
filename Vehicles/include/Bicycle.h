#ifndef BICYCLE_H
#define BICYCLE_H
#include <string>
#include <iostream>

using namespace std;

class Bicycle
{
public:
    Bicycle(string,string);

    void setChain(string);
        string getChain();
    void setTyres(string);
        string getTyres();

    void print();

private:
    string chain;
    string tyres;
};

#endif // BICYCLE_H
