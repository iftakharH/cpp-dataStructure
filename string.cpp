#include<iostream>

using namespace std;
int main()
{
    string st;
    cout<<"Enter a string: ";
    getline(cin,st);
    cout<<"-------"<<endl;
    cout<<"The string is: "<<st<<endl;
    cout << st << endl;

    cout<<"Length of the string is: "<<st.length()<<endl;
    cout<<"Size of the string is: "<<st.size()<<endl;
    cout<<"Substring of the string is: "<<st.substr(3,5)<<endl;
    cout<<"Replace "<<st.replace(6,2,"yy")<<endl;
    cout<<"Erase "<<st.erase(3,5)<<endl;
    cout<<"Find "<<st.find("is")<<endl;
}