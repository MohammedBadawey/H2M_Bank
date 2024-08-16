#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <Validation.h>
using namespace std;

class Person {
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
        setId(id);
        setPassword(password);
    }
	//setter
     void setName(string name) {
        while (!Validation::checkName(name)) {
            getline(cin, name);
        }
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setPassword(string password) {
        while (!Validation::checkPassword(password)) {
            cin >> password;
        }
        this->password = password;
    }
	//getter
    const string getName()const
	{
	    return name;
	}
	const int getId()
	{
	    return id;
	}
	const string getPassword()const
	{
	    return password;
	}

	//method
    const void Display()
    {
        cout << "Name -> " << name << endl;
        cout << "Id -> " << id << endl;
    }
};

#endif // PERSON_H
