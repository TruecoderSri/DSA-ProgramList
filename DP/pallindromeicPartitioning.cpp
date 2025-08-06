class Solution
{

public:
    bool isPalindrome(string &s, int i, int j)
    {

        while (i < j)
        {

            if (s[i] == s[j])
            {

                i++;

                j--;
            }

            else
            {

                return false;
            }
        }

        return true;
    }

    int solve(string &s, int i, int j, vector<vector<int>> &dp)
    {

        if (i > j)
        {

            return 0;
        }

        if (isPalindrome(s, i, j))
        {

            return 0;
        }

        if (dp[i][j] != -1)
        {

            return dp[i][j];
        }

        int mini = INT_MAX;

        int left = 0;

        int right = 0;

        for (int k = i; k <= j - 1; k++)
        {

            if (dp[i][k] != -1)
            {

                left = dp[i][k];
            }

            else
            {

                left = solve(s, i, k, dp);

                dp[i][k] = left;
            }

            if (dp[k + 1][j] != -1)
            {

                right = dp[k + 1][j];
            }

            else
            {

                right = solve(s, k + 1, j, dp);

                dp[k + 1][j] = right;
            }

            int temp = left + right + 1;

            if (temp < mini)
            {

                mini = temp;
            }

            dp[i][j] = mini;
        }

        return mini;
    }

    int palindromicPartition(string str)

    {

        int N = str.length();

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        return solve(str, 0, str.length() - 1, dp);
    }
};

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx-----------xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


Bottom-Up Optimized 


bool isPalindrome (int i,int j,string &s){
    
    while(i<j){
        if(s[i]!=s[j]) return false;
        
        i++; j--;
    }
    return true;
}
     int palindromicPartition(string str)
    {
        // Tabulation
        int n = str.size();
        vector<int>dp(n+1,0);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--) {
            int mini = INT_MAX;
            for(int j = i; j<n; j++) {
            if(isPalindrome(i,j,str)) {
                int cost = 1+dp[j+1];   // increase partition and check for the next index
                mini = min(mini,cost);
            }
        }
            dp[i]=mini;
        }
        return dp[0]-1;  // denotes no of cuts -1=partitions reqd.
    }
