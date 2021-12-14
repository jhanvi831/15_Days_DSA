/*

SEARCHING AND SORTING ALGORITHMS

Problem name: Find All Four Sum Numbers 

Difficulty: Medium

Statement:
Given an array of integers and another number. 
Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.

gfg link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

*/

//code
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum (vector<int> &arr, int k) {
     
        vector <vector<int> > ans;
        set <vector<int>> t;
      
        //sort the vector array
        sort(arr.begin(), arr.end());
     
        for(int i = 0; i < arr.size()-3; i++){
            for(int j = i+1; j < arr.size()-2; j++){
                int left = j+1;
                int right = arr.size()-1;
             
                while(left<right){
                if(arr[i] + arr[j] + arr[left] + arr[right] == k){
                    t.insert({arr[i],arr[j],arr[left], arr[right]});
                    left++;
                    right--;
                } 
                else if(arr[i] + arr[j] + arr[left] + arr[right] < k){
                    left++;
                }
                else{
                    right--;
                }
              } 
           }
        }
        for(auto i: t){
            ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} 
