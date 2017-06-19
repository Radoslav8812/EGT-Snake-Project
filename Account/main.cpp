#include <iostream>
#include <iomanip>
#include <string>
#include <Account.h>
#include <SavingsAccount.h>
#include <CheckingAccount.h>

using namespace std;

int main()
{
    Account account1(50.00);
    SavingsAccount account2(25.00, 0.3);
    CheckingAccount account3(80.00, 1.0);

    cout << fixed << setprecision(2);

    ///initial balance !
    cout << "Account balance :" << account1.getBalance() << endl;
    cout << "Account balance :" << account2.getBalance() << endl;
    cout << "Account balance :" << account3.getBalance() << endl;

    cout << "Debit 25.00$ from Account1" << endl;
    account1.debit(25.00);
    cout << "Debit 30.00 from Account2" << endl;
    account2.debit(30.00);
    cout << "Debit 40.00 from Account3" << endl;
    account3.debit(40.00);

    cout << "Account balance :" << account1.getBalance() << endl;
    cout << "Account balance :" << account2.getBalance() << endl;
    cout << "Account balance :" << account3.getBalance() << endl;

    cout << "Debit 40.00$ from Account1" << endl;
    account1.credit(40.00);
    cout << "Debit 65.00 from Account2" << endl;
    account2.credit(65.00);
    cout << "Debit 20.00 from Account3" << endl;
    account3.credit(20.00);

    cout << "Account balance :" << account1.getBalance() << endl;
    cout << "Account balance :" << account2.getBalance() << endl;
    cout << "Account balance :" << account3.getBalance() << endl;

    double interestEarned = account2.calculateInterest();
    cout << " adding $ " << interestEarned << "Interest to account2 " << endl;
    account2.credit(interestEarned);

    cout << "New account2 balance : $" << account2.getBalance() << endl;

    return 0;
}
