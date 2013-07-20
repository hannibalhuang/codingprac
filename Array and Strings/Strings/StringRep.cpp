/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 20, 2013, 3:35 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * Replace all occurrence of the given pattern to ‘X’.
 * For example, given that the pattern=”abc”, replace “abcdeffdfegabcabc” 
 * with “XdeffdfegX”. Note that multiple occurrences of abc’s that are contiguous 
 * will be replaced with only one ‘X’.
 */

bool isMatch(char *str, const char* pattern) {
  while (*pattern)
    if (*str++ != *pattern++)
      return false;
  return true;
}
 
void replace(char str[], const char *pattern) {
  if (str == NULL || pattern == NULL) return;
  char *pSlow = str, *pFast = str;
  int pLen = char_traits<char>::length(pattern); //C++ version of strlen
  while (*pFast != '\0') {
    bool matched = false;
    while (isMatch(pFast, pattern)) {
      matched = true;
      pFast += pLen;
    }
    if (matched)
      *pSlow++ = 'X';
    // tricky case to handle here:
    // pFast might be pointing to '\0',
    // and you don't want to increment past it
    if (*pFast != '\0')
      *pSlow++ = *pFast++;  // *p++ = (*p)++
  }
  // don't forget to add a null character at the end!
  *pSlow = '\0';
}

int main(int argc, char** argv) {

    return 0;
}

