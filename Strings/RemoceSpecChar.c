/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 20, 2013, 11:10 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Delete characters in a string
 */

void RemoveChars(char str[], char remove[])
{
    int src, dst, removeArray[256];
    
    for(src = 0;src < 256;src++)
    {
        removeArray[src] = 0;
    }
    
    src = 0;
    while (remove[src])
    {
        removeArray[remove[src]] = 1;
        src++;
    }
    
    src = dst = 0;
    do {
        if(!removeArray[str[src]])
        {
            str[dst++] = str[src];
        }
    }while(str[src++]);
}

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

