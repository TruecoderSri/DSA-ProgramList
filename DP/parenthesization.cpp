//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[1001][1001][2];
    int solve(string s, int i, int j, bool isTrue)
    {

        if (i > j)
            return false;

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        int ans = 0;

        //   since 2 operators are seperated by operands
        for (int k = i + 1; k <= j - 1; k += 2)
        {

            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&')
            {
                if (isTrue)
                    ans += lt * rt;
                else
                    ans += lt * rf + lf * rt + lf * rf;
            }
            else if (s[k] == '|')
            {
                if (isTrue)
                    ans += lt * rf + lf * rt + lt * rt;
                else
                    ans += lf * rf;
            }
            else if (s[k] == '^')
            {
                if (isTrue)
                    ans += lt * rf + lf * rt;
                else
                    ans += lf * rf + lt * rt;
            }
        }
        return dp[i][j][isTrue] = ans % 1003;
    }

    int countWays(int N, string S)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(S, 0, N - 1, true);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends