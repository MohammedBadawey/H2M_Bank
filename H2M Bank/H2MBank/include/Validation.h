#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <exception>
using namespace std;

class Validation {
public:
    static bool validateName(const string& name)
    {
        if (name.length() < 5 || name.length() > 20)
        {
            cout << "Name must be between 5 and 20 characters\n";
            return false;
        }

        int sum = 0;
        for (int i = 0; i < name.length(); i++)
        {
            if (isalpha(name[i]))
            {
                sum++;
            }
        }

        if (sum == name.length())
        {
            return true;
        }
        else
        {
            cout << "Name must contain only alphabetic characters\n";
            return false;
        }
    }

    static bool validatePassword(const string& password)
    {
        if (password.length() < 8 || password.length() > 20)
        {
            cout << "Password must be between 8 and 20 characters\n";
            return false;
        }
        return true;
    }

    static bool validateMinBalance(double balance)
    {
        if (balance < 1500)
        {
            cout << "Balance must be at least 1500\n";
            return false;
        }
        return true;
    }

    static bool validateMinSalary(double salary)
    {
        if (salary < 5000)
        {
            cout << "Salary must be at least 5000\n";
            return false;
        }
        return true;
    }
};


#endif // VALIDATION_H
