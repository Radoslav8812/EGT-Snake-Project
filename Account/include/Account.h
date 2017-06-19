#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
    Account(double);

        void credit(double); ///dobavq kolichestvo kum balansa na potrebitelq.
        bool debit(double); ///izvajda kolichestvo ot potrebitelskiq balans.

        void setBalance(double);
            double getBalance();

private:
    double balance;
};

#endif // ACCOUNT_H
