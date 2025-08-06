#include <iostream>
using namespace std;
int main()
{
    int dd, mm, yy, age;
    int pd, pm, py;
    cout << "Enter present Date:";
    cin >> pd >> pm >> py;
    cout << "Enter date of Birth of Person:";
    cin >> dd >> mm >> yy;
    if (mm > pm)
    {
        age = (py - yy) - 1;
        cout << "\nAge of person:" << age;
    }
    else if (mm == pm)
    {
        if (dd > pm)
        {
            cout << " Belated Happy Birthday\n";
            age = py - yy;
            cout << "\nAge of person:" << age;
        }
        if (pd == mm)
        {
            cout << "Happy Birthday\n";
            age = py - yy;
            cout << "\nAge of person:" << age;
        }
        else
            age = (py - yy) - 1;
        cout << "\nAge of person:" << age;
    }
    else
    {
        age = py - yy;
        cout << "\nAge of person:" << age;
    }
    return 0;
}
