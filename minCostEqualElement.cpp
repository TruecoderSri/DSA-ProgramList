#include <iostream>
using namespace std;
// Time complexity is O(N)//Space complexity O(1)
int main()
{
    int i, n;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
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
    int start = 0;
    int end = n - 1; // assign pointers to the first and last element ans calc sum of differnces
    int sum = 0;
    while (start <= end)
    {
        sum += (arr[end] - arr[start]);
        start++;
        end--;
    }
    cout << sum << endl;
    return 0;
}