#include <iostream>
using namespace std;
void fourSum(int arr[], int n, int s)
{
    int left, right, i;
    // sort(arr, arr + n);
    for (i = 0; i < n - 3; i++)
    {
        int j = i + 1;
        while (j < n - 2)
        {
            left = j + 1;
            right = n - 1;
            while (left < right)
            {
                if ((arr[i] + arr[j] + arr[left] + arr[right]) == s)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[left] << " " << arr[right] << endl;
                }
                else if ((arr[i] + arr[j] + arr[left] + arr[right]) > s)
                    right--;
                else
                    left++;
            }
            j++;
        }
    }
}
int main()
{
    int arr[] = {
        2,
        4,
        5,
        6,
        7,
        8,
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 25;
    fourSum(arr, n, s);
    return 0;
}