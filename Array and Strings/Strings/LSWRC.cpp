/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 20, 2013, 8:30 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

/*
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for “abcabcbb” is “abc”, 
 * which the length is 3. For “bbbbb” the longest substring is “b”, with the length of 1.
 */

int lengthOfLongestSubstringWR(string s)
{
    int n = s.length();
    int i = 0, j = 0;
    int maxLen = 0;
    bool exist[256] = { false };
    while (j < n) {
      if (exist[s[j]]) {
        maxLen = max(maxLen, j-i);
        while (s[i] != s[j]) {
          exist[s[i]] = false;
          i++;
        }
        i++;
        j++;
      } else {
        exist[s[j]] = true;
        j++;
      }
    }
    maxLen = max(maxLen, n-i);  //don't forget to add for the last time
    return maxLen;
}

int main(int argc, char** argv) {

    string input = "";

    // How to get a string/sentence with spaces
    cout << "Please enter a valid string (without spaces):\n>";
    getline(cin, input);
    cout << "You entered: " << input << endl;
    cout << "The max length is : " << lengthOfLongestSubstringWR(input) << endl;
    
    return 0;
}

