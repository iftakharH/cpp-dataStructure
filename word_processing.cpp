// word_processing.cpp
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to count the number of words in a string
int countWords(const string& str) {
    int wordCount = 0;
    bool inWord = false;
    for (char c : str) {
        if (isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }
    return wordCount;
}

// Function to convert a string to uppercase
string toUppercase(string str) {
    for (char& c : str) {
        c = toupper(c);
    }
    return str;
}

// Function to convert a string to lowercase
string toLowercase(string str) {
    for (char& c : str) {
        c = tolower(c);
    }
    return str;
}

// Function to reverse a string
string reverseString(string str) {
    string reversedStr = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }
    return reversedStr;
}

//Function to check if a string is a palindrome.
bool isPalindrome(const string& str){
    string temp = "";
    for(char c : str){
        if(isalnum(c)){
            temp += tolower(c);
        }
    }

    string reversedTemp = reverseString(temp);
    return temp == reversedTemp;
}

int main() {
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "Word count: " << countWords(inputString) << endl;
    cout << "Uppercase: " << toUppercase(inputString) << endl;
    cout << "Lowercase: " << toLowercase(inputString) << endl;
    cout << "Reversed: " << reverseString(inputString) << endl;
    cout << "Is Palindrome: " << (isPalindrome(inputString) ? "Yes" : "No") << endl;

    return 0;
}