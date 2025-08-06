long long int count(int coins[], int n, int sum) {
            long long int dp[sum+1][n+1];
            
            for(int i=0; i<=n; i++) dp[0][i] = 1;
            for(int i=1; i<=sum; i++) dp[i][0] = 0;
            
            for(int i=1; i<=sum; i++) {
                for(int j=1; j<=n; j++) {
                    
                    dp[i][j] = dp[i][j-1]; // n-1(Next coin)
                    
                    if(coins[j-1] <= i) { // coin < sum 
                        dp[i][j] += dp[i - coins[j-1]][j]; // sum - current coin. 
                    }
                }
                
            }
                return dp[sum][n];
        }