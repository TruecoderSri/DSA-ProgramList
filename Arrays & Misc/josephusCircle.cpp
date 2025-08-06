#include <bits/stdc++.h>
using namespace std;

int lastLeft(int n, int k)
{
    list<int> ls;
    for (int i = 0; i < n; i++)
    {
        ls.push_back(i);
    }
    auto it = ls.begin();

    while (ls.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            it++;
            if (it == ls.end())
                it = ls.begin();
        }
        it = ls.erase(it);
        if (it == ls.end())
            it = ls.begin();
    }
    return ls.front();
}

int main()
{

    int n, k;
    cin >> n >> k;
    int ans = lastLeft(n, k);
    cout << ans;
    return 0;
}