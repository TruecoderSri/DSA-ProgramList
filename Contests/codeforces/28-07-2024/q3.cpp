#include <bits/stdc++.h>
using namespace std;

int allSame(const vector<int> &temp)
{
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] != temp[i - 1])
            return 0;
    }
    return temp[0];
}

pair<int, vector<int>> solve(int n, vector<int> arr)
{
    vector<int> xval;
    int cnt = 0;

    while (cnt <= 40)
    {
        if (allSame(arr) != 0)
        {
            break;
        }

        int x = (arr[0] + arr[1]) / 2;
        for (int i = 0; i < n; i++)
        {
            arr[i] = abs(arr[i] - x);
        }
        xval.push_back(x);
        cnt++;
    }

    if (cnt > 40)
    {
        return {-1, {}};
    }

    if (allSame(arr) != 0)
    {
        xval.push_back(allSame(arr));
        cnt++;
    }

    return (cnt <= 40) ? make_pair(cnt, xval) : make_pair(-1, vector<int>{});
}

int main()
{
    int t;
    cin >> t;
    vector<pair<int, vector<int>>> results;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        results.push_back(solve(n, arr));
    }

    for (const auto &result : results)
    {
        cout << result.first << endl;
        if (result.first != -1)
        {
            for (int x : result.second)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
