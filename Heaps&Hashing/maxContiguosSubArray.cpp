#include <bits/stdc++.h>
using namespace std;

//   TC:O(N^2)

int findMxlength(int arr[], int n)
{
    int max_len = 1;
    for (int i = 0; i < n - 1; i++)
    {

        unordered_set<int> mp;

        mp.insert(arr[i]);
        int mn = arr[i];
        int mx = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            // check duplicacy

            if (mp.find(arr[j]) != mp.end())
                break;

            mp.insert(arr[j]);
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);

            // condn. for contiguos sequential subarray
            if ((mx - mn) == j - i)
                max_len = max(max_len, mx - mn + 1);
        }
    }
    return max_len;
}

int main()
{

    int arr[] = {10, 12, 12, 10, 10, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "MX lENGTH" << findMxlength(arr, n);
    return 0;
}