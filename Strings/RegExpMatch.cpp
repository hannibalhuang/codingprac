/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 20, 2013, 3:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "assert.h"

using namespace std;

/*
 * Implement regular expression matching with support for ‘.’ and ‘*’
 */

bool isMatch(const char *s, const char *p) {
    assert(s && p);
    if (*p == '\0') return *s == '\0';

    // next char is not '*': must match current character
    if (*(p+1) != '*') {
      assert(*p != '*');
      return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    }
    // next char is '*'
    while ((*p == *s) || (*p == '.' && *s != '\0')) {
      if (isMatch(s, p+2)) return true;
      s++;
    }
    return isMatch(s, p+2);
}


int main(int argc, char** argv) {

    return 0;
}

