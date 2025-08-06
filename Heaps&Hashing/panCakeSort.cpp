#include <iostream>
using namespace std;

void reverse(int till_index, int arr[])
{
    int start = 0;
    int temp;
    while (start < till_index)
    {
        temp = arr[start];
        arr[start] = arr[till_index];
        arr[till_index] = temp;
        start++;
        till_index--;
    }
}

int findMaxIndex(int arr[], int lastIndex)
{
    int mI = 0;
    for (int i = 1; i <= lastIndex; i++)
    {
        if (arr[i] > arr[mI])
            mI = i;
    }
    return mI;
}

void panCakeSort(int arr[], int n)
{
    for (int lastIndex = n - 1; lastIndex >= 1; lastIndex--)
    {
        int maxIndex = findMaxIndex(arr, lastIndex);
        if (maxIndex != lastIndex)
        {
            reverse(maxIndex, arr);
            reverse(lastIndex, arr);
        }
    }
}

int main()
{

    int arr[] = {7, 9, 6, 8, 10, 4};
    panCakeSort(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}