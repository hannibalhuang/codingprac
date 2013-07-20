/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 19, 2013, 7:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 * Check if a number is palindrome
 */
bool isPalindrome(int x)
{
    int div = 1;
    if(x < 0)
    {
        cout << "You've entered a negative number, please try a positive one. " << endl;
        return false;
    }
        
    else if (x == 0)
        return true;
    
    while (x / div >= 10)
    {
        div *= 10;
    }
    
    while (x != 0)
    {
        int l = x / div;
        int r = x % 10;
        if (l != r)
            return false;
        x = (x % div) / 10; // eliminate the first and the last digit
        div /= 100;
    }
    return true;    
}

int main(int argc, char** argv) {
    
    string input = "";
    int myNumber;
    
    while (true)
    {
        cout << "Please enter a valid number : " << endl;
        getline(cin,input);
        stringstream myStream(input);
        if (myStream >> myNumber)
            break;
        cout << "Invalid number, please try again" << endl;
    }
    cout << "You entered: " << myNumber << endl;
    
    if(isPalindrome(myNumber))
        cout << "Your number is palindrome" << endl;
    else
        cout << "Your number is not palindrome"<< endl;

    return 0;
}

