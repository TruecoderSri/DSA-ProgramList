#include <iostream>
using namespace std;
int main()
{
    int t, n, i;

    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j] = arr[j + 1];
            j--;
        }
        arr[j + 1] = temp;
    }
    int k;
    cin >> k;

    cout << arr[n - k];

    return 0;
}