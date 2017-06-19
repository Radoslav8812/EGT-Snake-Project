#include "SavingsAccount.h"
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double rate) : Account (initialBalance)
{
    interestRate = (rate < 0.0) ? 0.0 : rate;
}
double SavingsAccount:: calculateInterest()
{
    return getBalance() * interestRate;
}

