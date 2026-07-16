#include "bankaccount.h"
#include <fstream>
int BankAccount::nextAccountNumber = 1001;

void BankAccount::createAccount()
{
    cout << "Enter Name: ";
    cin >> name;

    AccountNumber = nextAccountNumber;
    nextAccountNumber++;

    cout << "Set PIN: ";
    cin >> pin;

    accountCreated = true;

    cout<< "\nAccount Created Successfully\n";
    cout<< "your account number is  =  ";
    cout<< AccountNumber;

}

void BankAccount::deposit()
{
    if (accountCreated == false){
        cout << "\ncreat account first \n" << endl;
    }
    else{
    double amount;

    cout << "\nEnter Deposit Amount: ";
    cin >> amount;

    if(amount <= 0){

        cout << "\n Enter valid value \n";
    }
    else{

    balance = balance + amount;

    cout << "Amount Deposited Successfully!\n";
    }
}
}

void BankAccount::withdraw()
{
     if (accountCreated == false){
        cout << "\n creat account first \n" << endl;
    }
    else{
    double amount;

    if(amount <= 0){

        cout << "\n Enter valid value \n";
    }
    else{

    cout << "\n Enter Withdraw Amount: ";
    cin >> amount;

    if(amount > balance)
    {
        cout << "Insufficient Balance!\n";
    }
    else
    {
        balance = balance - amount;

        cout << "Withdrawal Successful!\n";
    }
}
}
}

void BankAccount::display()
{
    if(accountCreated == true){
    cout << "\n----- ACCOUNT DETAILS -----\n";

    cout << "Name: " << name << endl;
    cout << "Account Number: " << AccountNumber << endl;
    cout << "Balance: " << balance << endl;
    }
    else{
        
        cout << "\n Creat Account First \n" <<endl;
    }
}

int BankAccount::getAccountNumber()
{
    return AccountNumber;
}

int BankAccount::getpin()
{
    return pin;
}

void BankAccount::depositAmount(double a)
{
    balance += a;
}

bool BankAccount::withdrawAmount(double a)
{
    if(a > balance)
    {
        return false;
    }

    balance -= a;

    return true;
}

