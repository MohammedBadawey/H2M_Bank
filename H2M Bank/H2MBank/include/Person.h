#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

class Person{
protected:
	// att
    string name;
    int id;
    string password;
public:
	// cons
    Person(){
    int id =0;}
    Person (string name , int id, string password)
    this-> name = name;
    this->id =id;
    this->password=password;
	//setter
    void steName(string name)
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
    void setPersonData(string name,int id,string password)
    {
        this->name=name;
        this->id=id;
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
    void Printinfo()
    {
        cout << "Name -> " << name << endl;
        cout << "Id -> " << id << endl;
        cout << "Password" << "******" << endl;
    }
};

#endif // PERSON_H
