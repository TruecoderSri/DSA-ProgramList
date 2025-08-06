#include <iostream>
//#include <climits>
using namespace std;
// Time complexity of O (log n)
int min(int arr[], int n)
{
    int low = arr[0];
    int high = arr[n - 1];
    if (arr[low] <= arr[high])
    {
        return arr[0];
    }
    int mid = (low + high) / 2;
    if (arr[mid] > arr[mid + 1])
        return arr[mid + 1];
    else if (arr[mid] < arr[mid - 1])
        return arr[mid];
    else if (arr[low] <= arr[mid])
        low = mid + 1;
    else if (arr[mid] <= arr[high])
        high = mid - 1;

    else
        return -1;
}
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Min in Sorted rotated array:" << min(arr, n) << endl;
    return 0;
}