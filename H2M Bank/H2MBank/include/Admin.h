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
    static Admin* AdminAccount;
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}

public:
    static Admin& getAdminAccount() {
        if (AdminAccount == nullptr) {
            AdminAccount = new Admin("admin", 1, "admin12345", 12000);
        }
        return *AdminAccount;
    }

    void Display()
    {
        Employee::Display();
    }
};

#endif // ADMIN_H
