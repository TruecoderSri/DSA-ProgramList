//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    //   TC:O(N)
    // SC:O(K)
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            maxHeap.push({arr[i], i});
        }
        // first get the max of 1st window
        ans.push_back(maxHeap.top().first);
        for (int i = k; i < n; i++)
        {
            maxHeap.push({arr[i], i});
            // vital condn.:check for size of the k window
            while (!(maxHeap.top().second > i - k))
            {
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
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

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends