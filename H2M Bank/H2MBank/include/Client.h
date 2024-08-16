#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <Person.h>
#include <Validation.h>
using namespace std;

class Client : public Person
{
    	// att
private:
    double balance;
        // con
    public:
        Client()
        {
        balance=0.0;
        }
        Client(string name , int id, string password, double balance) : Person(name,id,password)
        {
          setBalance(balance);
        }

        //setter
        void setBalance(double balance) {
        while (!Validation::checkBalance(balance)) {
        cin >> balance;
        }
        this->balance = balance;
        }
        // getter
       double getBalance()
        {
        return balance;
        }
        // methods

          void deposit(double amount)
        {
        balance += amount;
        cout << "Deposit successful" << endl;
        cout << "Your balance now: " << balance << endl;
        }

        void withdraw(double amount)
{
    if (amount <= balance)
    {
    balance -= amount;
 cout << "Withdraw successful" << endl;
 cout << "Your balance now: " << balance << endl;
    }
    else
    {
        cout << "Wrong value\n";
    }
}
            void transferTo(double amount, Client& recipient)
{
    if (amount >= balance)
    {
        balance -= amount;
        recipient.deposit(amount);
     cout << "Tranafer successful" << endl;
     cout << "Your balance now: " << balance << endl;
    }
    else
    {
       cout << "Wrong value\n";
    }
}
        void checkBalance ()
{
    cout << "your balance is -> " << balance << endl;
}
 void Display()
 {
     Person :: Display();
     cout << "balance-> " << balance << endl;
 }
};

#endif // CLIENT_H
