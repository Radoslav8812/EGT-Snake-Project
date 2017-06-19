#ifndef ROADBIKES_H
#define ROADBIKES_H
#include <iostream>
using namespace std;

class RoadBikes
{
public:
        RoadBikes(string,string,int,int,float);

        void print();

        void setName(string name);
        string getName();
        void setModel(string model);
        string getModel();
        void setPrice(int price);
        int getPrice();
        void setYear(int year);
        int getYear();
        void setWeight(float weight);
        float getWeight();

private:
    string name;
    string model;
    int price;
    int year;
    float weight;
};

#endif // ROADBIKES_H

