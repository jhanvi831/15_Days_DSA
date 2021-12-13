/* 

Problem name: Find missing and Repeating
Platform: Geekforgeeks

Statement:
Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number
'B' occurs twice in array. Find these two numbers.

Explanation: 
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

geekforgeeks link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

*/


//code:
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        for(auto &i: m){
            if(i.second==2){
                ans.push_back(i.first);
                break;
            }
        }
        for(int i=1; i<=n; i++){
            if(!m[i]){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} 
