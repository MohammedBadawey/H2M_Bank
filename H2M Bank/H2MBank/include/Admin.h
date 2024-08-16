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
public:
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary)
    {}

    void Display()
    {
        Employee::Display();
    }
};

#endif // ADMIN_H
