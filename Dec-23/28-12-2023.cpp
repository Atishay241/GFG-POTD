/*

Author : Atishay Gupta
Date : 28/12/2023
Problem : Wildcard string matching
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool check(string &S1, int i , int n) {
        for (int j = i; j < n; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }
    bool rec(int i , int j,int n,int m,string &wild, string &pattern,vector<vector<int>> &dp){
        if(j==m && i==n){
            return 1;
        }
        if(j==m) return check(wild , i , n);
        if(i==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(wild[i]==pattern[j] || wild[i]=='?'){
            return  dp[i][j] = rec(i+1,j+1,n,m,wild,pattern,dp);
        }
        if(wild[i]=='*'){
            return  dp[i][j] = rec(i+1,j , n,m,wild,pattern,dp) || rec(i,j+1,n,m,wild,pattern,dp);
        }
        
        return  dp[i][j] = 0;
        
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        return rec(0,0,n,m,wild , pattern , dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends