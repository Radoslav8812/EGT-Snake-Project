#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class CheckingAccount : public Account
{
public:
    CheckingAccount(double, double);

        void credit(double); /// predefinirane na kredit funkciqta
        bool debit(double); /// -------||------


private:
    double transactionFee; /// taksa za tranzakciq
    void chargeFee(); /// spomagatelna funkciq za taksata (fee)
};

#endif // CHECKINGACCOUNT_H
