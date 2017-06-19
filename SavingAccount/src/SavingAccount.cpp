#include "SavingAccount.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


double SavingAccount:: anualInterestRate = 0.0;


void SavingAccount:: calculateMonthlyInterest()
{
   savingBalance += savingBalance * ( anualInterestRate / 12.0 );
}


void SavingAccount::modifyInterestRate( double i )
{
   anualInterestRate = ( i >= 0.0 && i <= 1.0 ) ? i : 0.03;
}


void SavingAccount::printBalance() const
{
   cout << fixed << "$" << setprecision( 2 ) << savingBalance;
}
