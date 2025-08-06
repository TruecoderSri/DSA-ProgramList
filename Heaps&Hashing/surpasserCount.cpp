//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // TC:O(N*logN)
    // SC: O(N)
    void merge(int arr[], int l, int r, int mid, unordered_map<int, int> &mp)
    {

        int i = l, k = l;
        int j = mid + 1;
        int temp[2 * mid + 1];
        int c = 0;
        while (i <= mid && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                mp[arr[i]] += c;
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                c++;
            }
        }
        while (i <= mid)
        {
            mp[arr[i]] += c;
            temp[k++] = arr[i++];
        }
        while (j <= r)
        {
            temp[k++] = arr[j++];
        }
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[i];
        }
    }

    void mergesort(int dup[], int l, int r, unordered_map<int, int> &mp)
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergesort(dup, l, mid, mp);
            mergesort(dup, mid + 1, r, mp);
            merge(dup, l, r, mid, mp);
        }
    }

    vector<int> findSurpasser(int arr[], int n)
    {
        // code here

        unordered_map<int, int> mp;
        int dup[n + 1];
        memcpy(dup, arr, n * sizeof(int));

        mergesort(dup, 0, n - 1, mp);

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back((n - 1) - i - mp[arr[i]]);
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findSurpasser(arr, n);
        for (auto i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends