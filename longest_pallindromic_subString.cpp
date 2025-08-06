#include <iostream>
#include <vector>
#include <map>
using namespace std;
// Time complexity is of O(N^3)
void substr(string s, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        cout << s[i];
    }
    cout << endl;
}
int Longpalsubstr(string s)
{
    int maxlen = 1, n = s.size();
    int l = 0;
    int i, j, k;
    // loops to initialise the start and end after every iteration
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            int flag = 1;
            for (k = 0; k < (j - i + 1) / 2; k++)
            {
                if (s[i + k] != s[j - k])
                    flag = 0;
            }
            if (flag && (j - i + 1) > maxlen)
            {
                maxlen = j - i + 1;
                l = i;
            }
        }
    }
    cout << "Longest pallindromic substring:";
    substr(s, l, l + maxlen - 1); // calling the substr function after with new low and high values
    return maxlen;
}


int main()
{
    string s = "swatantra";

    cout << Longpalsubstr(s) << endl;
    return 0;
}


class Solution {
public:
    string longestPalindrome(string s) {
        
   int l,r;
   int start=0,end=1;
   int n=s.size();
   for(int i=1;i<n;i++){
 
    //  for even string length or substr
      l=i-1;
      r=i;
      while(l>=0 && r<n && s[l]==s[r]){
          if(r-l+1>end)
          {
            end=r-l+1;
            start=l;
          }
      l--;
      r++;
      }
    //   for odd string length or substr
      l=i-1;
      r=i+1;
      while(l>=0 && r<n && s[l]==s[r]){
          if(r-l+1>end)
          {
            end=r-l+1;
            start=l;
          }
      l--;
      r++;
      }
  
   }
   return s.substr(start,end);

    }
};




 
    int dp[1001][1001];
    bool isPallindrome(string &s,int i,int j){

        if(i>=j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j])
        return dp[i][j]=isPallindrome(s,i+1,j-1);

        return dp[i][j]=0;
    }
    string longestPalindrome(string s) {
         memset(dp,-1,sizeof(dp));
         int n=s.size();
         int len=0;
         int st=0;
         for(int i=0;i<n;i++){
             for(int j=i;j<n;j++){
                 if(isPallindrome(s,i,j)){
                  if((j-i+1)>len)   
                   len=j-i+1;
                   st=i;
                 }
             }
         }

     return s.substr(st,len+1);
    }

