/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 3:16 PM
 */

#include <cstdlib>
#include "limits.h"

using namespace std;

/*
 * Given an array of non-negative integers A and a positive integer k, we want to:
 * Divide A into k or fewer partitions,
 * such that the maximum sum over all the partitions is minimized.
 */

const int MAX_N = 100;
int findMax(int A[], int n, int k) {
  int M[MAX_N+1][MAX_N+1] = {0};
  int cum[MAX_N+1] = {0};
  for (int i = 1; i <= n; i++)
    cum[i] = cum[i-1] + A[i-1];
 
  for (int i = 1; i <= n; i++)
    M[i][1] = cum[i];
  for (int i = 1; i <= k; i++)
    M[1][i] = A[0];
 
  for (int i = 2; i <= k; i++) {
    for (int j = 2; j <= n; j++) {
      int best = INT_MAX;
      for (int p = 1; p <= j; p++) {
        best = min(best, max(M[p][i-1], cum[j]-cum[p]));
      }
      M[j][i] = best;
    }
  }
  return M[n][k];
}

int main(int argc, char** argv) {

    return 0;
}

