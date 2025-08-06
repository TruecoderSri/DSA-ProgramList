#include <iostream>
using namespace std;
// count no of inversions needed to sort the array
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv = 0;
    i = left;
    j = mid;
    k = right;
    while (i < mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            arr[k++] = arr[i++];
        }
        else
        {
            arr[k++] = arr[j++];
            inv += (mid - i);
        }
    }
    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i < right; i++)
    {
        arr[i] = temp[i];
    }
    return inv;
}
int mergesort(int arr[], int temp[], int left, int right)
{
    int inv = 0;
    while (left < right)
    {
        int mid = (left + right) / 2; //break at pivot and then start compare 
        inv += mergesort(arr, temp, left, mid);
        inv += mergesort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid, right);
    }
    return inv;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int temp[n];
        cout << mergesort(arr, temp, 0, n - 1);
    }
    return 0;
}