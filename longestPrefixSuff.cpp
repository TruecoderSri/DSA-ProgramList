#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
// print the largest prefix and suffix which are equal and are non overlapping
int lps(string s)
{
    int n = s.size();
    int lps[n - 1]; // array to store the lengths of consequent lengths of string
    int i = 1, len = 0;
    while (i < n)
    {
        if (s[len] == s[i])
        {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len != 0) // to resolve the anomaly coz it would calc. wrong size of the string prefix
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int res = lps[n - 1];
    return (res > n / 2) ? res / 2 : res; // to prevent overlapping of pre and suff
}

int main()
{
    string s = "abab";
    cout << "Length of the longest prefix/suffix:" << lps(s);
    return 0;
}