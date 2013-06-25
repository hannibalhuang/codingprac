/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 1:58 PM
 */

#include <cstdlib>

using namespace std;

/*
 * There is an array A[N] of N numbers. You have to compose an array Output[N] 
 * such that Output[i] will be equal to multiplication of all the elements of A[N] 
 * except A[i]. Solve it without division operator and in O(n).
 */

void array_multiplication(int A[], int OUTPUT[], int n) {
  int left = 1;
  int right = 1;
  for (int i = 0; i < n; i++)
    OUTPUT[i] = 1;
  for (int i = 0; i < n; i++) {
    OUTPUT[i] *= left;
    OUTPUT[n - 1 - i] *= right;
    left *= A[i];
    right *= A[n - 1 - i];
  }
}


int main(int argc, char** argv) {

    return 0;
}

