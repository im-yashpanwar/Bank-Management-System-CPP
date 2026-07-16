#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BankAccount {
    
private:
    string name;
    double balance = 0;
    int AccountNumber;
    int pin;
    bool accountCreated = false;
    static int nextAccountNumber;

public:
    void createAccount();
    void deposit();
    void withdraw();
    void display();
    int getAccountNumber();
    int getpin();
    void depositAmount(double a);
    bool withdrawAmount(double a);

};

#endif

