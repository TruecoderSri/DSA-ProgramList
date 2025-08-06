#include <iostream>
using namespace std;
// calculate the maximum sum with out adjacent element included in a sum
int findMaxSum(int *arr, int n)
{
    // code here
    if (n == 1)
    {
        return arr[0];
    }
    if (n == 2)
    {
        return max(arr[0], arr[1]);
    }
    arr[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
        arr[i] = max(arr[i] + arr[i - 2], arr[i - 1]);

    return arr[n - 1];
}
int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxSum(arr, n) << endl;
    return 0;
}