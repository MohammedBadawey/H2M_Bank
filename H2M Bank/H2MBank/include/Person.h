#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <Validation.h>
using namespace std;

class Person{
protected:
	// att
    string name;
    int id;
    string password;
	// cons
    Person()
    {
        id =0;
    }
    Person (string name , int id, string password)
    {

        this->name=name;
        this->id =id;
        this->password = password;
    }
public:
	//setter
     void setName(string name)
    {

        this->name=name;
    }

     void SetId(int id)
    {
        this->id=id;
    }

    void setPassword(string password)

    {
        this->password=password;
    }

	//getter
    string getName()
	{
	    return name;
	}
	int getId()
	{
	    return id;
	}
	string getPassword()
	{
	    return password;
	}

	//method
    void Display()
    {
        cout << "Name -> " << name << endl;
        cout << "Id -> " << id << endl;
    }
};

#endif // PERSON_H
