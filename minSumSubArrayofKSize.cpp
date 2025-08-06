#include <bits/stdc++.h>
int minSubarraySum(int arr[], int n, int k)
{
    // Write your code here
    //     TC:O(N)
    //     SC:O(1)
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int curr = sum;
    for (int i = k; i < n; i++)
    {
        // removing the first element from prev k sum
        curr += arr[i] - arr[i - k];
        // getting the in of them all
        sum = min(sum, curr);
    }
    return sum;
}
