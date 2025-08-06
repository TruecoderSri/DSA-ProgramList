//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// TC:O(K)
// SC:O(K)
// } Driver Code Ends

class Solution
{
public:
    string fractionToDecimal(int num, int deno)
    {
        // Code here
        string ans = "";
        unordered_map<int, int> mp;
        int quo = num / deno;
        int rem = num % deno;
        ans += to_string(quo);
        if (rem == 0)
            return ans;

        ans.push_back('.');
        int size = ans.size();

        while (rem)
        {
            rem *= 10;
            int x = rem / deno;

            if (mp[rem])
            {
                ans.insert(mp[rem], "(");
                break;
            }
            // we store the (remainder,position(here size)) in the map to check for repeating digits i.e. recurring
            mp[rem] = size;
            rem = rem % deno;
            ans += to_string(x);

            if (rem == 0)
                return ans;
            size++;
        }
        ans.push_back(')');
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int numerator, denominator;
        cin >> numerator >> denominator;
        Solution ob;
        string ans = ob.fractionToDecimal(numerator, denominator);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends