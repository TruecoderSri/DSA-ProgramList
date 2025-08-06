bool solve(string w, string p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0) // string is finised
        return true;

    if (j >= 0 && i < 0) // means our wild string is finished but patter string is not finsh
        return false;

    if (i >= 0 && j < 0) // means pattern is finish but wildcard is remain
    {
        // now we check that in wild string is only remain the star or not

        for (int k = 0; k <= i; k++) // we traverse the wild string and check the *
        {
            if (w[k] != '*')
                return false;
        }

        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // above we handeled the base case

    // Now , If match

    if (w[i] == p[j] || w[i] == '?')
        return dp[i][j] = solve(w, p, i - 1, j - 1, dp);

    else if (w[i] == '*')
    {
        return dp[i][j] = (solve(w, p, i - 1, j, dp) || solve(w, p, i, j - 1, dp));
    }

    else
        return false;
}

bool match(string wild, string pattern)
{
    vector<vector<int>> dp(wild.size(), vector<int>(pattern.size(), -1));

    return solve(wild, pattern, wild.size() - 1, pattern.size() - 1, dp);
}