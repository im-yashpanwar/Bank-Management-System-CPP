#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
enum CardType
{
    BRONZE,
    SILVER,
    GOLD,
    PLATINUM
};

class BankAccount {
    
private:
    string name;
    double balance = 0;
    int AccountNumber;
    int pin;
    bool accountCreated = false;
    static int nextAccountNumber;
    CardType cardType;

    double withdrawLimit;
    double loanLimit;

    double upgradeCost = 0;
    int cardTransactionCount = 0;
    double loanAmount;
    bool hasLoan;

public:
    void createAccount();
    void deposit();
    void withdraw();
    void display();
    int getAccountNumber();
    int getpin();
    void depositAmount(double a);
    bool withdrawAmount(double a);
    
    void updateCardBenefits();
    void upgradeCard();

    CardType getCardType();
    double getWithdrawLimit();
    double getLoanLimit();
    string getCardName();

    void takeLoan();

};

#endif

