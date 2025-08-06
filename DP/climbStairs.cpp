class Solution
{
    // understandable approach
    // TC:O(N);
    // SC:O(N);
    int climbStairs(int n)
    {

        vector<int> dp(n, 0);
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        dp[n - 1] = 1;
        dp[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--)
        {
            //    because 1 or 2 steps are allowed so follows a reverse fibo seq.
            dp[i] += dp[i + 1] + dp[i + 2];
        }

        return dp[0];
    }

public:
    int climbStairs(int n)
    {

        //  reaching at the dest itself can be done in 1 way n from n-1 also in 1 way
        int n1 = 1, n2 = 1;
        //  for corresponding values add the prev 2 values because moves're 1 or 2
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = n1;
            n1 += n2;
            n2 = temp;
        }
        return n1;
    }
};
