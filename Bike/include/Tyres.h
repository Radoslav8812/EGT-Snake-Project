#ifndef TYRES_H
#define TYRES_H
#include <iostream>
using namespace std;
class Tyres
{
public:
    Tyres(string,int,int);

    void setName(string);
    string getName();
    void setHeight(int);
    int getHeight();
    void setLengh(int);
    int getLengh();

    void showInfo();

private:
    string name;
    int height;
    int lengh;

};

#endif // TYRES_H
