#include<iostream>
using namespace std;
class number
{
public:

    int factorial(int n);

};
int number::factorial(int n)
{
    int fact=1,i;
    for(i=1; i<=n; i++)
    {
        fact=fact*i;

    }
    cout<<"factorial of "<< n <<"is "<<fact<<endl;
    return 0;

}

int main()
{
    number n1;
    cout<<n1.factorial(5);
}
