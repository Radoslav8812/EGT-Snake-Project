#include "CarInsurance.h"
#include <string>
#include <iostream>

using namespace std;

CarInsurance::CarInsurance(int carNumber,string ownerName,string insuranceName,int MainInsurPrice,string carSpec,int ownerUsage)
{
    this -> carNumber = carNumber;
    this -> ownerName = ownerName;
    this -> insuranceName = insuranceName;
    this -> MainInsurPrice = MainInsurPrice;
    this -> carSpec = carSpec;
    this -> ownerUsage = ownerUsage;
}
///
void CarInsurance:: setCarNumber(int carNumber)
{
    this -> carNumber = carNumber;
}
int CarInsurance:: getCarNumber()
{
    return this -> carNumber;
}
void CarInsurance:: setOwnerName(string ownerName)
{
    this -> ownerName = ownerName;
}
string CarInsurance:: getOwnerName()
{
    return this -> ownerName;
}
void CarInsurance:: setInsuranceName(string insuranceName)
{
    this -> insuranceName = insuranceName;
}
string CarInsurance:: getInsuranceName()
{
    return this -> insuranceName;
}
void CarInsurance:: setCarSpec(string carSpec)
{
    this -> carSpec = carSpec;
}
string CarInsurance:: getCarSpec()
{
    return this -> carSpec;
}
void CarInsurance:: setMainInsurPrice(int MainInsurPrice)
{
    if(carSpec == "New" && ownerUsage > 6){
        double promo = MainInsurPrice * 0.07;
            this-> MainInsurPrice = MainInsurPrice - promo;
    }
    if(carSpec == "Middle" && ownerUsage < 2){
            double promo = MainInsurPrice * 0.03;
                this -> MainInsurPrice = MainInsurPrice - promo;
        }else{
            this -> MainInsurPrice = MainInsurPrice;
        }
}
void CarInsurance:: print()
{
    cout <<" number : " << getCarNumber() << endl;
    cout <<" owner name : " << getOwnerName() << endl;
    cout <<" insurance name : " << getInsuranceName() << endl;
    cout <<" main insurance price " << getMainInsurPrice() << endl;
    cout <<" car spec : " << getCarSpec() << endl;
    cout <<" owner usage : " << getOwnerUsage() << endl;
}
int CarInsurance:: getMainInsurPrice()
{
    return this -> MainInsurPrice;
}
void CarInsurance:: setOwnerUsage(int ownerUsage)
{
    this -> ownerUsage = ownerUsage;
}
int CarInsurance:: getOwnerUsage()
{
    return this -> ownerUsage;
}


