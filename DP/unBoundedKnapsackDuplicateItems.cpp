// TC:O(N*W)
// Auxiliary Space: O(W)

class Solution{
public:
       int dp[1001][1001];
       
     int solve(int N,int w,int val[],int wt[]){
         if(N<0)
         return 0;
         if(dp[N][w]!=-1) return dp[N][w];
        //  in this condn.
         if(wt[N]<=w)
        //  include a weight:as many times you want,just reduce the weight requirement for each iteration
         return dp[N][w]=max((val[N]+solve(N,w-wt[N],val,wt)),solve(N-1,w,val,wt));
        //  exclude an item and iterate for remaining loop
         else return dp[N][w]=solve(N-1,w,val,wt);
     }  
       
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp[N][W];
        memset(dp,-1,sizeof(dp));
        return solve(N-1,W,val,wt);
    }
};