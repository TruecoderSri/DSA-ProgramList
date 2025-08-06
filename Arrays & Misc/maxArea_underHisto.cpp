#include <iostream>
#include <stack>
using namespace std;
int maxarea(int arr[], int n)
{
    int ps[n], ns[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ps[i] = 0;
        }
        else
        {
            ps[i] = s.top() + 1;
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ns[i] = n - 1;
        }
        else
        {
            ns[i] = s.top() - 1;
        }
        s.push(i);
    }

    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = (ns[i] - ps[i] + 1) * arr[i];
        maxA = max(maxA, curr);
    }
    return maxA;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "the max area from this array:" << maxarea(arr, n) << "\n";
    return 0;
}