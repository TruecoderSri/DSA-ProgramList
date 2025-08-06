//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  
//   variation of LCS:just consider string b->reverse of string a and then same LCS code
  
  int solve(string A,string B,int m,int n, vector<vector<int>> &dp){
      if(m==0||n==0)
      return 0;
      
      if(dp[m][n]!=-1) 
      return dp[m][n];
      
      if(A[m-1]==B[n-1])
      return dp[m][n]=1+solve(A,B,m-1,n-1,dp);
      
      else
      return dp[m][n]=max(solve(A,B,m-1,n,dp),solve(A,B,m,n-1,dp));
  }
  
    int longestPalinSubseq(string A) {
        //code here
        int m=A.length();
        string B;
        for(int i=m-1;i>=0;i--)
        B.push_back(A[i]);
        int n=B.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(A,B,m,n,dp);
    }
};

//{ Driver Code Starts.
    
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends