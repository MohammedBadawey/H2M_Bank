#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Person.h>
using namespace std;

class Employee : public Person
{
    	// att
private:
    double salary;
        // con
    public:
        Employee()
        {
        salary=0.0;
        }
        Employee(string name , int id, string password, double salary) : Person(name,id,password)
        {
        this->salary=salary;
        }
        //setter
        void setSalary(double salary)
        {
            this->salary=salary;
        }
        // getter
        double getSalary()
        {
            return salary;
        }

        // methods
         void Printinfo()
         {
             Person :: Printinfo();
             cout << "Salary-> " << salary << endl;
         }
};

#endif // EMPLOYEE_H
