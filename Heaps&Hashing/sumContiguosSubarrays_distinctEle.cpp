//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// TC:O(N)
// } Driver Code Ends

class Solution
{
public:
    int sumoflength(int arr[], int n)
    {
        unordered_set<int> st;
        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {

            while (j < n && st.find(arr[j]) == st.end())
            {
                st.insert(arr[j]);
                j++;
            }
            // formula to calculate all possible subarrays of given size
            ans += ((j - i) * (j - i + 1)) / 2;

            // erase the first element to start from the next index for the next iteration
            st.erase(arr[i]);
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
        cout << ob.sumoflength(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends