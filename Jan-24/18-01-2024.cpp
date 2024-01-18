/*

Author : Atishay Gupta
Date : 18/01/2024
Problem : Water the plants
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/water-the-plants--170646/1

*/

//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            if(gallery[i]>=0){
                arr.push_back({max(0 , i-gallery[i]) , i + gallery[i]});
            }
        }
        sort(arr.begin() , arr.end());
        
        if(arr[0].first!=0) return -1;
        int sz = arr.size();
        int i = 0 , maxi = 0;
        
        
        while(arr[i].first==0 && i<sz) maxi = max(arr[i].second,maxi) , i++;
        
        int ans = 1;
        
        int start = maxi+1;
        while(start<n && i<sz){
            int mx = -1;
            while(arr[i].first<=start && i<sz){
                mx = max(arr[i].second, mx);
                i++;
            }
            if(mx<start) return -1;
            start = mx + 1;
            ans++;
        }
        
        if(start>=n)    return ans;
        return -1;
    
        
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends