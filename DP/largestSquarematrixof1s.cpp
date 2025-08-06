//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxSq(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() or j >= mat[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = maxSq(mat, i, j + 1, maxi, dp);
        int down = maxSq(mat, i + 1, j, maxi, dp);
        int diagonal = maxSq(mat, i + 1, j + 1, maxi, dp);

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min({diagonal, down, right});
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> A)
    {
        // code here
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // maxSq(A,0,0,maxi,dp);

        /* BOTTOMUP-APPROACH */

        int maxSquare(int n, int m, vector<vector<int>> mat)
        {
            // code here
            int maxi = 0;
            vector<vector<int>> dp(n, vector<int>(m, 0));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {

                    if (mat[i][j] == 1)
                    {

                        if (i == 0 || j == 0)
                        {
                            dp[i][j] = 1;
                        }
                        else
                        {
                            dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                        }

                        maxi = std::max(maxi, dp[i][j]);
                    }
                }
            }

            return maxi;
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends