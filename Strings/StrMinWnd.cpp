/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 7:21 PM
 */

#include <cstdlib>
#include "limits.h"
#include "string.h"

using namespace std;

/*
 * Given a set T of characters and a string S, find the minimum window in S 
 * which will contain all the characters in T in complexity O(n).
 */

// Returns false if no valid window is found. Else returns 
// true and updates minWindowBegin and minWindowEnd with the 
// starting and ending position of the minimum window.
bool minWindow(const char* S, const char *T, 
               int &minWindowBegin, int &minWindowEnd) {
  int sLen = strlen(S);
  int tLen = strlen(T);
  int needToFind[256] = {0};
 
  for (int i = 0; i < tLen; i++)
    needToFind[T[i]]++;
 
  int hasFound[256] = {0};
  int minWindowLen = INT_MAX;
  int count = 0;
  for (int begin = 0, end = 0; end < sLen; end++) {
    // skip characters not in T
    if (needToFind[S[end]] == 0) continue;
    hasFound[S[end]]++;
    if (hasFound[S[end]] <= needToFind[S[end]])
      count++;
 
    // if window constraint is satisfied
    if (count == tLen) {
      // advance begin index as far right as possible,
      // stop when advancing breaks window constraint.
      while (needToFind[S[begin]] == 0 ||
            hasFound[S[begin]] > needToFind[S[begin]]) {
        if (hasFound[S[begin]] > needToFind[S[begin]])
          hasFound[S[begin]]--;
        begin++;
      }
 
      // update minWindow if a minimum length is met
      int windowLen = end - begin + 1;
      if (windowLen < minWindowLen) {
        minWindowBegin = begin;
        minWindowEnd = end;
        minWindowLen = windowLen;
      } // end if
    } // end if
  } // end for
 
  return (count == tLen) ? true : false;
}

int main(int argc, char** argv) {

    return 0;
}

