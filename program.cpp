#include <iostream>
using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string accountHolderName;
    double balance;

    BankAccount()
    {
        accountNumber = 219022789;
        accountHolderName = "Perry";
        balance = 50000;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposite amount!" << endl;
            return;
        }
        balance += amount;
        cout << "Deposit successful!" << endl;
        cout << "Current balance:" << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdraw amount!" << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance! Withdraw denied" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdraw successful!" << endl;
            cout << "Balance:" << balance << endl;
        }
    }

    void getBalance()
    {
        cout << "Current balance:" << balance << endl;
    }

    void displayAccount()
    {
        cout << "Account number: " << accountNumber << endl;
        cout << "Acount holder name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
public:
    double interestRate;

    SavingsAccount()
    {
        interestRate = 2.0;
    }

    void calculateInterest()
    {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest amount:" << interest << endl;
        cout << "Balance after interest add:" << balance << endl;
    }
};

class CheckingAccount : public BankAccount
{
public:
    int over_draft_limit;

    CheckingAccount()
    {
        over_draft_limit = 40000;
    }

    void displayOverdraftLimit()
    {
        cout << "Overdraft limit:" << over_draft_limit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    int term;
    double interest_rate;
    double fixedBalance;

    FixedDepositAccount()
    {
        term = 12;
        interest_rate = 5;
        fixedBalance = 0;
    }

    void depositeToFD(double amount, int month)
    {
        if (amount <= 0 || month <= 0)
        {
            cout << "Invalid amount!!" << endl;
            return;
        }
        fixedBalance = amount;
        term = month;
    }

    void calculateInterestFD()
    {
        double interest = (fixedBalance * interest_rate * term) / 100;
        fixedBalance += interest;
        cout << "Fixed deposite interest amount:" << interest << endl;
        cout << "Total balance in fixed deposit:" << fixedBalance << endl;
    }
};

int main()
{
    int choice;
    SavingsAccount s1;
    CheckingAccount c1;
    FixedDepositAccount f1;

    do
    {
        cout << endl;
        cout << "---Banking System---" << endl;

        cout << "1. Deposite" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Display Account Info" << endl;
        cout << "5. Calculate Interest" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Enter your choice:";
        cin >> choice;

        double amount;
        int term;

        switch (choice)
        {
        case 1:
            cout << "Enter deposit amount:";
            cin >> amount;
            s1.deposit(amount);
            break;

        case 2:
            cout << "Enter withdraw amount:";
            cin >> amount;
            s1.withdraw(amount);
            break;

        case 3:
            s1.getBalance();
            break;

        case 4:
            s1.displayAccount();
            break;

        case 5:
            s1.calculateInterest();
            break;

        case 6:
            cout << "Exit the program!!";
            break;

        default:
            cout << "Invalid input!! Please Tray Again" << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}