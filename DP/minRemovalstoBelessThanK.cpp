class Solution
{
public:
    int solve(vector<int> &arr, int k, vector<vector<int>> &dp, int i, int j)
    {

        // base case
        if (i >= j)
            return 0;

        if ((arr[j] - arr[i]) <= k)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // hit & Trial by neglecting the first or last one by one

        dp[i][j] = 1 + min(solve(arr, k, dp, i + 1, j), solve(arr, k, dp, i, j - 1));
        return dp[i][j];
    }

    int removals(vector<int> &arr, int k)
    {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // to get the ele in inc order
        sort(arr.begin(), arr.end());

        return solve(arr, k, dp, 0, n - 1);
    }
};