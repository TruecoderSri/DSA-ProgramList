#include <bits/stdc++.h>
using namespace std;

int countKsubseq(int arr[], int n, int k)
{
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // general case for every sum
            dp[i][j] = dp[i][j - 1];

            // if the number is smaller than curr asked val ie K then only proceed the if part
            if (arr[j - 1] <= i)
            {
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
            }
        }
        return dp[k][n];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    cout << countKsubseq(arr, n, k) << endl;
    return 0;
}