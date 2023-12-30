/*

Author : Atishay Gupta
Date : 31/12/2023
Problem : New Year Resolution
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/good-by-2023/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int dp[367][2025];
    
    int rec(int idx , int n,int coins[],int sum){
        // cout<<sum<<"\n";
        if(sum!=0 && (sum %20==0 || sum%24==0 || sum==2024)) return 1;
        if(idx==n) return 0;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        int pick = rec(idx+1,n,coins,sum+coins[idx]);
        
        if(pick==1) return dp[idx][sum] = 1;
        
        int notpick = rec(idx+1,n,coins,sum);
        
        return dp[idx][sum] =  notpick ;
        
    }
    int isPossible(int N , int coins[]) 
    {
        memset(dp,-1,sizeof(dp));
        return rec(0,N,coins,0);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends