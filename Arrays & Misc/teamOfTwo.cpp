#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            int problem;
            cin >> problem;
            v[i].push_back(problem);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<int> solved(6, 0);
            for (int a : v[i])
            {
                solved[a] = 1;
            }
            for (int a : v[j])
            {
                solved[a] = 1;
            }
            int total = accumulate(solved.begin(), solved.end(), 0);
            if (total == 5)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}