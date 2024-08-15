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
public:
	// cons
    Person()
    {
        id =0;
    }
    Person (string name , int id, string password)
    {
        setName(name);
        SetId(id);
        setPassword(password);
    }
	//setter
     void setName(string name)
    {
        if (Validation ::checkName(name))
        {
            this->name=name;
        }
        else {cin >> name;
        setName(name);}
    }

     void SetId(int id)
    {
        this->id=id;
    }

    void setPassword(string password)

    {
        if (Validation ::checkPassword(password))
        {
        this->password=password;
        }
        else {
            cin >> password;
            setPassword(password);
        }
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
