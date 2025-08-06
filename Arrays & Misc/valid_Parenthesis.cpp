#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
// Time Complexity O(n)
bool isValid(string s)
{
    stack<char> st;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
                st.pop();
            else
            {
                return false;
                break;
            }
        }

        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
                st.pop();
            else
            {
                return false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
                st.pop();
            else
            {
                return false;
                break;
            }
        }
        else
        {
            return false;
            break;
        }
    }

    if (st.empty())
        return true;
    return false;
}
int main()
{
    string s = "([)])";
    if (isValid(s))
        cout << "valid\n";
    else
        cout << "Invalid\n";

    return 0;
}
