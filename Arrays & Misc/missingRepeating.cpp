#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
    int i, n;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a = 0, b = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
        {
            a = abs(arr[i]);
        }
        else
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            b = i + 1;
            break;
        }
    }
    cout << a << "\t" << b << endl;
    return 0;
}