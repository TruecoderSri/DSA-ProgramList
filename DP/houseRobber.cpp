class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        int pre = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = max(pre + nums[i], curr);
            // stores the value of the (i-1)th house
            pre = curr;
            // stores the val of curr house
            curr = temp;
        }
        return curr;
    }
};