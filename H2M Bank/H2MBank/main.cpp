#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <Person.h>
#include <Client.h>
#include <Employee.h>
using namespace std;


int main()
{
    Client a("Ahmed",1,"123",1500.5);
    Employee m ("Mohammed",1,"123",3500.5);
    a.Printinfo();
    m.Printinfo();

    return 0;
}
