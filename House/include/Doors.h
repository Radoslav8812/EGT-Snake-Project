#ifndef DOORS_H
#define DOORS_H
#include <iostream>
#include <string>

using namespace std;

class Doors
{
public:
    Doors(string,int);
    void setColor(string);
    string getColor();
    void setPrice(int);
    int getPrice();

    void print();

private:
    string color;
    int price;
};

#endif // DOORS_H
