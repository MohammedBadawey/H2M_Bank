#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Person.h>
#include <Client.h>
#include <Employee.h>
#include <Admin.h>
#include <Validation.h>
using namespace std;


int main(){
    Client a1;
    string name;
    cout << "enter your name\n";
    getline (cin, name);
    a1.setName(name);
    cout << "enter your password\n";
    string pass;
    cin >> pass;
    a1.setPassword(pass);
    cout << a1.getName();
    cout << a1.getPassword();



    return 0;

}
