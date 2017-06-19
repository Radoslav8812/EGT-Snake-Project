#include "Account.h"

Account::Account(double initialBalance)
{
    if ( initialBalance >= 0.0)
        initialBalance = balance;
    else
    {
        cout << " Balance can not be negative" << endl;
        balance = 0.0;
    }
}
void Account:: credit(double amount)
{
    balance = balance + amount; /// dobavq na smetkata( balance ).
}
bool Account:: debit(double amount)
{
    if (amount > balance)
    {
        cout << " debit amount exceeded account balance " << endl;
        return false;
    }
    else
    {
        balance = balance - amount;
        return true;
    }
} /// krai na funkciq " debit " .
void Account:: setBalance(double newBalance)
{
    balance = newBalance;
}
double Account:: getBalance()
{
    return balance;
}

