/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 20, 2013, 11:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAX_DIGITS_INT 10
/*
 * signed int/ string conversion
 */

int StrToInt (char str[])
{
    int i = 0, isNeg = 0, num = 0;
    
    if(str[0] == '-')
    {
        isNeg = 1;
        i = 1;
    }
    
    while(str[i])
    {
        num *= 10;
        num += (str[i++] - '0');
    }
    
    if(isNeg)
        num *= -1;
    
    return num;
}

void IntToStr(int num, char str[])
{
    int i = 0, j = 0, isNeg = 0;
    
    /*Buffer big enough for largest int, -sign and NUL*/
    char temp[MAX_DIGITS_INT + 2];
    
    /*Check if neg number*/
    if(num < 0)
    {
        num *= -1;
        isNeg = 1;
    }
    
    /*Fill buffer with digit characters in reverse order*/
    do {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }while (num);
    
    if(isNeg)
        temp[i++] = '-';
    
    /*Reverse the characters*/
    while(i > 0)
        str[j++] = temp[--i];
    
    /*NUL terminate the string*/
    str[j] = '\0';
}

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

