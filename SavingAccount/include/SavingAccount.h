#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class SavingAccount
{
public:
        SavingAccount(double b)
    {
      savingBalance = ( b >= 0.0 ? b : 0.0 );
    } /// end SavingsAccount constructor


        void calculateMonthlyInterest();
        static void modifyInterestRate( double );
        void printBalance()const;

private:
    double savingBalance;
    static double anualInterestRate;
};

#endif
