#include <bits/stdc++.h>

//  TC:O(N*M)N->no of strings ,M->vector size
using namespace std;

string stringDiff(string str)
{
    string shift = "";
    for (int i = 1; i < str.length(); i++)
    {
        int diff = str[i] - str[i - 1];
        if (diff < 0)
            diff += 26; // since there're 26 alphabets
        shift = (diff + 'a');
    }
    return shift;
}

void groupStrings(string str[], int n)
{
    map<string, vector<int>> groupStr; // to store the the str's with same diff in a single vector
    for (int i = 0; i < n; i++)
    {
        string gather = stringDiff(str[i]);
        groupStr[gather].push_back(i);
    }
    // iterating through map to print group
    for (auto it = groupStr.begin(); it != groupStr.end(); it++)
    {
        vector<int> count = it->second;
        for (int i = 0; i < count.size(); i++)
        {
            cout << str[count[i]] << " ";
        }
        cout << endl;
    }
}
int main()
{
    string str[] = {"acd", "dfg", "wyz", "yab", "mop",
                    "bdfh", "a", "x", "moqs"};
    int n = sizeof(str) / sizeof(str[0]);
    groupStrings(str, n);
    return 0;
}
