//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.

// TC:O(N^2)
// SC:O(N^2)

/*if A starts possible outcomes:
1)A selects 1st val then B has to select from 2 to n val:
   1.1)if B selects 2,then in the next itr A selects from 3 to n.
   1.2)if B selects n,then in the next itr A selects from 3 to n-1.
   
2)A selects nth val then B has to select from 1 to n-1 val:
   2.1) if B selects 1 then in next itr A selects from 2 to n-1;
   2.2) if B selects n-1 val then A selects from 1 to n-2;*/

class Solution{
    public:
    
    int solve(int arr[],int i,int j,vector<vector<int>>&dp){
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int x=arr[i]+min(solve(arr,i+2,j,dp),solve(arr,i+1,j-1,dp));
        int y=arr[j]+min(solve(arr,i,j-2,dp),solve(arr,i+1,j-1,dp));
        
        return dp[i][j]=max(x,y);
        
    }
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(arr,0,n-1,dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends