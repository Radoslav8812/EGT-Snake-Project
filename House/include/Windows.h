#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
#include <string>

using namespace std;

class Windows
{
public:
    Windows(string,float);
    void setColor(string);
    string getColor();
    void setPrice(float);
    float getPrice();

    void print();

private:
    string color;
    float price;
};

#endif // WINDOWS_H
