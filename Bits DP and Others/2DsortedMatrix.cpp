/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 11:52 AM
 */

#include <cstdlib>

using namespace std;
#define N_MAX 10

/*
 * Write an efficient algorithm that searches for a value in an n x m table 
 * (two-dimensional array). This table is sorted along the rows and columns 
 * — that is, Table[i][j] ≤ Table[i][j + 1], Table[i][j] ≤ Table[i + 1][j]
 */

bool binPart(int mat[][N_MAX], int M, int N, int target, int l, int u, int r, int d, int &targetRow, int &targetCol) {
  if (l > r || u > d) return false;
  if (target < mat[u][l] || target > mat[d][r]) return false;
  int mid = l + (r-l)/2;
  int row = u;
  while (row <= d && mat[row][mid] <= target) {
    if (mat[row][mid] == target) {
      targetRow = row;
      targetCol = mid;
      return true;
    }
    row++;
  }
  return binPart(mat, M, N, target, mid+1, u, r, row-1, targetRow, targetCol) ||
         binPart(mat, M, N, target, l, row, mid-1, d, targetRow, targetCol);
}
 
bool binPart(int mat[][N_MAX], int N, int target, int &row, int &col) {
  return binPart(mat, N, N, target, 0, 0, N-1, N-1, row, col);
}

int main(int argc, char** argv) {

    return 0;
}

