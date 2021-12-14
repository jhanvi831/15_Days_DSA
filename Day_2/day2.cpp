/*

SEARCHING AND SORTING ALGORITHMS

Problem:
Searching in an array where adjacent differ by at most k

Difficulty Level : Easy

Explanation:
A step array is an array of integers where each element has a 
difference of at most k with its neighbor. Given a key x, we 
need to find the index value of x if multiple-element exist to 
return the first occurrence of the key.

Examples: 
 
Input : arr[] = {4, 5, 6, 7, 6}
           k = 1
           x = 6
Output : 2
The first index of 6 is 2.

Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5

gfg link: https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

*/

//code

#include<bits/stdc++.h>
using namespace std;

int adjacentSearch(int a[], int n, int k, int x){
    int i=0;
    while(i<n){
        if(a[i]==x)
            return i;
        i = i + max(1, abs( (x-a[i])/k) );
    }
    return -1;
}

int main(){
    int a[] = {2,4,5,6,7,8};
    int n = 6;
    int k = 2;
    int x = 7;
    
    cout<< adjacentSearch(a, n, k, x) <<endl;
    
    return 0;
}

