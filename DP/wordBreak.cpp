int solve(string s,vector<string>&dict,unordered_map<string,int>&dp)
{
    int size=s.length();
    if(s.size()==0)
    {
        return 1;
    }
    if(dp[s]!=0)
    {
        return dp[s];  //if count of that subset exist than return that count
    }
    for(int i=1;i<=size;i++)
    {
        int f=0;
        string ss=s.substr(0,i);
        for(int j=0;j<dict.size();j++)
        {
            if(ss.compare(dict[j])==0)
            {
                f=1;
                break;
            }
        }
        if(f==1 and solve(s.substr(i,size-i),dict,dp)==1)
          return dp[s]=1;
    }
    return dp[s]=0;
}
    int wordBreak(string A, vector<string> &B) {
        unordered_map<string,int>dp;
     return solve(A,B,dp);
    }