#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
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
        this->balance=balance;
        }
        //setter
        void setBalance(double balance)
        {
            this->balance=balance;
        }
        // getter
        double getBalance()
        {
            return balance;
        }

        // methods
         void Printinfo()
         {
             Person :: Printinfo();
             cout << "balance-> " << balance << endl;
         }
};

#endif // CLIENT_H
