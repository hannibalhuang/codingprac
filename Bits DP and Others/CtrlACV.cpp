/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 10:58 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Imagine you have a special keyboard with the following keys:
 * A, Ctrl+A, Ctrl+C, Ctrl+V
 * where CTRL+A, CTRL+C, CTRL+V each acts as one function key
 * for “Select All”, “Copy”, and “Paste” operations respectively.
 * If you can only press the keyboard for N times (with the above four keys), 
 * please write a program to produce maximum numbers of A. If possible, 
 * please also print out the sequence of keys.
 */

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
 
int findMaxK(int n) {
    int power = 2;
    double max = 0.0;
    int maxK = 0;
    while (n > 0) {
        n -= 2;
        double t = (double)n/power;
        double r = pow(t, (double)power);
        if (r > max) {
            maxK = power;
            max = r;
        }
        power++;
    }
    return maxK;
}
 
unsigned int f(int n) {
    if (n <= 7) return n;
    int k = findMaxK(n);
 
    int sum = n - 2*(k-1);
    unsigned int mul = 1;
    while (k > 0) {
        int avg = sum/k;
        mul *= avg;
        k--;
        sum -= avg;
    }
 
    assert(sum == 0);
 
    return mul;
}


int main(int argc, char** argv) {

    return 0;
}

