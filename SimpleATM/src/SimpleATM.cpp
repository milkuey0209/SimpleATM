#include "../include/SimpleATM.h"

int main(void)
{
    while (true)
    {
        ShowMenu();
        cout << "--- Select Menu ---" << endl;
        cin >> SelectMenu;
        cout << endl;

        switch (SelectMenu)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            Deposit();
            break;
        case WITHDRAW:
            Withdraw();
            break;
        case SHOWLIST:
            ShowList();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Invalid Input:" << endl;
        }
    }
}

void ShowMenu()
{
    cout << "--- Menu ---" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Show All Account" << endl;
    cout << "5. Exit" << endl; 
}

void MakeAccount()
{
    int PinNubmer;
    char Name[NAME_LENGTH];
    int Balance;
    
    cout << "--- Make Credit Card ---" << endl;
    cout << "Create Pin Number: ";
    cin >> PinNubmer;
    cout << "Create Name ( Max 20 ): ";
    cin >> Name;
    cout << "Enter Balance ( dollar[$] ): ";
    cin >> Balance;
    cout << endl;

    AccountArray[AccountNubmer++] = new Account(PinNubmer, Balance, Name);
    
}

void Deposit()
{
    int PinNubmer;
    int Money;

    cout << "--- Deposit Money ---" << endl;
    cout << "Deposit Pin Number: ";
    cin >> PinNubmer;
    cout << "Deposit Money( dollar[$] ) : ";
    cin >> Money;

    for (int i = 0; i < AccountNubmer; i++)
    {
        if (AccountArray[i]->GetAccountID() == PinNubmer)
        {
            AccountArray[i]->Deposit(Money);
            cout << "Deposit Complete!: " << endl << endl;
            return;
        }
        else
        {
            cout << "Invalid Account!" << endl << endl;
        }
    }
}

void Withdraw()
{
    int PinNubmer;
    int Money;
    cout << "--- Withdraw Money ---" << endl;
    cout << "Withdraw Pin Number: ";
    cin >> PinNubmer;
    cout << "Withdraw Money( dollar[$] ): ";
    cin >> Money;
    for (int i = 0; i < AccountNubmer; i++)
    {
        if (AccountArray[i]->GetAccountID() == PinNubmer)
        {
            if (AccountArray[i]->Withdraw(Money) == 0)
            {
                cout << "Account is Empty!" << endl << endl;
            }
            else
            {
                cout << "Withdraw Complete!" << endl << endl;
            }
        }
        else
        {
            cout << "Invalid Account!" << endl << endl;
        }
    }
}

void ShowList()
{
    for (int i = 0; i < AccountNubmer; i++)
    {
        AccountArray[i]->ShowInfo();
        cout << endl;    
    }
}
