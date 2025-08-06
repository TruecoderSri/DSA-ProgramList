#include <iostream>
#include <vector>
using namespace std;
void combi(int arr[], int n, int r, int index, int data[], int i);
void printSum(int arr[], int n, int r)
{
    int data[r];
    combi(arr, n, r, 0, data, 0);
}
void combi(int arr[], int n, int r, int index, int data[], int i)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j];
        cout << endl;
        return;
    }
    if (i >= n)
        return;
    data[index] = arr[i];
    combi(arr, n, r, index + 1, data, i + 1);
    combi(arr, n, r, index, data, i + 1);
}

using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printSum(arr, n, r);
    return 0;
}