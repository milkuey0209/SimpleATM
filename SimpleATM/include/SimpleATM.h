#pragma once
#include <array>
#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LENGTH = 20;
enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    SHOWLIST,
    EXIT
};

class Account
{
private:
    int PINID;
    int Balance;
    char* CustomerName;

public:
    
    Account(int InID, int InMoney, char* InName) : PINID(InID), Balance(InMoney)
    {
        CustomerName = new char[strlen(InName) + 1];
        strcpy_s(CustomerName,strlen(InName) + 1, InName);
    }

    int GetAccountID() const {return PINID;}
    char* GetCustomerName() const {return CustomerName;}
    int GetBalance() const {return Balance;}

    void Deposit(int InMoney)
    {
        Balance += InMoney;
    }

    int Withdraw(int InMoney)
    {
        if (Balance < InMoney)
            return 0;
        Balance -= InMoney;
        return InMoney;
    }
    
    void ShowInfo()
    {
        cout << "AccountID: " << PINID << endl;
        cout << "CustomerName: " << CustomerName << endl;
        cout << "Balance ( dollar[$] ): " << Balance << endl;
    }
    ~Account()
    {
        delete[] CustomerName;
    }
};
Account* AccountArray[100];
int AccountNubmer = 0;

int TypePinNubmer;
int SelectMenu;

void ShowMenu();
void MakeAccount();
void Deposit();
void Withdraw();
void ShowList();