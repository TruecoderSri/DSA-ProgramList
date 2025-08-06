#include <iostream>
using namespace std;
// TimeC:O(2^N)
int solve(int arr[], int n, int sum2)
{
    if (sum2 == 0) // base condn ie we're able to traverse and go to each element and we have found the subset
        return 1;
    if (n == 0)
        return 0;
    int target = arr[n - 1];
    if (target <= sum2)
    {
        return solve(arr, n - 1, sum2 - target) || solve(arr, n - 1, sum2); // we have option whether to include or exclude the element for findiing the subset
    }
    return solve(arr, n - 1, sum2);
}

int equalPartition(int N, int arr[])
{
    // code here
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0 || N < 2) // when the sum of ele is odd we cannot make subsets with equal sum
        return 0;
    else
        solve(arr, N, sum / 2);
}
int main()
{
    int ar[] = {1, 4, 1, 11};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << equalPartition(n, ar) << endl;
    return 0;
}