#include <iostream>
using namespace std;
// time complexity of O(N)
int ceil(int a[], int x, int n)
{
    int i;

    if (x <= a[0])
        return a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return a[i];
        }
        else if (a[i] < x && x <= a[i + 1]) // the no is b/w 2 no of the array
        {
            return a[i + 1];
        }
    }
    return -1;
}
int main()
{
    int a[] = {2, 8, 10, 10, 12, 19};
    int n = sizeof(a) / sizeof(a[0]);
    int x, low, high;
    cout << ceil(a, 0, n) << endl;
    cout << ceil(a, 1, n) << endl;
    cout << ceil(a, 5, n) << endl;
    cout << ceil(a, 20, n) << endl;
    return 0;
}