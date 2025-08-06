int maxChainLen(struct val p[], int n)
{
    // Your code here
    int dp[n];
    // memset(dp,1,sizeof(dp));
    vector<pair<int, int>> pa;

    for (int i = 0; i < n; i++)
        pa.push_back({p[i].first, p[i].second});

    sort(pa.begin(), pa.end());
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pa[j].second < pa[i].first)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, dp[i]);
    }
    return m;
}