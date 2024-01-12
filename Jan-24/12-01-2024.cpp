/*

Author : Atishay Gupta
Date : 12/01/2024
Problem : Reverse First k elements of Queue
Difficulty : Easy
Problem Link :https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        int r = k;
        int sz = q.size();
        vector<int> arr;
        while(!q.empty() && k>0){
            arr.push_back(q.front());
            q.pop();
            k--;
        }
        int i = r-1;
        while(i>=0){
            q.push(arr[i--]);
        }
        int t = sz - r;
        
        while(t--){
            int a = q.front();
            q.pop();
            q.push(a);
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends