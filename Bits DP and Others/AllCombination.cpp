/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 8:26 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * Given a target number, and a series of candidate numbers, 
 * print out all combinations, so that the sum of candidate numbers 
 * equals to the target.
 * Here order is not important, so don’t print the duplicated combination.
 */

void printSum(int candidates[], int index[], int n) {
  for (int i = 1; i <= n; i++)
    cout << candidates[index[i]] << ((i == n) ? "" : "+");
  cout << endl;
}
 
void solve(int target, int sum, int candidates[], int sz, int index[], int n) {
  if (sum > target)
    return;
  if (sum == target)
    printSum(candidates, index, n);
 
  for (int i = index[n]; i < sz; i++) {
    index[n+1] = i;
    solve(target, sum + candidates[i], candidates, sz, index, n+1);
  }
}
 
void solve(int target, int candidates[], int sz) {
  int index[10000];
  index[0] = 0;
  solve(target, 0, candidates, sz, index, 0);
}

int main(int argc, char** argv) {

    return 0;
}

