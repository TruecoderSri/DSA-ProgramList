
    int solve(int i,int j, vector<vector<int>> &Matrix,vector<vector<int>> &dp,int N){
        if(j>N||j<0){
          return 0;
        }
        if(i==N)
        return Matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
         int down=solve(i+1,j,Matrix,dp,N);
         int downleft=solve(i+1,j-1,Matrix,dp,N);
         int downright=solve(i+1,j+1,Matrix,dp,N);
          
          dp[i][j]=Matrix[i][j]+max(down,max(downleft,downright));
          return dp[i][j];
         
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
         vector<vector<int>>dp(N,vector<int>(N, -1));
         
         int m=INT_MIN;
         for(int i=0;i<N;i++){
             m=max(m,solve(0,i,Matrix,dp,N-1));
         }
         return m;
         
    }