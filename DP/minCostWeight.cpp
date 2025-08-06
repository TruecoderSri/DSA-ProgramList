//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
// Position this line where user code will be pasted.

class Solution
{

public:
    int minimumCost(int cost[], int N, int W)
    {
        // Your code goes here
        vector<int> dp(W + 1, 1e9);

        //   base case
        dp[0] = 0;

        for (int i = 1; i <= W; i++)
        {
            //   to traverse the cost array
            for (int j = 0; j < N && j < i; j++)
            {
                // the if,checks that does the remaining weight packet exists or not to make it the minimum possible
                if (cost[j] != -1 && dp[i - j - 1] != 1e9)
                {
                    dp[i] = min(dp[i], cost[j] + dp[i - j - 1]);
                }
            }
        }
        return dp[W] == 1e9 ? -1 : dp[W];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
}
// } Driver Code Ends