#include <iostream>
#include <string.h>
using namespace std;
string smallestwindow(string s, string p)
{
    int c = 0;
    int mp[256] = {0};
    for (int i = 0; i < p.size(); i++) // to update the frequency of each char in string p
    {
        if (mp[p[i]] == 0)
            c++;
        mp[p[i]]++;
    }
    int start = 0, len = INT_MAX;
    int i = 0, j = 0;
    while (j < s.size()) // traverse string s and decrement each by char by 1
    {
        mp[s[j]]--;
        if (mp[s[j]] == 0)
            c--;
        if (c == 0) // if all char of string p are traversed the count becomes 0
        {
            while (c == 0)
            {
                if (j - i + 1 < len) // the  len is updated to calc the shortest length
                {
                    len = j - i + 1;
                    start = i;
                }
                mp[s[i]]++; // further the window is slided to by incrementing its value by 1
                if (mp[s[i]] == 1)
                    c++;
                i++;
            }
        }
        j++;
    }
    if (len != 0)
        return s.substr(start, len); // returns the shortest window of the related string
    return "-1";
}
int main()
{
    string s = "timetopractice";
    string p = "pce";
    cout << "shortest related length:" << smallestwindow(s, p);
    return 0;
}