/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 8:58 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */



int main(int argc, char** argv) {

    int T, n, k;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> k;
        cout << "Case #" << i + 1 << ": ";
        if (((1 << (n-1)) ^ (k & ((1 << n)-1))) == ((1 << (n-1))-1)) {
          cout << "ON\n";
        } else {
          cout << "OFF\n";
        }
    }
    return 0;
}

