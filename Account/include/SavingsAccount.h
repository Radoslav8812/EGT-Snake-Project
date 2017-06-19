#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

class SavingsAccount : public Account
{
public:
    SavingsAccount(double, double); /// <- balance i interest rate !

       double calculateInterest(); /// opredelq duljimite lihvi

private:
    double interestRate;
};

#endif // SAVINGSACCOUNT_H
