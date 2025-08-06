#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr)
{
    vector<int> even_indices;
    vector<int> odd_indices;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_indices.push_back(i);
        }
        else
        {
            odd_indices.push_back(i);
        }
    }

    int even_count = even_indices.size();
    int odd_count = odd_indices.size();

    int odd_swaps_to_start = 0;
    for (int i = 0; i < odd_count; i++)
    {
        odd_swaps_to_start += abs(odd_indices[i] - i);
    }

    int even_swaps_to_end = 0;
    for (int i = 0; i < even_count; i++)
    {
        even_swaps_to_end += abs(even_indices[i] - (n - even_count + i));
    }

    int odd_swaps_to_end = 0;
    for (int i = 0; i < odd_count; i++)
    {
        odd_swaps_to_end += abs(odd_indices[i] - (n - odd_count + i));
    }

    int even_swaps_to_start = 0;
    for (int i = 0; i < even_count; i++)
    {
        even_swaps_to_start += abs(even_indices[i] - i);
    }

    return min({odd_swaps_to_start, even_swaps_to_end, odd_swaps_to_end, even_swaps_to_start});
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Min Swaps: " << solve(n, arr) << endl;
    return 0;
}
