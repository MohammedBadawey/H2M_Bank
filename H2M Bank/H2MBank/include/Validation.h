#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <exception>
#include <stdexcept>
using namespace std;

class Validation
{
public:

    static bool checkName(const string& name){
    int lengthOfName = name.length();

    if (lengthOfName < 5 || lengthOfName > 20)
    {
        cout << "The name must be between 5 and 20 characters\n";
        return false;
    }

    for (char c : name)
    {
        if (!isalpha(c)&&!isspace(c))
        {
            cout << "The name must contain only alphabetic characters\n";
            return false;
        }
    }
        return true;
}


    static bool checkPassword(const string& password)
    {
        if (password.length() < 8 || password.length() > 20)
        {
            cout << "Password must be between 8 and 20 characters\n";
            return false;
        }
        return true;
    }


    static bool checkBalance(double balance)
    {
        if (balance < 1500)
        {
            cout << "Balance must be at least 1500\n";
            return false;
        }
        return true;
    }


    static bool checkSalary(double salary)
    {
        if (salary < 5000)
        {
            cout << "Salary must be at least 5000\n";
            return false;
        }
        return true;
    }


    static void ValidationData(string& name, string& password, double& value, const string& type) {
        do {
            cout << "Enter " << type << " name\n";
            string temp;
            getline(cin, temp);
            name = temp;
        } while (!checkName(name));

        do {
            cout << "Enter " << type << " password\n";
            cin >> password;
        } while (!checkPassword(password));



        string valueType = type == "Client" ? "balance" : "salary";
        do {
            cout << "Enter " << type << " " << valueType << "\n";
            cin >> value;
        } while (type == "Client" ? !checkBalance(value) : !checkSalary(value));
    }

    static bool isNumberId(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
}


};


#endif // VALIDATION_H
