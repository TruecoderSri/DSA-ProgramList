#include <bits/stdc++.h>
using namespace std;
// To find the duplicate parenthesis if present in the string
int main()
{
    stack<char> st;
    string s;
    cin >> s;
    string ans = " ";
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }
        if (s[i] == '(')
            st.push(s[i]);

        if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
                flag = 1;
                cout << "Duplicate Found" << endl;
                break;
            }

            else if (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
            {
                st.pop();
            }
            st.pop();
        }
    }
    if (flag == 0)
        cout << "Not Found" << endl;
    return 0;
}