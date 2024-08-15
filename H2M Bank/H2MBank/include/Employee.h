#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <Person.h>
#include <Validation.h>
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
            setSalary(salary);

        }
        //setter
        void setSalary(double salary)
        {
        if(Validation::checkBalance(salary))
          {
                this->salary=salary;
          }
        else {
            cin >> salary;
            setSalary(salary);
        }
        }

        // getter
        double getSalary()
        {
            return salary;
        }

        // methods
         void Display()
         {
             Person :: Display();
             cout << "Salary-> " << salary << endl;
         }
};

#endif // EMPLOYEE_H
