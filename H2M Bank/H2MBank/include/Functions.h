#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Person.h>
#include <Client.h>
#include <Employee.h>
#include <Admin.h>
#include <Validation.h>
#include <BankAccount.h>
#include <vector>
using namespace std;

class Functions
{
private:
    static vector <Client> clientList;
public:
    static void OpenSystem()
    {
        int choise;
        cout << "\t Welcome to H2M bank\n";
        cout << "\t   :: Main menu ::\n";
        cout << "\t 1-New account\n";
        cout << "\t 2-Deposit amount\n";
        cout << "\t 3-Withdraw amount\n";
        cout << "\t 4-Show balance\n";
        cout << "\t 5-Delete account\n";
        cout << "\t 6-Administrator\n";
        cout << "\t 7-Exit\n";
        cin >> choise;
        switch(choise){
        case 1: {CreateClientAccount();}
                break;
        case 2: {cout << "Coming soon";}
                break;
        case 3: {cout << "Coming soon";}
                break;
        case 4: {cout << "Coming soon";}
                break;
        case 5: {cout << "Coming soon";}
                break;
        case 6: {cout << "Coming soon";}
                break;
        case 7: {cout << "Coming soon";}
                break;
        case 8: {return;}
                break;
        }


    }

    static void CreateClientAccount(){
        string name,password;
        double balance;

    cout << "Enter your name\n";
    cin.ignore();
    getline(cin,name);
    cout << "Enter your password\n";
    cin >> password;
    cout << "Enter your balance\n";
    cin >> balance;
     Client newClient(name, clientList.size() + 1, password, balance);
    clientList.push_back(newClient);

        newClient.Display();
    }
};

#endif // FUNCTIONS_H
