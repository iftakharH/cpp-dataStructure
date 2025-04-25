#include <iostream>
using namespace std;

int main()
{
    int i, r, j, n=5;

    for (i=0; i<=n; i++)
    {
        for (j=0; j<i; j++)
        {
            cout << i<<" ";
        }
        cout << endl;
    }
}
