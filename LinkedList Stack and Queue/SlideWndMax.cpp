/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 11:10 PM
 */

#include <cstdlib>
#include "queue"
using namespace std;

/*
 * A long array A[] is given to you. There is a sliding window of size w 
 * which is moving from the very left of the array to the very right. 
 * You can only see the w numbers in the window. Each time the sliding window 
 * moves rightwards by one position.
 * Input: A long array A[], and a window width w
 * Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
 */

void maxSlidingWindow(int A[], int n, int w, int B[]) {
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];
}

int main(int argc, char** argv) {

    return 0;
}

