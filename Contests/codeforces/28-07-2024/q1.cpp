#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, int arr[])
{
    priority_queue<pair<int, int>> pq;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i], i});
    }

    while (!pq.empty())
    {
        int ind = pq.top().second;
        int val = pq.top().first;
        if (ind % 2 == 0)
        {
            ans = val;
            break;
        }
        else
            pq.pop();
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    vector<int> val;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int maxVal = solve(0, n, arr);
        val.push_back(maxVal);
    }

    for (auto it : val)
    {
        cout << it << endl;
    }

    return 0;
}