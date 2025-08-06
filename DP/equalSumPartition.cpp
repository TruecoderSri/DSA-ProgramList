//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool solve(int N,int index,int arr[],int target,vector<vector<int>>&dp){

        if(target==0)
        return 1;
        if(target<0)
        return 0;
        if(index>=N)
        return 0;
        if(dp[index][target]!=-1)
        return dp[index][target];
        
        dp[index][target]=(solve(N,index+1,arr,target-arr[index],dp)||solve(N,index+1,arr,target,dp));
        
        return dp[index][target];
    }
    int equalPartition(int N, int arr[]){
    
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2!=0)
        return 0;
        else
        {
          int target=sum/2;
          vector<vector<int>>dp(N,vector<int>(target+1,-1));
          return solve(N,0,arr,target,dp);
            
        }
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends