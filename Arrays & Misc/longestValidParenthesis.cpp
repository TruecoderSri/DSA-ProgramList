//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {
        // code here
        stack<char> st;
        stack<int> ind;
        ind.push(-1);
        int maxx = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s.empty() || s[i] == '(')
            {
                st.push(s[i]);
                ind.push(i);
            }
            else
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    ind.pop();
                    maxx = max(maxx, i - ind.top());
                }
                else
                {
                    ind.push(i);
                }
            }
        }
        return maxx;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends