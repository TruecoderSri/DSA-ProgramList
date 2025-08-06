//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
// TC:    O(N*(K^2))
// Auxiliary Space: O(N*K)
    
    public:
    
    int solve(int eggs,int floors, vector<vector<int>> &dp){
        
        if(floors==0||floors==1)
        
        return floors;
        if(eggs==1)
        return floors;
        
        if(dp[eggs][floors]!=-1) return dp[eggs][floors];
        
        int m=INT_MAX;
        
        for(int k=1;k<=floors;k++){
            int temp=1+max(solve(eggs-1,k-1,dp),solve(eggs,floors-k,dp));
           min(m,temp);
        dp[eggs][floors]=m;
        }
        return dp[eggs][floors];
    }
    
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends