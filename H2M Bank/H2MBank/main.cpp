#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Person.h>
#include <Client.h>
#include <Employee.h>
#include <Admin.h>
using namespace std;


int main()
{
    Client a("Ahmed",1,"123",1500.5);
    Employee m ("Mohammed",1,"123",3500.5);
    Admin h ("Hassan",1,"123",200);
    a.Printinfo();
    cout << endl;
    m.Printinfo();
    cout << endl;    h.Printinfo();
    cout << endl;

    return 0;
}
