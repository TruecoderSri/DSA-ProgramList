//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(vector<vector<int>>&dp,int i,int j,int arr[]){
    
    if(i>=j-1)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int mini=INT_MAX;
    
    for(int k=i+1;k<j;k++){
        int x=arr[i]*arr[k]*arr[j]+solve(dp,i,k,arr)+solve(dp,k,j,arr);
        mini=min(mini,x);
        
    }
    return dp[i][j]=mini;
}

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return solve(dp,0,N-1,arr);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends