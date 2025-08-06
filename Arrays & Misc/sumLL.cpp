//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> findSum(vector<int> &a, vector<int> &b)
    {
        // code here

        vector<int> ans;
        int temp = 0;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            temp = a[i] + b[j] + carry;
            ans.push_back(temp % 10);
            carry = temp / 10;
            i--;
            j--;
        }
        // if partial part left
        while (i >= 0)
        {
            temp = a[i] + carry;
            ans.push_back(temp % 10);
            carry = temp / 10;
            i--;
        }
        while (j >= 0)
        {
            temp = b[j] + carry;
            ans.push_back(temp % 10);
            carry = temp / 10;
            j--;
        }
        if (carry != 0)
            ans.push_back(carry);

        reverse(ans.begin(), ans.end());
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends