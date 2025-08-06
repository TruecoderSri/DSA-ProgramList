//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char s)
    {
        // assign priority
        if (s == '^')
            return 3;
        else if (s == '*' || s == '/')
            return 2;
        else if (s == '+' || s == '-')
            return 1;
        else
            return -1;
    }

    string infixToPostfix(string s)
    {

        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            char a = s[i];
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
                ans += a;

            else if (a == '(')
                st.push('(');

            else if (a == ')')
            {
                while (!st.empty() || st.top() == '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }

            // tackle operators
            else
            {
                while (!st.empty() && prec(st.top()) > prec(a))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(a);
            }
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends