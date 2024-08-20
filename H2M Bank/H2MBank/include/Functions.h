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
    static vector <Employee*> employeeList;
    static vector <Admin*> adminList;
    static int currentClientId;
public:

    static void OpenSystem()
{

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
    case 2: {CreateAccount("Client");;break;}
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


    static void CreateAccount(const string& accountType){
    string name, password;
    double acountTypeValue;
    int id;
      if (accountType == "Client") {
        id = Client::getNewClientId();
        Validation::ValidationData(name, password, acountTypeValue, "Client");
        Client* newClient = new Client(name, id, password, acountTypeValue);
        clientList.push_back(newClient);
        cout << "Client account created successfully.\n";
        newClient->Display();
    }
    else if (accountType == "Employee") {
        id = Employee::getNewEmployeeId();
        Validation::ValidationData(name, password, acountTypeValue, "Employee");
        Employee* newEmployee = new Employee(name, id, password, acountTypeValue);
        employeeList.push_back(newEmployee);
        cout << "Employee account created successfully.\n";
        newEmployee->Display();
    } else {
        cout << "Invalid account type.\n";
    }
}



    static void AdministratorList()
    {
        int AdminChoice;
        do {
            cout << "\t\t\t\t\t   :: Administrator Menu ::\n";
            cout << "\t\t\t\t\t 1-Add Employee\n";
            cout << "\t\t\t\t\t 2-Search Client\n";
            cout << "\t\t\t\t\t 3-Return to Main Menu\n";
            cout << "\t\t\t\t\t 4-Exit\n";
            cout << "\nEnter your choice\n";
            cin >> AdminChoice;

            switch(AdminChoice)
            {
                 case 1: {CreateAccount("Employee"); break;}
                 case 2: {SearchClientById();        break;}
                 case 3: {OpenSystem();              break;}
                 case 4: {cout << "... Goodbye!\n"; return;}
                default: {cout << "Invalid choice, please try again.\n";}
            }

        } while (AdminChoice != 4);
    }

    static void ClientLogin() {
        int id, attemptsUsername = 0, attemptsPassword = 0;
        string username, password, idString;
        bool loggedIn = false;

    do {
        cout << "Enter your ID: ";
        cin >> idString;
        attemptsUsername++;

        if (Validation::isNumberId(idString)) {
            id = stoi(idString);

            if (id > 0 && id <= clientList.size()) {
                break;
            } else if (attemptsUsername < 3) {
                cout << "Invalid ID. Please enter a valid ID.\n";
            }
        } else if (attemptsUsername < 3) {
            cout << "ID must be a number. Please try again.\n";
        }

        if (attemptsUsername >= 3) {
            cout << "Too many failed attempts. Please try again later.\n";
            return;
        }

    } while (true);

    attemptsUsername = 0;

    Client* client = clientList[id - 1];

        cin.ignore();
    do {
        cout << "Enter your username: ";
        getline(cin, username);
        attemptsUsername++;

        if (client->getName() == username) {
            break;
        } else if (attemptsUsername < 3) {
            cout << "Username does not match with the entered ID. Please try again.\n";
        }

        if (attemptsUsername >= 3) {
            cout << "Too many failed attempts. Please try again later.\n";
            return;
        }

    } while (true);

    attemptsPassword = 0;

    do {
        cout << "Enter your password: ";
        getline(cin, password);
        attemptsPassword++;

        if (client->getPassword() == password) {
            cout << "Client logged in successfully.\n";
            currentClientId = client->getId();
            loggedIn = true;
            ClientMenu();
            return;
        } else if (attemptsPassword < 3) {
            cout << "Invalid password. Please try again.\n";
        }

        if (attemptsPassword >= 3) {
            cout << "Too many failed attempts. Please try again later.\n";
            return;
        }

    } while (true);
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
        cout << "\t\t\t\t\t 5-Account information\n";
        cout << "\t\t\t\t\t 6-Delete account\n";
        cout << "\t\t\t\t\t 7-Exit\n";
        cout << "\nEnter your choise\n";
        cin >> choise;

        switch(choise)
        {
         case 1: {cout << "Coming soon\n";break;}
         case 2: {cout << "Coming soon\n";break;}
         case 3: {myBalance();break;}
         case 4: {transferAmount();break;}
         case 5: {displayClient();break;}
         case 6: {cout << "Coming soon\n";break;}
         case 7: {cout << "Exiting system... Goodbye!\n";return;}
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

    static Client* SearchClientById()
{
    int id;
    cin >> id;
    if (id > 0 && id <= clientList.size()) {
        Client* clientById = clientList[id - 1];
        cout << "Client with ID " << id << "founded.\n";
        clientById->Display();
        return clientById;
    } else {
        cout << "Client with ID " << id << " not found.\n";
        return nullptr;
    }
}

    static Client* SearchClientById(int id){
    if (id > 0 && id <= clientList.size()) {
        return clientList[id - 1];}
    else {
        return nullptr;}
    }

    static void transferAmount() {
    int recipientId, attempts;
    double amount;
    attempts = 0;
    bool validRecipient = false;

    do {
        cout << "Enter recipient id\n";
        cin >> recipientId;
        attempts++;

        if (recipientId == currentClientId) {
            cout << "Cannot transfer to yourself. Transfer canceled.\n";
        } else {
            Client* recipient = SearchClientById(recipientId);
            if (recipient) {
                cout << "Client found by name: " << recipient->getName() << endl;
                validRecipient = true;
                break;
            } else {
                cout << "Recipient not found. Please try again.\n";
            }
        }
    } while (attempts < 3 && !validRecipient);

    if (!validRecipient) {
        cout << "Failed to enter a valid recipient. Transfer canceled.\n";
        return;
    }

    char confirm;
    do {
        cout << "Do you want to proceed with the transfer? (y/n): ";
        cin >> confirm;
        confirm = toupper(confirm);
        if(confirm != 'Y' && confirm != 'N'){
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
        }
    } while(confirm != 'Y' && confirm != 'N');

    if (confirm == 'Y') {
        Client* sender = SearchClientById(currentClientId);
        cout << "Enter amount: ";
        cin >> amount;
        if (amount > 0) {
            if(sender->getBalance() >= amount){
                sender->transferTo(amount, *SearchClientById(recipientId));
                cout << "Transfer completed successfully.\n";
                cout << "Your balance Now is -> " << sender->getBalance() << endl;
            } else {
                cout << "Insufficient balance. Transfer canceled.\n";
            }
        } else {
            cout << "Invalid amount entered. Transfer canceled.\n";
        }
    } else {
        cout << "Transfer canceled.\n";
    }
}

    static Client* displayClient(){
        Client* disClient = SearchClientById(currentClientId);
        disClient->Display();
        }

    static void myBalance(){
    Client* showBalance = SearchClientById(currentClientId);
    showBalance ->checkBalance();
    }

};

#endif // FUNCTIONS_H
