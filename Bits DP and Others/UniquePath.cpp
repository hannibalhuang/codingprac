/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 2:25 PM
 */

#include <cstdlib>

using namespace std;

/*
 * A robot is located at the top-left corner of a m x n grid (marked ‘Start’ 
 * in the diagram below). The robot can only move either down or right at any 
 * point in time. The robot is trying to reach the bottom-right corner of the 
 * grid (marked ‘Finish’ in the diagram below). How many possible unique paths are there?
 */

const int M_MAX = 100;
const int N_MAX = 100;
 
int dp(int m, int n) {
  int mat[M_MAX+2][N_MAX+2] = {0};
  mat[m][n+1] = 1;
 
  for (int r = m; r >= 1; r--)
    for (int c = n; c >= 1; c--)
      mat[r][c] = mat[r+1][c] + mat[r][c+1];
 
  return mat[1][1];
}


int main(int argc, char** argv) {

    return 0;
}

