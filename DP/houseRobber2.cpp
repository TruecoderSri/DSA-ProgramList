class Solution

// TC:O(N)
// SC:O(1)
{
public:
    // the idea is to select the max sum from max((0,n-1),(1,n)) of the houses

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 && nums[0] != 0)
            return nums[0];
        else if (n == 1 && nums[0] == 0)
            return 0;
        int prev = 0, curr = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int temp = max(nums[i] + prev, curr);
            prev = curr;
            curr = temp;
        }
        int m1 = curr;
        int prev1 = 0, curr1 = 0;
        for (int i = 1; i < n; i++)
        {
            int temp = max(nums[i] + prev1, curr1);
            prev1 = curr1;
            curr1 = temp;
        }
        int m2 = curr1;
        return max(m1, m2);
    }
};