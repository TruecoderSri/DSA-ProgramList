//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string ans = " ";
        vector<int> count(26, 0);
        vector<char> ch;
        for (int i = 0; i < A.size(); i++)
        {
            if (!count[A[i] - 'a'])
            {
                ch.push_back(A[i]);
            }
            count[A[i] - 'a']++;

            int f = 0;
            for (int j = 0; j < ch.size(); j++)
            {
                if (count[ch[j] - 'a'] == 1)
                {
                    ans.push_back(ch[j]);
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                ans.push_back('#');
        }
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
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends