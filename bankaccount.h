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

    double upgradeCost = 0;
    int cardTransactionCount = 0;

    double loanAmount;
    double loanLimit;
    bool hasLoan;

    double interestRate = 0;
    double interestAmount = 0;
    double totalRepayment = 0;

    double emiAmount = 0;

    int totalInstallments = 0;
    int remainingInstallments = 0;

    int emiTransactionCount = 0;
    int warningCount = 0;

    bool pendingEMI = false;
    bool accountFrozen = false;

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
    void setupLoan();
    void closeLoan();
    void processEMI();
    void payPendingEMI();

};

#endif

