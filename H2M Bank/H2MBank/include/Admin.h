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
        : Employee(name, id, password, salary){}

public:
     static Admin* getInstance(string name = "Mohammed" , int id = 1, string password = "Mohammed123", double salary = 9000){
     if (instance == nullptr)
     {
         instance = new Admin(name,id,password,salary);
     }
     else {return instance;}

     }

    const void Display()
    {
        Employee::Display();
    }
};

#endif // ADMIN_H
