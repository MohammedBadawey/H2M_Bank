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
#include <vector>
using namespace std;

class Functions
{
private:
    static vector <Client*> clientList;
    static vector <Employee> employeeList;
    static vector <Admin*> adminList;

public:


    static void ValidationData(string& name, string& password, double& value, const string& type) {
        do {
            cout << "Enter " << type << " name\n";
            cin.ignore();
            getline(cin, name);
        } while (!Validation::checkName(name));

        do {
            cout << "Enter " << type << " password\n";
            cin >> password;
        } while (!Validation::checkPassword(password));



        string valueType = type == "Client" ? "balance" : "salary";
        do {
            cout << "Enter " << type << " " << valueType << "\n";
            cin >> value;
        } while (type == "Client" ? !Validation::checkBalance(value) : !Validation::checkSalary(value));
    }

    static void OpenSystem()
{
    Admin* admin = Admin::getInstance();
    int choise;
    char op;
    cout << "\t\t\t\t\t Welcome to H2M bank\n";
   do {
    cout << "\t\t\t\t\t   :: Main menu ::\n";
    cout << "\t\t\t\t\t 1-Login\n";
    cout << "\t\t\t\t\t 2-Create New account\n";
    cout << "\t\t\t\t\t 3-Administrator\n";
    cout << "\t\t\t\t\t 4-Exit\n";
    cout << "\nEnter your choise\n";
    cin >> choise;

    switch(choise)
    {
    case 1: {ClientLogin();break;}
    case 2: {CreateClientAccount();break;}
    case 3: {AdminLogin();break;}
    case 4: {cout << "Exiting system... Goodbye!\n";return;}
    default: {cout << "Invalid choice, please try again.\n";}
    }
    do {
        cout << "Press [Y] to Continue or [N] to Exit: ";
        cin >> op;
        op = toupper(op);
        if(op != 'Y' && op != 'N') {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
        }
    } while(op != 'Y' && op != 'N');

    if(op == 'N') {
        cout << "Exiting system... Goodbye!\n";
        return;
    }

   } while(op == 'Y');
}

    static void CreateClientAccount(){
    string name,password;
    double balance;
    int id = Client::getNewClientId();

     ValidationData(name, password, balance, "Client");

    Client* newClient = new Client(name,id, password, balance);
    clientList.push_back(newClient);

    cout << "Account created successfully.\n";
    newClient->Display();
}



    static void CreateEmployeeAccount(){
    string name,password;
    double salary;
    int id = Employee::getNewEmployeeId();
ValidationData(name, password, salary, "Employee");

 Employee newEmployee(name, id, password, salary);
 employeeList.push_back(newEmployee);

    newEmployee.Display();
}


    static void AdministratorList()
    {
        int AdminChoice;
        do {
            cout << "\t\t\t\t\t   :: Administrator Menu ::\n";
            cout << "\t\t\t\t\t 1-Add Employee\n";
            cout << "\t\t\t\t\t 2-Return to Main Menu\n";
            cout << "\t\t\t\t\t 3-Exit\n";
            cout << "\nEnter your choice\n";
            cin >> AdminChoice;

            switch(AdminChoice)
            {
                 case 1: {CreateEmployeeAccount();  break;}
                 case 2: {OpenSystem();             break;}
                 case 3: {cout << "... Goodbye!\n"; return;}
                default: {cout << "Invalid choice, please try again.\n";}
            }

        } while (AdminChoice != 4);
    }
    static void ClientLogin()
{
    string username, password;
    bool loggedIn = false;

    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);

    // Check for client
    for (size_t i = 0; i < clientList.size(); ++i) {
        const Client* client = clientList[i];
        if (client->getName() == username && client->getPassword() == password) {
            cout << "Client logged in successfully.\n";
            loggedIn = true;
            ClientMenu();
        }
    }
    if (!loggedIn) {
        cout << "Invalid username or password. Please try again.\n";
    }
}
    static void ClientMenu(){
    int choise;
        char op;
       do {
        cout << "\t\t\t\t\t   :: Client menu ::\n";
        cout << "\t\t\t\t\t 1-Deposit amount\n";
        cout << "\t\t\t\t\t 2-Withdraw amount\n";
        cout << "\t\t\t\t\t 3-Show balance\n";
        cout << "\t\t\t\t\t 4-Transfer\n";
        cout << "\t\t\t\t\t 5-Delete account\n";
        cout << "\t\t\t\t\t 6-Exit\n";
        cout << "\nEnter your choise\n";
        cin >> choise;

        switch(choise)
        {
         case 1: {cout << "Coming soon\n";break;}
         case 2: {cout << "Coming soon\n";break;}
         case 3: {cout << "Coming soon\n";break;}
         case 4: {cout << "Coming soon\n";break;}
         case 5: {cout << "Coming soon\n";break;}
         case 6: {cout << "Exiting system... Goodbye!\n";return;}
        default: {cout << "Invalid choice, please try again.\n";}
        }
        do {
            cout << "Press [Y] to Continue or [N] to Exit: ";
            cin >> op;
            op = toupper(op);
            if(op != 'Y' && op != 'N') {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            }
        } while(op != 'Y' && op != 'N');

        if(op == 'N') {
            cout << "Exiting system... Goodbye!\n";
            return;
        }

       } while(op == 'Y');
    }
    static void AdminLogin()
    {
        string username, password;
        bool loggedIn = false;

        cout << "Enter your username: ";
        cin.ignore();
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);

       Admin* admin = Admin::getInstance();
        if (admin->getName() == username && admin->getPassword() == password) {
            cout << "Admin logged in successfully.\n";
            loggedIn = true;
            AdministratorList();
            }


        if (!loggedIn) {
            cout << "Invalid username or password. Please try again.\n";
        }
    }


};

#endif // FUNCTIONS_H
