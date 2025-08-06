#include <iostream>
#include <vector>
using namespace std;
int search(int arr[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[low] <= arr[mid])
    {
        if (key >= arr[low] && key <= arr[high])
        {
            return search(arr, key, low, mid - 1);
        }
        return search(arr, key, mid + 1, high);
    }
    if (key >= arr[mid] && key <= arr[high])
    {
        return search(arr, key, mid + 1, high);
    }
    return search(arr, key, low, mid - 1);
}
int main()
{
    int arr[] = {4, 5, 6, 10, 1, 2, 5};
    int n = 7;
    int key;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\nEnter element to be searched:";
    cin >> key;
    int idx = search(arr, key, 0, n - 1);
    if (idx == -1)
        cout << "Sorry!! Element doesn't exist\n";
    else
        cout << "Searched element is present in:" << idx + 1 << endl;
    return 0;
}