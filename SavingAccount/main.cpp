///Create a SavingsAccount class. Use a static data member annualInterestRate to store the annual
///interest rate for each of the savers. Each member of the class contains a private data member
///savingsBalance indicating the amount the saver currently has on deposit. Provide member function
///calculateMonthlyInterest that calculates the monthly interest by multiplying the balance by
///annualInterestRate divided by 12; this interest should be added to savingsBalance. Provide a static
///member function modifyInterestRate that sets the static annualInterestRate to a new value. Write a
///driver program to test class SavingsAccount.
///SavingsAccount, saver1 and saver2, with balances of $2000.00 and $3000.00, respectively. Set the
///annualInterestRate to 3 percent. Then calculate the monthly interest and print the new balances
///for each of the savers. Then set the annualInterestRate to 4 percent, calculate the nextmonth's interest and print
///the new balances for each of the savers.
#include <string>
#include <iostream>
#include "SavingAccount.h"
#include <iomanip>
using namespace std;

int main()
{
   SavingAccount saver1( 2000.0 );
   SavingAccount saver2( 3000.0 );

   SavingAccount::modifyInterestRate( .03 );

   cout << "Initial balances:\nSaver 1: ";
   saver1.printBalance();
   cout << "\tSaver 2: ";
   saver2.printBalance();

   saver1.calculateMonthlyInterest();
   saver2.calculateMonthlyInterest();

   cout << "\n\nBalances after 1 month's interest applied at .03:\n"
      << "Saver 1: ";
   saver1.printBalance();
   cout << "\tSaver 2: ";
   saver2.printBalance();

   SavingAccount::modifyInterestRate( .04 );
   saver1.calculateMonthlyInterest();
   saver2.calculateMonthlyInterest();

   cout << "\n\nBalances after 1 month's interest applied at .04:\n"
      << "Saver 1: ";
   saver1.printBalance();
   cout << "\tSaver 2: ";
   saver2.printBalance();
   cout << endl;
   return 0;
}
