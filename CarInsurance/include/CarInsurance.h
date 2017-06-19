#ifndef CARINSURANCE_H
#define CARINSURANCE_H
# include <string>
#include <iostream>

using namespace std;

class CarInsurance
{
public:
    CarInsurance(int,string,string,int,string,int);
        void setCarNumber(int);
            int getCarNumber();
        void setOwnerName(string);
            string getOwnerName();
        void setInsuranceName(string);
            string getInsuranceName();
        void setMainInsurPrice(int);
            int getMainInsurPrice();
        void setCarSpec(string);
            string getCarSpec();
        void setOwnerUsage(int);
            int getOwnerUsage();

        void print();

private:
    int carNumber;
    string ownerName;
    string insuranceName;
    int MainInsurPrice;
    string carSpec;
    int ownerUsage;

    double promo;
};

#endif // CARINSURANCE_H
