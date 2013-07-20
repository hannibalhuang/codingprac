/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 25, 2013, 3:37 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Given only putchar (no sprintf, itoa, etc.) write a routine putlong 
 * that prints out an unsigned long in decimal.
 */

void putlong(unsigned long n) {
  if (n < 10) {
    putchar(n + '0');
    return;
  }
  putlong(n / 10);
  putchar(n % 10 + '0');
}

/*Print a string in reverse order.*/

void printReverse(const char *str) {
  if (!*str)
    return;
  printReverse(str + 1);
  putchar(*str);
}

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

