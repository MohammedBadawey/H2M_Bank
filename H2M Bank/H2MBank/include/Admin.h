#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <Employee.h>
#include <Validation.h>
using namespace std;

class Admin : public Employee
{
private:
    static Admin* instance;
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary)
    {}

public:
    static Admin* getInstance(string name, int id, string password, double salary)
    {
        if (instance == nullptr)
        {
            instance = new Admin(name, id, password, salary);
        }
        return instance;
    }

    void Display()
    {
        Employee::Display();
    }

    ~Admin()
    {
        delete instance;
        instance = nullptr;
    }
};


#endif // ADMIN_H
