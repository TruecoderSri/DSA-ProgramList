//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Tc:o(LogN +K)
    // SC:O(1)
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        // code here
        // implementing max Heap
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            // don't include x itself
            if (x - arr[i] != 0)
            {
                // include the closest on the right side if there is a tie
                pq.push({-1 * abs(x - arr[i]), arr[i]});
            }
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
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
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends