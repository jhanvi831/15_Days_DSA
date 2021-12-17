/*

PROBLEM: Allocate minimum number of pages

DIFFICULTY: Hard 

STATEMENT: You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. There can be many ways
or permutations to do so. In each permutation, one of the M students will be allocated
the maximum number of pages. Out of all these permutations, the task is to find that 
particular permutation in which the maximum number of pages allocated to a student is 
minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at 
least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous 
order (see the explanation for better understanding).

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:
113

Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:
32

Explanation:
Allocation is done as 
{15,17} and {20}

gfg link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

*/

//code
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool check(int a[], int n, int mid, int m){
        int sum = 0;
        int students = 1;
        
        for(int i=0; i<n; i++){
            if(a[i]>mid)//that one student cannot read the book since it exceeds the no of pages i.e. mid
                return false;
            if(sum+a[i]>mid){
                students++; //next students is given the current book
                sum=a[i];
                if(students>m) //exceeds total no of students
                    return false;
            }
            else
                sum+=a[i];
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        int lowerb = 0;
        int s = 0;
        int ans = -1;
        
        for(int i=0; i<n; i++)
            s+=a[i];
            
        int upperb = s;
        while(lowerb <= upperb){
            int mid = (lowerb + upperb)/2;
            if(check(a,n,mid,m)){
                ans=mid;
                upperb = mid - 1;
            }
            else{
                lowerb = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}