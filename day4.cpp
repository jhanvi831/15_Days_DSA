/*

Problem: Product array puzzle 

Difficulty: Easy 

Statement: Given an array nums[] of size n, 
construct a Product Array P (of same size n) 
such that P[i] is equal to the product of 
all the elements of nums except nums[i].

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}

Output:
180 600 360 300 900

Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.

Example 2:

Input:
n = 2
nums[] = {12,0}

Output:
0 12

gfg link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

*/

//code:
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        
        vector<long long int> l(n), r(n), p(n);
        
        l[0]=1;
        r[n-1]=1;
        
        for(int i=1; i<n; i++){
            l[i] = l[i-1] * nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--){
            r[i] = r[i+1] * nums[i+1];
        }
        
        for(int i=0; i<n; i++){
            p[i] = l[i]*r[i];
        }
        return p;
    }
};

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        Solution obj;
        vec = obj.productExceptSelf(arr,n);   
        for(int i=0;i<n;i++)  {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}