#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Person.h>
#include <Validation.h>
using namespace std;

class Employee : public Person
{

    	// att
protected:
    double salary;
        // con
    public:
        Employee()
        {
        salary=0.0;
        }
        Employee(string name , int id, string password, double salary) :Person(name,id,password)
        {
            setSalary(salary);

        }
        //setter
        void setSalary(double salary){
        while (!Validation::checkSalary(salary))
    {
        cin >> salary;
    }
    this->salary = salary;
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
             cout << "Salary -> " << salary << endl;
         }
};

#endif // EMPLOYEE_H
