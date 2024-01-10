/*

Author : Atishay Gupta
Date : 11/01/2024
Problem : Remove K Digits
Difficulty : Medium
Problem Link :https://www.geeksforgeeks.org/problems/remove-k-digits/1

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        for(auto it: s){
            while(!st.empty() && k>0 && st.top() > it){
                st.pop();
                k--;
            }
            st.push(it);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        
        
        reverse(ans.begin() , ans.end());
        int i = 0;
        while(ans[i]=='0') i++;
        
        ans = ans.substr(i);
        
        
        int n = ans.length();
        
        if(k>=n) return "0";
        
        ans = ans.substr(0 , n-k);
        
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
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends