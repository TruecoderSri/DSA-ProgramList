//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {
        // Code here
        int inc = 1;
        int dec = 1;
        //   not include the last point coz it is already included
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                inc = dec + 1;
            else if (nums[i] < nums[i - 1])
                dec = inc + 1;
        }
        int ans = max(inc, dec);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.AlternatingaMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends 