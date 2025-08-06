#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define l 256

string lPrefix(vector<string> &strs)
{

    int i, c = 0;
    string res;
    int minlen = strs[0].length();
    for (i = 0; i < strs.size(); i++)
    {
        if (strs[i].length() <= minlen)
        {
            minlen = strs[i].length();
            res = strs[i];
        }
    }
    char curr;
    for (i = 0; i < minlen; i++)
    {
        curr = res[i];
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[j][i] != curr)
                return res.substr(0, c);
        }
        c++;
    }
    return res.substr(0, c);
}

int main()
{
    vector<string> st;
    string s;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        st.push_back(s);
    }
    lprefix(st);

    return 0;
}