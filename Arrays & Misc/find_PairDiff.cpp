#include <iostream>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    // code
    sort(arr, arr + size);
    int i = 0, flag = 0;
    int j = 1;
    while (i < size && j < size)
    {
        int d = abs(arr[i] - arr[j]);
        if (d == n)
        {
            return true;
        }
        else if (d < n)
            j++;

        else
            i++;
        if (i == j)
        {
            i--;
            j++;
        }
    }

    return false;
}
int main()
{
    int arr[] = {5, 20, 3, 2, 5, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 78;
    if (findPair(arr, size, n))
        cout << "1\n";
    else
        cout << "-1\n"

            return 0;
}