#include <iostream>
using namespace std;
// Time complexity O(N)
// Voting-Moore's Algorithm
int majorEle(int a[], int n)
{
    int c = 0;
    int maj_ele;
    int i;
    for (i = 0; i < n; i++) // calculates the count of each dig until it becomes zero then re-iterates and the last ele comes out to be the major-element.
    {
        if (c == 0)
        {
            maj_ele = a[i];
        }
        if (a[i] == maj_ele)
        {
            c++;
        }
        else
            c--;
    }
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == maj_ele)
        {
            res++;
        }
    }
    if (res > (n / 2))
    {
        return maj_ele;
    }
    else
        return -1;
}
int main()
{
    int a[] = {3, 1, 3, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    cout << majorEle(a, n) << endl;
    return 0;
}