//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here

        sort(a, a + n);
        int count = 0;
        long long int ans = 0;

        // run for the negative values

        for (int i = 0; i < k; i++)
        {
            if (a[i] < 0)
            {
                a[i] = -a[i];
                count++;
            }
            else
                break;
        }
        // sort the updated list
        sort(a, a + n);
        // change k ie k=k-(neg-count)
        k -= count;
        // if k is odd the change would be a minus sign else same
        if (k % 2 != 0)
        {
            a[0] = -a[0];
        }
        for (int i = 0; i < n; i++)
        {
            ans += a[i];
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends