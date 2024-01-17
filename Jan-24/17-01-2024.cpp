/*

Author : Atishay Gupta
Date : 17/01/2024
Problem : All Unique Permutations of an array
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void rec(int i, int n, vector<int> &arr,vector<int> a , set<vector<int>> &ans){
        if(i==n){
            ans.insert(a);
            return;
        }
        for(int idx = i;idx<n;idx++){
            if(idx==i || arr[idx]!=arr[i]){
                swap(arr[i] , arr[idx]);
                a.push_back(arr[i]);
                rec(i+1 , n , arr , a ,ans);
                a.pop_back();
                swap(arr[i] , arr[idx]);
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> s;
        vector<int> a;
        rec(0 , n , arr , a , s);
        
        vector<vector<int>> ans(s.begin() , s.end());
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends