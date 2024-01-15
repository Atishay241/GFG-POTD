/*

Author : Atishay Gupta
Date : 15/01/2024
Problem : Grinding Geek
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/grinding-geek/1

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int rec(int i ,int n, int total, vector<int> &cost,vector<vector<int>> &dp){
        if(i==n) return 0;
        
        if(total<=0) return 0;
        if(dp[i][total]!=-1) return dp[i][total];
        
        int notpick = rec(i+1,n,total,cost,dp);
        int pick = 0;
        if(cost[i]<=total){
            pick = 1 + rec(i+1 , n , total - cost[i] + (cost[i] * 9)/10 , cost , dp);
        }
        
        return dp[i][total] = max(pick , notpick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>> dp(n+1 , vector<int> (total+1,-1));
        return rec(0,n,total,cost,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends