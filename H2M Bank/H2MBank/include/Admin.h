#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Employee.h>
using namespace std;

class Admin : public Employee
{
public:
    Admin() {}

    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary)
    {}

    void Printinfo()
    {
        Employee::Printinfo();
    }
};

#endif // ADMIN_H
