/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 7:06 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Given the sequence S1 = {a,b,c,d,…,x,y,z,aa,ab,ac…. } and given that this 
 * sequence corresponds (term for term) to the sequence S2 = {0,1,2,3,….}. 
 * Write code to convert an element of S2 to the corresponding element of S1.
 */

void numToStrHelper(int n) {
  if (n == 0) return;
  numToStrHelper((n-1)/26);
  cout << (char)('a'+(n-1)%26);
}
 
void numTostr(int n) {
  numToStrHelper(n/26);
  cout << (char)('a'+n%26);
}


int main(int argc, char** argv) {

    return 0;
}

