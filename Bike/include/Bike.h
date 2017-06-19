#ifndef BIKE_H
#define BIKE_H
#include "Chain.h"
#include "Tyres.h"
#include <iostream>
#include <string>
using namespace std;

class Bike
{
public:
    Bike(string,int,Chain&,Tyres&);///priema adres Ch ,Ty;

    void setColor(string);
        string getColor();
    void setPrice(int);
        int getPrice();
    void setChain(Chain&);
        Chain& getChain();
    void setTyres(Tyres&);
        Tyres& getTyres();

    void showInfo();


private:
    string color;
    int price;
    Chain Ch;
    Tyres Ty;
};

#endif // BIKE_H
