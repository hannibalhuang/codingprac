/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 11:24 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

/*
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m+n)).
 */

#define MAX 1000
//#define RANDOM_INPUT
 
double MedianOfFour (int a, int b, int c, int d)
{
        int minValue = min (d, min (a, min (b,c) ) );
        int maxValue = max (d, max (a, max (b,c) ) );
        return (a + b + c + d - minValue - maxValue) / 2.0 ;
}
 
double MedianOfThree (int a, int b, int c)
{
        int minValue = min (a, min (b,c) ) ;
        int maxValue = max (a, max (b,c) ) ;
        return (a + b + c - minValue - maxValue);
}
 
//constraint : n <= m
double MedianSortedArrays (int A[MAX], int n, int B[MAX], int m)
{
        //base case # 1
        if ( n == 1 ) 
        {
                if ( m == 1 ) 
                        return (A[0] + B[0]) / 2.0; 
                if ( m % 2 == 1) 
                         return ( B[m/2] + MedianOfThree (A[0], B[m/2-1], B[m/2+1]) ) / 2.0 ;
                else 
                        return MedianOfThree ( A[0], B[m/2-1], B[m/2] );
        }
 
        //base case # 2
        if ( n == 2 ) 
        {
                if ( m == 2 )
                        return MedianOfFour (A[0], A[1], B[0], B[1]);
                if ( m % 2 == 1 )
                        return MedianOfThree ( B[m/2], min(A[0], B[m/2+1]), max (A[1], B[m/2-1]) ) ;
                else 
                        return MedianOfFour ( B[m/2-1], B[m/2], min(A[0], B[m/2+1]), max(A[1], B[m/2-2]) );
        }
 
 
        int minRemoved, idxA = n/2 , idxB = m/2 ;
 
        if ( A[idxA] < B[idxB]  )                                               
        {
                if ( n % 2 == 0 ) --idxA;       //for even number of elements --idxA points to lower median of A[]
                minRemoved = min ( idxA, m - idxB - 1) ;        
                return MedianSortedArrays ( A + minRemoved, n - minRemoved, B, m - minRemoved); 
        }
        else                                                                                    
        {
                if ( m % 2 == 0 ) --idxB;       //for even number of elements --idxB points to lower median of B[]
                minRemoved = min ( n - idxA - 1, idxB) ;        
                return MedianSortedArrays ( A, n - minRemoved, B + minRemoved, m - minRemoved); 
        }
 
}
 
int main()
{
        int N, M ;
        double median;
        int A[MAX], B[MAX] ;
        
        
        cin >> N >> M;
 
#ifdef RANDOM_INPUT
        srand ( time(NULL) );
        for(int i = 0; i < N; i++)  A[i] = rand() % 10000 ;
#endif
 
#ifndef RANDOM_INPUT
        for(int x, i = 0; i < N && cin >> x; i++)  A[i] = x;
#endif
        sort ( A, A+N );
 
#ifdef RANDOM_INPUT
        for(int i = 0; i < M; i++)  B[i] = rand() % 10000 ;
#endif
#ifndef RANDOM_INPUT
        for(int x, i = 0; i < M && cin >> x; i++)  B[i] = x;
#endif
        sort (B, B+M );
 
        if ( N <= M )
                median = MedianSortedArrays (A, N, B, M) ;
        else
                median = MedianSortedArrays (B, M, A, N) ;
 
        cout << "median : " << median << endl;
        
        //verfication 
        vector <int> c (A, A+N );
        double verifiedMedian;
        c.insert (c.end(), B, B+M );
        sort ( c.begin(), c.end() ) ;
        int sz = c.size();
        if ( sz % 2 == 1 )
                verifiedMedian = c [sz/2] ;
        else 
                verifiedMedian =  ( c[sz/2] + c[sz/2 - 1]) / 2.0;
        cout << "VERIFIED MEDIAN : " << verifiedMedian << endl;
        
        assert (median == verifiedMedian); 
        //verification end
 
        return 0;
}
