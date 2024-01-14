/*

Author : Atishay Gupta
Date : 14/01/2024
Problem : Find duplicate rows in a binary matrix
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        unordered_map<string,int> mp;
        int i = 0;
        vector<int> ans;
        
        for(auto it: matrix){
            string s = "";
            for(auto k: it){
                s+=to_string(k);
            }
            if(mp.find(s)!=mp.end()){
                ans.push_back(i);
            }
            else mp[s] = i;
            
            i++;
        }
        
        return ans;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends