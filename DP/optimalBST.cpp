#include <bits/stdc++.h>

int sum(vector<int> &freq, int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += freq[k];
    }
    return s;
}

int solve(vector<int> &freq, int i, int j, vector<vector<int>> &dp)
{

    if (i > j)
        return 0;
    if (j == i)
        return dp[i][j] = freq[i];
    if (dp[i][j] != -1)
        return dp[i][j];

    int fsum = sum(freq, i, j);
    int m = INT_MAX;

    for (int k = i; k <= j; k++)
    {
        int optCost = solve(freq, i, k - 1, dp) + solve(freq, k + 1, j, dp);
        m = min(m, optCost);
    }
    // according to the formula
    dp[i][j] = m + fsum;
    return dp[i][j];
}

int optimalCost(vector<int> &keys, vector<int> &freq, int n)
{
    // Write your code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(freq, 0, n - 1, dp);
}