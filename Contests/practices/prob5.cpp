#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = i * fac[i - 1];

    return fac[n];
}

int solve(int n)
{
    int t = n - 1;
    int ans = 1;
    while (t > 1)
    {
        if (fact(t) % n == 1)
        {
            ans = t;
            break;
        }
        t--;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << "Max Length:" << solve(n) << endl;
    return 0;
}
