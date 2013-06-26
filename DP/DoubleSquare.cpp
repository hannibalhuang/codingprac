/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 10:45 PM
 */

#include <cstdlib>

using namespace std;

/*
 * A double-square number is an integer X which can be expressed as 
 * the sum of two perfect squares. For example, 10 is a double-square 
 * because 10 = 32 + 12. Your task in this problem is, given X, 
 * determine the number of ways in which it can be written as the sum of two squares. 
 */

int doubleSquare(unsigned int m) {
  int p = sqrt((double)m / 2.0);
  int total = 0;
  for (int i = 0; i <= p; i++) {
    double j = sqrt((double)m - i*i);
    if (j - (int)j == 0.0)   // might have precision issue, 
      total++;  // can be resolved using |j-(int)j| == delta
  }
  return total;
}

int main(int argc, char** argv) {

    return 0;
}

