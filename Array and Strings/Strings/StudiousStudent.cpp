/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 11:03 PM
 */

#include <cstdlib>

using namespace std;

/*
 * One game you’ve come up with is to see how you can concatenate the words to 
 * generate the lexicographically lowest possible string.
 */

bool compareSort(const string &s1, const string &s2) {
  return s1 + s2 < s2 + s1;
}

int main(int argc, char** argv) {

    string words[10];
    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++) {
      
        cin >> M;

        for (int j = 0; j < M; j++)
          cin >> words[j];

        sort(words, words+M, compareSort);

        for (int j = 0; j < M; j++)
          cout << words[j];

        cout << endl;
    }
    return 0;
}

