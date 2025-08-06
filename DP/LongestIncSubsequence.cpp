#include <bits/stdc++.h>
using namespace std;

// TC:O(N^2)
// SC:O(N)

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        int dp[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
        }
        int maxlen = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxlen = max(dp[i], maxlen);
        }
        return maxlen;
    }
};