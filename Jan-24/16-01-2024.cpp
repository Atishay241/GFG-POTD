/*

Author : Atishay Gupta
Date : 16/01/2024
Problem : Sequence of Sequence
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int rec(int m , int n , vector<vector<int>> &dp){
        if(n>m) return 0;
        if(n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        
        int ans1 = rec(m/2,n-1,dp);
        int ans2 = rec(m-1,n,dp);
        
        return dp[m][n] = ans1 + ans2;
    }
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>> dp(m+1 , vector<int>(n+1,-1));
        
        return rec(m,n,dp);
    }
};
// 1 2 4 8 = 5 + 3 + 1 3 7 14
// 4 

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends

