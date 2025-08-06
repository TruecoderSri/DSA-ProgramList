#include <bits/stdc++.h>
using namespace std;
// Time complexity:O(N^2)
// Space complexity:O(1)
void minArrayKswaps(int arr[], int k, int n)
{

    for (int i = 0; i < n - 1 && k > 0; i++)
    {
        // Set the position where we want
        // to put the smallest integer
        int pos = i;

        for (int j = i + 1; j < n; j++)
        {
            // If we exceed the Max swaps
            // then terminate the loop
            if (j - i > k)
                break;
            // Find the minimum value from i+1 to
            // max k or n
            if (arr[j] < arr[pos])
                pos = j;
        }
        // shift every element by one position
        for (int j = pos; j > i; j--)
        {
            swap(arr[j], arr[j - 1]);
        }
        // Set the final value after swapping pos-i
        // elements
        k -= (pos - i);
    }
}

int main()
{
    int arr[] = {8, 9, 11, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    minArrayKswaps(arr, k, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}