#ifndef CARS_H
#define CARS_H
#include "Engine.h"

class Cars
{
    public:
        Cars(string,string,int,Engine& eng);

        void setBrand(string Brand);
        string getBrand();
        void setModel(string Model);
        string getModel();
        void setYear(int Year);
        int getYear();



private:
        string Brand;
        string Model;
        int Year;
        Engine eng;
};

#endif // CARS_H
