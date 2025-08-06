#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
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
    for (i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    int l = 0, h = n - 1, med;
    float med1, m1, m2;
    if (n % 2 != 0)
    {
        med = (l + h) / 2;
        cout << arr[med];
    }
    else
    {
        m1 = (l + h) / 2;
        m2 = (l + h + 1) / 2;
        med1 = (arr[int(m1)] + arr[int(m2)]) / 2;
        cout << med1;
    }
    return 0;
}