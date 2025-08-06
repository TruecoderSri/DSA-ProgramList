#include <bits/stdc++.h>
using namespace std;
// Time Complexity of O(N)
void multi(string s)
{
    int i = 0;
    string temp = " ";
    for (i = 0; i < s.size(); i++)
    {
        if (s[i + 1] && s[i] == s[i + 1])
        {
            continue;
        }
        if (s[i] != s[i + 1])
        {
            temp += s[i];
        }
    }
    for (i = 0; temp[i]; i++)
    {
        cout << temp[i];
    }
}
int main()
{
    string a = "najirs";
    cout << "Corrected String:";
    multi(a);
    return 0;
}