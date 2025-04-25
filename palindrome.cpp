#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, temp;
    int i = 0, j;

    cout << "Enter a Number to check for Palindrome: ";
    cin >> str;

    temp = str;

    j = str.length() - 1;

    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }

    if (temp == str)
    {
        cout << "The Number is a palindrome." << endl;
    }
    else
    {
        cout << "The Number is not a palindrome." << endl;
    }

    return 0;
}
