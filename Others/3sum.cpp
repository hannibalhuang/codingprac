/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 4:17 PM
 */

#include <cstdlib>
#include "vector"
#include "set"
#include "algorithm"
using namespace std;

/*
 * Given a set S of n integers, are there elements a, b, c in S such that 
 * a + b + c = 0? Find all unique triplets in the set which gives the sum 
 * of zero.
 */

set<vector<int> > find_triplets(vector<int> arr) {
  sort(arr.begin(), arr.end());
  set<vector<int> > triplets;
  vector<int> triplet(3);
  int n = arr.size();
  for (int i = 0;i < n; i++) {
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      int sum_two = arr[i] + arr[j];
      if (sum_two + arr[k] < 0) {
        j++;
      } else if (sum_two + arr[k] > 0) {
        k--;
      } else {
        triplet[0] = arr[i];
        triplet[1] = arr[j];
        triplet[2] = arr[k];
        triplets.insert(triplet);
        j++;
        k--;
      }
    }
  }
  return triplets;
}


int main(int argc, char** argv) {

    return 0;
}

