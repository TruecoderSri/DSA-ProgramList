//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// TC:O(N)
// SC:O(N)

/*for the first transaction we itr from the last and maximise the profit
 to check if the the 2nd itr will benefit or not we itr from the beginning of the dp 
 and check whether the sum of existing sum +arr[i]>dp[i-1]if yes we update the dp with that value*/ 

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    int dp[n];
    memset(dp,0,sizeof(dp));
    int ma=price[n-1];
    for(int i=n-2;i>=0;i--){
        if(price[i]>ma) ma=price[i];
        dp[i]=max(dp[i+1],(ma-price[i]));
    }
    int mi=price[0];
    for(int i=1;i<=n-1;i++){
        if(price[i]<mi)mi=price[i];
        dp[i]=max(dp[i-1],dp[i]+(price[i]-mi));
    }
    return dp[n-1];
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends