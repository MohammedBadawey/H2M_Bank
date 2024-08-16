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
        char op;
        cout << "\t\t\t\t\t Welcome to H2M bank\n";
       do {
        cout << "\t\t\t\t\t   :: Main menu ::\n";
        cout << "\t\t\t\t\t 1-New account\n";
        cout << "\t\t\t\t\t 2-Deposit amount\n";
        cout << "\t\t\t\t\t 3-Withdraw amount\n";
        cout << "\t\t\t\t\t 4-Show balance\n";
        cout << "\t\t\t\t\t 5-Delete account\n";
        cout << "\t\t\t\t\t 6-Administrator\n";
        cout << "\t\t\t\t\t 7-Exit\n";
        cout << "\nEnter your choise\n";
        cin >> choise;

        switch(choise)
        {
        case 1: {CreateClientAccount();break;}
        case 2: {cout << "Coming soon\n";break;}
        case 3: {cout << "Coming soon\n";break;}
        case 4: {cout << "Coming soon\n";break;}
        case 5: {cout << "Coming soon\n";break;}
        case 6: {cout << "Coming soon\n";break;}
        case 7: {cout << "Exiting system... Goodbye!\n";return;}
        default: {cout << "Invalid choice, please try again.\n";}
        }
        cout<<"Press [Y] to Countinue ?";
        cin >> op;
       } while(op == 'y'||op =='Y');



    }

    static void CreateClientAccount(){
        string name,password;
        double balance;

    do {
        cout << "Enter your name\n";
        cin.ignore();
        getline(cin, name);
    } while (!Validation::checkName(name));

    do {
        cout << "Enter your password\n";
        cin >> password;
    } while (!Validation::checkPassword(password));

    do {
        cout << "Enter your balance\n";
        cin >> balance;
    } while (!Validation::checkBalance(balance));
     Client newClient(name, clientList.size() + 1, password, balance);
    clientList.push_back(newClient);

        newClient.Display();
    }
};

#endif // FUNCTIONS_H
