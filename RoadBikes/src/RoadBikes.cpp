#include "RoadBikes.h"
#include <string>
RoadBikes::RoadBikes(string name, string model, int price, int year, float weight)
{
    this -> name = name;
    this -> model = model;
    this -> price = price;
    this -> year = year;
    this -> weight = weight;
}
void RoadBikes::print(){

    cout << getName() <<" " <<getModel() <<" "<<getPrice() <<" " <<getYear()<< " " << getWeight()<< endl;
}


void RoadBikes::setName(string name){
    this -> name = name;
}
void RoadBikes::setModel(string model){
    this -> model = model;
}
void RoadBikes::setPrice(int price){
    this -> price = price;
}
void RoadBikes::setYear(int year){
    this -> year = year;
}
void RoadBikes::setWeight(float weight){
    this -> weight = weight;
}


string RoadBikes:: getName(){
    return this -> name;
}
string RoadBikes:: getModel(){
    return this -> model;
}
int RoadBikes::getPrice(){
    return this -> price;
}
int RoadBikes::getYear(){
    return this -> year;
}
float RoadBikes::getWeight(){
    return this -> weight;
}







