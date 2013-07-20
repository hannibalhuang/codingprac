/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 20, 2013, 4:06 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Write C code to implement the strstr (Search for a substring) function. 
 * Do not use any system library such as strlen.
 */

char* StrStr(const char *str, const char *target) {
    
    if (!*target) return str;
    char *p1 = (char*)str, *p2 = (char*)target;
    char *p1Adv = (char*)str;
    while (*++p2)
      p1Adv++;
    while (*p1Adv) {
      char *p1Begin = p1;
      p2 = (char*)target;
      while (*p1 && *p2 && *p1 == *p2) {
        p1++;
        p2++;
      }
      if (!*p2)
        return p1Begin;
      p1 = p1Begin + 1;
      p1Adv++;
    }
    return NULL;
}


int main(int argc, char** argv) {

    
    return (EXIT_SUCCESS);
}

