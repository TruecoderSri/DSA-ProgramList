//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(string s, string b, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i == s.length())
            return b.length() - j;
        if (j == b.length())
            return s.length() - i;

        if (dp[i][j] != 0)
            return dp[i][j];

        int ans = 0;

        if (s[i] == b[j])
            return solve(s, b, i + 1, j + 1, dp);
        else
        {
            // insert
            int insertans = 1 + solve(s, b, i, j + 1, dp);

            // delete
            int deleteans = 1 + solve(s, b, i + 1, j, dp);

            // replace
            int replaceans = 1 + solve(s, b, i + 1, j + 1, dp);

            ans = min(insertans, min(deleteans, replaceans));
        }
        return dp[i][j] = ans;
    }

    int editDistance(string s, string t)
    {
        // Code here
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), 0));
        return solve(s, t, 0, 0, dp);
    }
};

// Bottom-Up Approach

int minDistance(string word1, string word2)
{

    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] =
                    1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[n][m];
}
}
;

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends