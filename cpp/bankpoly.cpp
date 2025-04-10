#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initBalance) : accountNumber(accNum), balance(initBalance) {}
    
    virtual void deposit(double amount) 
    {
        balance += amount;
    }

    virtual void withdraw(double amount) 
    {
        if (amount <= balance) 
        {
            balance -= amount;
        } 
        else 
        {
            cout << "Insufficient funds\n";
        }
    }

    virtual void display()
    {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: Rs " << balance << "\n";
    }
};

class SavingsAccount : public Account 
{
    double interestRate;

public:
    SavingsAccount(string accNum, double initBalance, double interest) : Account(accNum, initBalance), interestRate(interest) {}

    void display() 
    {
        cout << "Account Type: Savings\n";
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initBalance, double overdraft) : Account(accNum, initBalance), overdraftLimit(overdraft) {}

    void withdraw(double amount) 
    {
        if (balance + overdraftLimit >= amount) 
        {
            balance -= amount;
        }
        else
        {
            cout << "Exceeded overdraft limit\n";
        }
    }

    void display()
    {
        cout << "Account Type: Current\n";
        Account::display();
        cout << "Overdraft Limit: Rs " << overdraftLimit << "\n";
    }
};

int main() 
{
   
    SavingsAccount savings("HXR3452",10000, 12);
    CurrentAccount current("HXR2452",50000, 20000);
    
    savings.deposit(15000);
    savings.withdraw(20000);
    savings.display();
    cout << "\n";

    current.deposit(100000);
    current.withdraw(45000);
    current.display();

    return 0;
}
