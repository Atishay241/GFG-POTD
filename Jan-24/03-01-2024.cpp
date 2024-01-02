/*

Author : Atishay Gupta
Date : 03/01/2024
Problem : Smallest window containing 0, 1 and 2
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
       int a = -1 , b = -1 , c = -1;
        int ans = INT_MAX,n = s.size();
        int i = 0 , j = 0;
       
        while(i<n && j<n){
            
            if(s[j]=='0') a = j;
            else if(s[j]=='1') b = j;
            else c = j;
            
            // cout<<a<<" "<<b<<" "<<c<<"\n";
            
            if(a!=-1 && b!=-1 && c!=-1){
                if(a<b && a<c){
                    i = a;
                    a=-1;
                }
                else if(b<a && b<c){
                    i = b;
                    b = -1;
                }
                else{
                    i = c;
                    c=-1;
                }
                ans = min(ans , j-i+1);
                
            }
            j++;
        }
        
        if(ans==INT_MAX) ans = -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends