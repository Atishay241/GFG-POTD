/*

Author : Atishay Gupta
Date : 27/12/2023
Problem : Anti Diagonal Traversal of Matrix
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/print-diagonally1623/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> arr) 
    {
        // Code here
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int k = i;
            for(int j = 0 ; j<n && k>=0 ; j++ ,k--){
                ans.push_back(arr[j][k]);
            }
        }
        for(int i = 1;i<n;i++){
            for(int k = n-1 ,j = i ; k>=0 && j<n ; j++ , k--){
                ans.push_back(arr[j][k]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// Working with git