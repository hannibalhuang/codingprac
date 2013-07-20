/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 9:07 AM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */

bool isPow2(unsigned int x)
{
    return x && !(x & (x-1));
}

//Write a function that takes an unsigned integer and 
//returns the number of ’1′ bits it has. 

int number_of_ones(unsigned int x) {
  int total_ones = 0;
  while (x != 0) {
    x = x & (x-1);
    total_ones++;
  }
  return total_ones;
}

//Reverse bits of an unsigned integer.

typedef unsigned int uint;

uint swapBits(uint x, uint i, uint j) {
  uint lo = ((x >> i) & 1);
  uint hi = ((x >> j) & 1);
  if (lo ^ hi) {
    x ^= ((1U << i) | (1U << j));
  }
  return x;
}
 
uint reverseXor(uint x) {
  uint n = sizeof(x) * 8;
  for (uint i = 0; i < n/2; i++) {
    x = swapBits(x, i, n-i-1);
  }
  return x;
}


int main(int argc, char** argv) {

    return 0;
}

