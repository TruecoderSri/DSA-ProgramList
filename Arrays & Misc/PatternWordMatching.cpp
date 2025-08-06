#include <bits/stdc++.h>
using namespace std;
class Solution
{

    // s->size of str array,p->size of pattern
    // TC:O(s+p(s[i].size()))
    // SC:O(p+s)
public:
    bool wordPattern(string pattern, string s)
    {

        int j = 0;
        map<char, string> mp1;
        map<string, char> mp2;

        int c = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                c++;
        }
        if (c != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i++)
        {
            string temp = "";
            while (j < s.size())
            {
                if (s[j] == ' ')
                {
                    j++;
                    break;
                }
                else
                {
                    temp += s[j];
                    j++;
                }
            }
            if (mp1[pattern[i]].size() == 0)
                mp1[pattern[i]] = temp;
            else if (mp1[pattern[i]] != temp)
                return false;

            if (mp2[temp] == 0)
                mp2[temp] = pattern[i];
            else if (mp2[temp] != pattern[i])
                return false;
        }
        return true;
    }
};
