// all 3 approches

int solve(int idx, int W, int val[], int wt[], vector<vector<int>> &dp)
{

    if (W == 0 || idx == 0)
    {
        return 0;
    }

    if (dp[idx][W] != -1)
        return dp[idx][W];

    int pick = INT_MIN;

    if (wt[idx - 1] <= W)
    {

        pick = val[idx - 1] + solve(idx, W - wt[idx - 1], val, wt, dp);
    }
    int notpick = solve(idx - 1, W, val, wt, dp);

    return dp[idx][W] = max(pick, notpick);
}

int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    // vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    vector<int> dp(W + 1, 0);

    // for (int i=1;i<=N;i++){
    //     for (int j=0;j<=W;j++){
    //         dp[i][j] = dp[i - 1][j];  // Initialize with the value when the current item is not picked.

    //     if (wt[i - 1] <= j) {
    //         dp[i][j] = max(dp[i][j], val[i - 1] + dp[i][j - wt[i - 1]]);
    //     }
    //     }

    for (int i = 1; i <= N; i++)
    {
        for (int j = wt[i - 1]; j <= W; j++)
        {
            dp[j] = max(dp[j], val[i - 1] + dp[j - wt[i - 1]]);
        }
    }

    return dp[W];
}