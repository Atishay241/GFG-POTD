/*

Author : Atishay Gupta
Date : 01/01/2024
Problem : Array Pair Sum Divisibility Problem
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n%2==1) return 0;
        unordered_map<int,int> mp;
        for(auto it: nums){
            int rem = it%k;
            mp[rem]++;
        }
        int x = mp[0];
        if(x%2!=0) return 0;
        int i = 1 , j = k-1;
        while(i<=j){
            if(i==j){
                if(mp[i]%2==1) return 0;
            }
            if(mp[i]!=mp[j]) return 0;
            i++ , j--;
        }
        
        return 1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends