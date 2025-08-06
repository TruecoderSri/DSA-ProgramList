#include <iostream>
#include <climits>
using namespace std;

// sort the array ad then check min diff in m subarray

void sort(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        if (j >= 0 & arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
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
    sort(arr, n);
    int k;
    cout << "How many children u wanna distribute:";
    cin >> k;
    int min = INT_MAX;
    for (i = 0; i <= (n - k); i++)
    {
        if (arr[k - 1 + i] - arr[i] < min)
        {
            if (arr[k - 1 + i] - arr[i] < 0)
                continue;
            else
                min = arr[k - 1 + i] - arr[i];
        }
    }
    cout << "The min difference:" << min << endl;
    return 0;
}