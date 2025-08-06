 int maxGold(int n, int m, vector<vector<int>> ar)
    {
        // code here
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            dp[i][0] = ar[i][0];
        }
        for(int j=1;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                int right = dp[i][j-1];
                int right_up = (i==0)?0 : dp[i-1][j-1];
                int right_dn = (i==n-1)?0 : dp[i+1][j-1];
                dp[i][j] = ar[i][j] + max(right,max(right_up,right_dn));
            }
        }
        int result = INT_MIN;
        for(int i=0;i<n;i++){
            result = max(result,dp[i][m-1]);
        }
        return result;
    }