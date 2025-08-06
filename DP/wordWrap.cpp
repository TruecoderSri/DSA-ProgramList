//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

// TC:O(N^2)
// SC:O(N^2)
// 1st []->n/2nd []->k

   int dp[501][2001];
    int solve(int i, int rem, vector<int>& arr, int &k){
      
      if(i==arr.size())
      return 0;
      if(dp[i][rem]!=-1)
      return dp[i][rem];
      
      int ans;
    //   if the word is > than remaining words we goto the next line
    
      if(arr[i]>rem){
          
          ans=(rem+1)*(rem+1)+solve(i+1,k-arr[i]-1,arr,k);
      }
    /*  2 choices:
     stay on the same line
       goto te next line whichever yeilds the least cost*/
      
      else{
          int choice1=(rem+1)*(rem+1)+solve(i+1,k-arr[i]-1,arr,k);
          int choice2=solve(i+1,rem-arr[i]-1,arr,k);
          ans=min(choice1,choice2);
      }
       dp[i][rem]=ans;
       return dp[i][rem];
    }
    int solveWordWrap(vector<int>arr, int k) 
    { 
      memset(dp,-1,sizeof(dp));
      return solve(0,k,arr,k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends