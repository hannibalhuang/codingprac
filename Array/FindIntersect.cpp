/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 2:06 PM
 */

#include <cstdlib>
#include <vector>

using namespace std;

/*
 * Find the intersection of two sorted arrays.
 */

vector<int> findIntersection(vector<int> A, vector<int> B) {
  vector<int> intersection;
  int n1 = A.size();
  int n2 = B.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (A[i] > B[j]) {
      j++;
    } else if (B[j] > A[i]) {
      i++;
    } else {
      intersection.push_back(A[i]);
      i++;
      j++;
    }
  }
  return intersection;
}

int main(int argc, char** argv) {

    return 0;
}

