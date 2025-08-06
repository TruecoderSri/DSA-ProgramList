#include <iostream>
#include <string>
using namespace std;
int convertOp(string &s, string &t)
{
    int m = s.size(), n = t.size();
    int i, j;
    if (m != n)
        return -1;
    int count[256] = {0};
    for (i = 0; i < m; i++)
    {
        count[s[i]++];
    }
    for (j = 0; j < n; j++)
    {
        count[t[j]--];
    }
    for (i = 0; i < 256; i++)
    {
        if (count[i])
            return -1;
    }
    int c = 0;
    for (i = n - 1, j = n - 1; i >= 0;)
    {
        while (i >= 0 && s[i] != t[i])
        {
            i--;
            c++;
        }
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return c;
}
int main()
{
    string s = "ABD";
    string t = "BAD";
    cout << "No.of operations to convert string A to B:" << convertOp(s, t);
    return 0;
}