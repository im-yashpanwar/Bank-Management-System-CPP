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

    cardType = BRONZE;
    updateCardBenefits();
    cout << endl<<"Bronze Debit Card Issued Successfully!\n"<<endl;

    loanAmount = 0;
    hasLoan = false;

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

     cout << "\n Enter Withdraw Amount: ";
    cin >> amount;

    if(amount <= 0){

        cout << "\n Enter valid value \n";
    }
    else{

        if(amount > withdrawLimit)
        {
            cout << "\nWithdrawal Limit Exceeded!\n";
            cout << "Your Card Limit is: " << withdrawLimit << endl;
            return;
        }
   
        else{

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
}

void BankAccount::display()
{
    if(accountCreated == true){
    cout << "\n----- ACCOUNT DETAILS -----\n";
    cout << "Name: " << name << endl;
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
        cout << "Debit Card: " << getCardName() << endl;
        cout << "Withdraw Limit: Rs. " << withdrawLimit << endl;
        cout << "Loan Limit: Rs. " << loanLimit << endl;

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

void BankAccount::updateCardBenefits()
{
    if(cardType == BRONZE)
{
    withdrawLimit = 10000;
    loanLimit = 50000;
    
}

else if(cardType == SILVER)
{
    withdrawLimit = 25000;
    loanLimit = 100000;
    
}

else if(cardType == GOLD)
{
    withdrawLimit = 50000;
    loanLimit = 200000;
    
}

else if(cardType == PLATINUM)
{
    withdrawLimit = 100000;
    loanLimit = 500000;
    
}
}

double BankAccount::getWithdrawLimit()
{
    return withdrawLimit;
}

string BankAccount::getCardName()
{
    if(cardType == BRONZE)
        return "Bronze";

    if(cardType == SILVER)
        return "Silver";

    if(cardType == GOLD)
        return "Gold";

    return "Platinum";
}

void BankAccount::upgradeCard()
{
    cout << "\nCurrent Card: " << getCardName() << endl;

    cout << "\nUpgrade Options:\n";

    cout << "1. Silver (Rs. 500)\n";
    cout << "   Withdraw Limit : Rs. 25,000\n";
    cout << "   Loan Limit     : Rs. 1,00,000\n";
    

    cout << "2. Gold (Rs. 1000)\n";
    cout << "   Withdraw Limit : Rs. 50,000\n";
    cout << "   Loan Limit     : Rs. 2,00,000\n";
    

    cout << "3. Platinum (Rs. 2000)\n";
    cout << "   Withdraw Limit : Rs. 1,00,000\n";
    cout << "   Loan Limit     : Rs. 5,00,000\n";
    

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1)
    {
        if(cardType == BRONZE)
        {
            if(balance >= 500)
            {
                balance -= 500;
                cardType = SILVER;
                updateCardBenefits();
                cout << "Congratulations! Your card has been upgraded to Silver.\n";
            }
            else
            {
                cout << "Insufficient Balance!\n";
            }
        }
        else
        {
            cout << "You cannot upgrade to Silver.\n";
        }
    }

    else if(choice == 2)
    {
        if(cardType == SILVER)
        {
            if(balance >= 1000)
            {
                balance -= 1000;
                cardType = GOLD;
                updateCardBenefits();
                cout << "Congratulations! Your card has been upgraded to Gold.\n";
            }
            else
            {
                cout << "Insufficient Balance!\n";
            }
        }
        else
        {
            cout << "You must have a Silver card before upgrading to Gold.\n";
        }
    }

    else if(choice == 3)
    {
        if(cardType == GOLD)
        {
            if(balance >= 2000)
            {
                balance -= 2000;
                cardType = PLATINUM;
                updateCardBenefits();
                cout << "Congratulations! Your card has been upgraded to Platinum.\n";
            }
            else
            {
                cout << "Insufficient Balance!\n";
            }
        }
        else
        {
            cout << "You must have a Gold card before upgrading to Platinum.\n";
        }
    }

    else
    {
        cout << "Invalid Choice!\n";
    }
}

void BankAccount::takeLoan()
{
     double amount;

    cout << "Enter Loan Amount: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid Loan Amount!\n";
        return;
    }

    if(hasLoan)
    {
        cout << "You already have an active loan.\n";
        return;
    }

     if(amount > loanLimit)
    {
        cout << "Loan Limit Exceeded!\n";
        cout << "Your Maximum Loan Limit is Rs. " << loanLimit << endl;
        return;
    }

    balance += amount;
    loanAmount = amount;
    hasLoan = true;

    cout << "Loan Approved Successfully!\n";
    cout << "Loan Amount: Rs. " << loanAmount << endl;
    cout << "Current Balance: Rs. " << balance << endl;
}