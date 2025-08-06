#include <iostream>
#include <math.h>
using namespace std;
void merge(int *arr1, int *arr2, int n, int m)
{
    // code here
    int i, j;
    int gap = ceil((m + n) / 2);
    while (gap > 1)
    {

        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
        gap = (gap / 2) + (gap % 2);
    }
}
int main()
{
    int arr[] = {1, 3, 5, 7};
    int Arr[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(Arr) / sizeof(Arr[0]);
    merge(arr, Arr, n, m);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for (int j = 0; j < m; j++)
    {
        cout << Arr[j] << " ";
    }
    return 0;
}