#include <iostream>
using namespace std;
// Time Complexity O((n+b)*logb(max)) :Space complexity O(max)
int getmax(int arr[], int n) // to calculate the max digit occurence in the array
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int countsort(int arr[], int n, int place)
{
    int output[n];       // to store the sorted array
    int count[10] = {0}; // to store the countof each digit

    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++; // inc the occurence of digit in the count array

    for (int i = 1; i < 10; i++) // Cumulative count
        count[i] += count[i - 1];

    // sorted array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int m = getmax(arr, n);
    // sort array using count sort based on place value
    for (int place = 1; m / place > 0; place *= 10)
        countsort(arr, n, place);
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    printArray(arr, n);
    return 0;
}