#include <bits/stdc++.h>
using namespace std;

int ans(int energy, int n, int arr[])
{
    priority_queue<int> pq;

    for (int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }

    int ans=0;
    while (!pq.empty() && energy > 0)
    {
        auto val = pq.top();
        pq.pop();

        int cnt = 2;
        while (cnt > 0 && energy >= val)
        {
            energy -= val;
            cnt--;
            ans++;
        }
    }
   
    return energy>0 ?-1:ans;
}

int main()
{
    int energy, n;
    cin >> energy;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout <<"Min excercises:" <<ans(energy, n, arr) << endl;
    return 0;
}
