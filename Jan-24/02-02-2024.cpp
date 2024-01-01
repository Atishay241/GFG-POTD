/*

Author : Atishay Gupta
Date : 02/01/2024
Problem : Largest Sum Subarray of Size at least K
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

*/

//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
   long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int sum=0,ans=LLONG_MIN,temp=0;
    for(int i=0;i<k;i++) sum+=a[i];
    ans=max(ans,sum);
    for(int i=k;i<n;i++){
        temp+=a[i-k];
        sum+=a[i];
        ans=max(ans,sum);
        if(temp<0){
            sum=sum- temp;
            ans=max(ans,sum);
            temp=0;
        }
    }
    return ans;
    
}
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends