//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// Time complexity:O(NLogN)
class Solution
{
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
    {
        // Write your code here

        sort(X.begin(), X.end(), greater<int>());
        sort(Y.begin(), Y.end(), greater<int>());

        int hori_count = 1;
        int vert_count = 1;
        int totalcost = 0;
        int i = 0, j = 0;

        while (i < M - 1 && j < N - 1)
        {
            if (X[i] > Y[j])
            {
                totalcost += X[i] * vert_count;
                hori_count++;
                i++;
            }
            else
            {
                totalcost += Y[j] * hori_count;
                vert_count++;
                j++;
            }
        }
        while (i < M - 1)
        {
            totalcost += X[i] * vert_count;
            i++;
        }
        while (j < N - 1)
        {
            totalcost += Y[j] * hori_count;
            j++;
        }
        return totalcost;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> X(m - 1), Y(n - 1);
        for (int i = 0; i < m - 1; i++)
        {
            cin >> X[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> Y[i];
        }
        Solution ob;
        int ans = ob.minimumCostOfBreaking(X, Y, m, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends