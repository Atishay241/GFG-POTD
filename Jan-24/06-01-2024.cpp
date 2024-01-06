/*

Author : Atishay Gupta
Date : 05/01/2024
Problem : Techfest and Queue
Difficulty : Medium
Problem Link :https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1

*/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int> arr(b+1);
	    for(int i=1;i<=b;i++) arr[i] = i;
	    
	    for(int i=2;i*i<=b;i++){
	        if(arr[i]==i){
	            for(int j = i*i;j<=b;j+=i){
	                if(arr[j]==j) arr[j] = i;
	            }
	        }
	    }
	    
	    int ans = 0;
	    int i = a;
	    while(i<=b){
	        int n = i;
	        while(n>1){
	            int x = arr[n];
	            n = n/x;
	            ans++;
	        }
	        i++;
	    }
	    
	    return ans;
	}
};

// 17 = 1 , 18 = 3 , 19 = 1 , 20 = 3 , 21 = 2 , 22 = 2 , 23 = 1 , 24 = 4

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends