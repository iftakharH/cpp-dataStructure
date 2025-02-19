#include <iostream>
using namespace std;

void sumSubtraction (int x, int y)
{
    int sum = x + y;
    int sub = x - y;
    cout << "Summation is: "<< sum << endl << "Subtraction is: "<< sub << endl;
}

void mulDiv(int x, int y)
{
    int mul = x * y;
    float div = (float)x / y;
    cout << "Multiplication is: " <<mul<<endl<< "Division is: " << div << endl;
}

int main ()
{
    int a, b;
    cout<<"Enter Two Number: "<<endl;
    cin >> a >> b;
    sumSubtraction ( a, b);
    mulDiv ( a, b);
}