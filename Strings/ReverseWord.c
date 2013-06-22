/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 20, 2013, 11:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*
 * Reverse words in a string. Assume that all words are space delimited and treat
 * punctuation the same as letters
 */

void ReverseString(char str[], int start, int end)
{
    char temp;
    while(end > start)
    {
        /*Exchange characters*/
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        /*Move indices towards middle*/
        start++;
        end--;
    }
    return;
}

void ReverseWords(char str[])
{
    int start = 0, end = 0, length;
    length = strlen(str);
    
    ReverseString(str, start, length - 1);
    
    while(end < length)
    {
        if(str[end] != ' ')
        {
            /*Save position of the beginning of the word*/
            start = end;
            
            /*Scan to next non-word character*/
            while(end < length && str[end] != ' ')
                end++;
            
            /*Back up to end of word*/
            end--;
            
            /*Reverse word*/
            ReverseString(str, start, end);
        }
        end++; /*Advance to next token*/
    }
    return;
}

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

