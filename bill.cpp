#include <iostream>
using namespace std;

int main()
{
    float unit, total=50;
    char name[100];

    cout <<"Enter the Name: ";
    cin >> name;
    cout <<"Enter any unit:"<<endl;
    cin >> unit;

    if (unit<100)
    {
        total=total+(unit*0.6);
    }

    else if (unit>100 && unit<=300)
    {
        total=total+(100*0.6)+((unit-100)*0.8);
    }

    else if (unit>300)
    {
        total=total+220+((unit-100)*0.9);
    }

    if(unit>300)
    {
        cout <<"Total Bill is: "<<total+(total*0.15)<<"TK";
    }
    else
    {
        cout << "Total Bill is: " <<total<<"TK"<<endl;
    }
    return 0;
}
