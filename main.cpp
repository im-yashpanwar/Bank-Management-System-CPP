#include "bankaccount.h"
#include "bankaccount.cpp"
#include <vector>
int main()
{
    vector <BankAccount> accounts;

    int choice = 0;

    while (choice <= 6)
    {
    
        cout << "\n----- BANK MENU -----\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display\n";
        cout << "5. Transfer Money\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
            {
                BankAccount newUser;

                newUser.createAccount();

                accounts.push_back(newUser);

                break;

            }
            case 2:
            {
                int accNo;
                int cpin;
                bool found = false;

                cout << "\nEnter Account Number: ";
                cin >> accNo;

                for(int i = 0; i < accounts.size(); i++)
                {
                    if(accounts[i].getAccountNumber() == accNo)
                    {
                        cout << " Enter Your Pin : ";
                        cin >> cpin;

                        if(accounts[i].getpin() == cpin)
                        {
                        accounts[i].deposit();

                        found = true;

                        break;
                        }
                        else
                        {
                            cout << "\n Your pin is wrong\n";
                            found = true;
                            break;
                        }
                    }
                }

                if(found == false)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }
                

            case 3:
            {
                int accNo;
                int cpin;
                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for(int i = 0; i < accounts.size(); i++)
                {
                    if(accounts[i].getAccountNumber() == accNo)
                    {
                        cout << " Enter Your Pin : ";
                        cin >> cpin;

                        if(accounts[i].getpin() == cpin)
                        {
                        accounts[i].withdraw();

                        found = true;

                        break;
                        }
                        else
                        {
                            cout << "Account Not Found!\n";
                            found = true;
                            break;
                        }
                    }
                }

                if(found == false)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }

            case 4:
            {
                int accNo;
                int cpin;
                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for(int i = 0; i < accounts.size(); i++)
                {
    
                    if (accounts[i].getAccountNumber() == accNo)
                    {
                        cout << " Enter Your Pin : ";
                        cin >> cpin;

                        if(accounts[i].getpin() == cpin)
                        {

                            accounts[i].display();
                            found = true;
                            break;
                        }
                        else
                        {
                            cout << "Account Not Found!\n";
                            found = true;
                            break;
                        }
                    }
                }
                if(found == false)
                {
                    cout << "Account Not Found!\n";
                }
                break;
            }

            case 5:
            {
                int senderAcc;
                int receiverAcc;
                int cpin;

                double amount;

                int senderIndex = -1;
                int receiverIndex = -1;
                
                cout << "Enter Sender Account Number: ";
                cin >> senderAcc;

                for(int i = 0; i < accounts.size(); i++)
                {
                    if(accounts[i].getAccountNumber() == senderAcc)
                    {
                        senderIndex = i;
                        break;
                    }
                }

                if(senderIndex == -1)
                {
                    cout << "Sender Account Not Found!\n";
                    break;
                }

                cout << "Enter PIN: ";
                cin >> cpin;

                if(accounts[senderIndex].getpin() != cpin)
                {
                    cout << "Incorrect PIN!\n";
                    break;
                }

                cout << "Enter Receiver Account Number: ";
                cin >> receiverAcc;

                for(int i = 0; i < accounts.size(); i++)
                {
                    if(accounts[i].getAccountNumber() == receiverAcc)
                    {
                        receiverIndex = i;
                        break;
                    }
                }

                if(receiverIndex == -1)
                {
                    cout << "Receiver Account Not Found!\n";
                    break;
                }

                cout << "Enter Amount: ";
                cin >> amount;

                if(accounts[senderIndex].withdrawAmount(amount))
                {
                    accounts[receiverIndex].depositAmount(amount);

                    cout << "Transfer Successful!\n";
                }
                else
                {
                    cout << "Insufficient Balance!\n";
                }

                break;
            }
            
            case 6:
            {
                cout << "Exiting Program...\n";
                break;
            }

            default:
            {
                cout << "Invalid Choice!\n";
            }
        }
    
    }
    

    return 0;

}


