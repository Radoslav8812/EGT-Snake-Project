#ifndef AUTOHOUSE_H
#define AUTOHOUSE_H
#include <string>
#include <iostream>

using namespace std;

class AutoHouse
{
public:
    AutoHouse(string, int);
        void setBrand(string);
            string getBrand();
        void setID(int);
            int getID();

        void showinfo();

private:
    string Brand;
    int ID;
};

#endif // AUTOHOUSE_H
