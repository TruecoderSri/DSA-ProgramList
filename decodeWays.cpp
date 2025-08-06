// class Solution {
// public:

// int nways(int i,string s){
//     int n=s.size();
//      vector<int> dp(n+1,0);
//     if(n==0||s[0]=='0')
//     return 0;
//     dp[0]=1;
//      dp[1] = s[0] != '0';

//     for(int i=2;i<=n;i++){
//         if(s[i-1]>='1'&&s[i-1]<='9')
//         dp[i]=dp[i-1];
//         if(dp[i-2]=='1')
//         dp[i]+=dp[i-2];
//         else if(s[i-2]=='2'&& (s[i-1]>='0'&&s[i-1]<='6'))
//         dp[i]+=dp[i-2];
//     }
//     return dp[n];
// }

// int numDecodings(string s) {
//     int n=s.size();

//    return nways(1,s);
// }
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int len = s.length();
        int dp[len + 1];
        int i;
        dp[0] = 1;
        dp[1] = 1;
        for (i = 2; i <= len; i++)
        {
            if (s[i - 1] == '0' && s[i - 2] != '1' && s[i - 2] != '2')
                return 0;
            if (s[i - 1] >= '1' && s[i - 2] == '1')
                dp[i] = dp[i - 1] + dp[i - 2];
            else if (s[i - 1] == '0' && s[i - 2] == '1')
                dp[i] = dp[i - 2];
            else if (s[i - 1] == '0' && s[i - 2] == '2')
                dp[i] = dp[i - 2];
            else if (s[i - 1] < '7' && s[i - 2] == '2')
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[len];
    }
};