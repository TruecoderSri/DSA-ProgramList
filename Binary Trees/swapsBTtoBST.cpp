//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void inorder(vector<int> &a, int i, int n, vector<int> &ans)
    {
        if (i >= n)
            return;

        inorder(a, 2 * i + 1, n, ans);
        ans.push_back(a[i]);
        inorder(a, 2 * i + 2, n, ans);
    }
    int swaps(vector<int> &ans, int n)
    {
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[ans[i]] = i;
        }
        sort(ans.begin(), ans.end());

        int c = 0;
        int i = 0;
        while (i < n)
        {
            // until the elements aren't equal keep doing
            if (mp[ans[i]] != i)
            {
                c++;
                swap(ans[i], ans[mp[ans[i]]]);
                continue;
            }
            i++;
        }
        return c;
    }

    int minSwaps(vector<int> &A, int n)
    {
        // Write your code here
        vector<int> ans;

        inorder(A, 0, n, ans);
        int a = swaps(ans, n);
        return a;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        int ans = ob.minSwaps(A, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends