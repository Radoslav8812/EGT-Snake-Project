#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <string>
using namespace std;
class Chain
{
public:
      Chain(int,int);

      void setDents(int);
      int getDents();
      void setLengh(int);
      int getLengh();

      void showInfo();

private:
    int dents;
    int lengh;
};

#endif // CHAIN_H
