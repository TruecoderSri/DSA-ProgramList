#include <iostream>
using namespace std;
bool KSum(int a[], int b[], int k, int n)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if ((a[i] + b[i]) >= k)
            flag++;
    }
    if (flag > 0)
        return true;
    return false;
}

int main()
{
    int a[] = {1, 1, 4};
    int b[] = {7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int k;
    cin >> k;
    if (KSum(a, b, k, n))
        cout << "YES" << endl;
    else
        cout << "NO";
    return 0;
}