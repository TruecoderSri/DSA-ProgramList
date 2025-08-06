//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int dp[1001][1001];

    bool solve(string A, string B, string C, int a, int b, int c)
    {
        if (c == 0)
            return 1;
        if (!dp[a][b])
            return dp[a][b];

        int t1 = 0, t2 = 0;

        if ((a - 1) >= 0 && A[a - 1] == C[c - 1])
            t1 = solve(A, B, C, a - 1, b, c - 1);
        if ((b - 1) >= 0 && B[b - 1] == C[c - 1])
            t2 = solve(A, B, C, a, b - 1, c - 1);

        /* implies that the given string c is called interleaved only when both the
        strings are fully present in the 3rd string and so is OR */

        return dp[a][b] = t1 or t2;
    }

    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        // Your code here
        int a = A.length();
        int b = B.length();
        int c = C.length();
        if ((a + b) != c)
            return 0;
        dp[a][b];
        memset(dp, -1, sizeof(dp));

        return solve(A, B, C, a, b, c);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends