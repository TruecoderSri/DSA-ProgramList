#include <iostream>
using namespace std;
// Time complexity of O (log n)
int search(int arr[], int n, int k)
{
    int low = arr[0];
    int high = arr[n - 1];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (k == arr[mid])
        {
            return mid;
        }
        if (arr[low] <= arr[mid])
        {
            if (k >= arr[low] && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (k >= arr[mid] && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, i, k;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element to be searched:";
    cin >> k;
    if (search(arr, n, k) >= 0)
        cout << "yes at position:" << search(arr, n, k) << endl;
    else
        cout << "SORRY\n";
    return 0;
}