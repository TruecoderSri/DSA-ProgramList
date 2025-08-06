#include <iostream>
#include <vector>
using namespace std;
struct query
{
    int L, R;
};
void sumQuery(int arr[], int n, query q[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int l = q[i].L;
        int r = q[i].R;
        for (int i = l; i <= r; i++)
        {
            sum += arr[i];
        }
        cout << "the sum in:"
             << "[" << l << "," << r << "]"
             << ":" << sum << endl;
    }
}

int main()
{
    int arr[] = {8, 5, 4, 3, 6, 8, 9, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    query q[] = {{0, 3}, {1, 4}, {4, 7}};
    int m = sizeof(q) / sizeof(q[0]);
    sumQuery(arr, n, q, m);
    return 0;
}