long long int mod=1000000007;
    
      long long int solve(string A,string B,int m,int n, vector<vector<long long int>> &dp){
      if(m==0||n==0)
      return 0;
      
      if(dp[m][n]!=-1) 
      return dp[m][n];
      
      if(A[m-1]==B[n-1])
      return dp[m][n]=(1+solve(A,B,m-1,n,dp)+solve(A,B,m,n-1,dp))%mod;
      
      else
      return dp[m][n]=(mod+solve(A,B,m-1,n,dp)+solve(A,B,m,n-1,dp)-solve(A,B,m-1,n-1,dp))%mod;
  
      }
  
    long long int  countPS(string str){
        //code here
        int m=str.length();
        string B;
        for(int i=m-1;i>=0;i--)
        B.push_back(str[i]);
        int n=B.length();
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        
        return solve(str,B,m,n,dp); 
    }