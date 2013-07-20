/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 20, 2013, 6:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "hashtable.h"

using namespace std;

#define NO_OF_CHARS 256

/*
 * Find the first non-repeated character in a string.
 */

/* Returns an array of size 256 containg count
   of characters in the passed char array */
   
int *getCharCountArray(char *str)
{
   int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
   int i;
   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;
   return count;
}
 
/* The function returns index of first non-repeating
   character in a string. If all characters are repeating
   then reurns -1 */
int firstNonRepeating(char *str)
{
  int *count = getCharCountArray(str);
  int index = -1, i;
 
  for (i = 0; *(str+i);  i++)
  {
    if(count[*(str+i)] == 1)
    {
      index = i;
      break;
    }  
  } 
  return index;
}
 
/* Driver program to test above function */
int main()
{
  char str[] = "geeksforgeeks";
  int index =  firstNonRepeating(str);
  if(index == -1) 
    printf("Either all characters are repeating or string is empty");
  else
   printf("First non-repeating character is %c", str[index]);
  getchar();
  return 0;
}
