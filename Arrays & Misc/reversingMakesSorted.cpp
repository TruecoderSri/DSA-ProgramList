#include <iostream>
using namespace std;
bool checkforSort(int arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    // sort the array
    for (int i = 1; i < n; i++)
    {
        int tem = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tem)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tem;
    }
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (temp[i] != arr[i])
            break;
    }
    int j;
    for (j = n - 1; j >= 0; j--)
    {
        if (temp[j] != arr[j])
            break;
    }
    if (i >= j)
        return true;
    do
    {
        i++;
        if (arr[i] < arr[i + 1])
            return false;
    } while (i != j);
    return true;
}

int main()
{

    int arr[] = {1, 2, 5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    checkforSort(arr, n) ? (cout << "yes" << endl) : (cout << "no" << endl);
    return 0;
}