//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// we have to display the possible strings with valid parenthesis S

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (i != A.size() - 1)
                cout << A[i] << " ";
            else
                cout << A[i];
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<string> &ans, string s, unordered_map<string, bool> &mp, int removals)
    {
        if (mp[s])
            return;

        mp[s] = true;

        if (removals == 0)
        {
            int n = no_of_removal(s);
            if (n == 0)

                ans.push_back(s);

            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            string a = s.substr(0, i);
            string b = s.substr(i + 1);
            string join = a + b;
            solve(ans, join, mp, removals - 1);
        }
        return;
    }

    int no_of_removal(string s)
    {

        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);

            else if (s[i] == ')')
            {
                if (st.size() != 0 && st.top() == '(')
                    st.pop();
                else if (st.size() == 0 || st.top() == ')')
                    st.push(')');
            }
        }
        return st.size();
    }
    vector<string> removeInvalidParentheses(string s)
    {
        // code here
        unordered_map<string, bool> str;
        int removals = no_of_removal(s);
        vector<string> ans;
        solve(ans, s, str, removals);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        string s;
        cin >> s;

        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);

        Array::print(res);
    }
}

// } Driver Code Ends