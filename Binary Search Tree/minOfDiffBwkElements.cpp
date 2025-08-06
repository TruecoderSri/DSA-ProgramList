//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minDiff(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int ans = INT_MAX;
        for (int i = 0; i <= N - K; i++)
        {
            // sliding window approach
            long mini = arr[i];
            long maxi = arr[i + K - 1];
            long d = maxi - mini;
            if (d < ans)
            {
                ans = d;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution obj;
        cout << obj.minDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends