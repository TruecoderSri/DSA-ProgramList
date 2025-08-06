#include <bits/stdc++.h>
using namespace std;

int hcf(int a, int b)
{
    if (b == 0)
        return a;

    return hcf(b, b % a);
}

int ans(string s)
{
    unordered_map<int, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    int ans = 1;
    for (auto it : mp)
    {
        ans = hcf(ans, it.second);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << ans(s);
    return 0;
}