#ifndef HOUSE_H
#define HOUSE_H
#include "Doors.h"
#include "Windows.h"
#include <iostream>
#include <string>

using namespace std;

class House
{
public:
    House(string,double,Doors&,Windows&);
    void setLocation(string);
    string getLocation();
    void setPrice(double);
    double getPrice();
    void setDoors(Doors&);
    Doors& getDoors();
    void setWindows(Windows&);
    Windows& getWindows();

    void print();

private:
    string location;
    double price;
    Doors Dr;
    Windows Wd;
};

#endif // HOUSE_H
