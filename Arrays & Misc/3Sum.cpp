class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; ++i)
        {
            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int k = i + 1, j = n - 1;

            while (k < j)
            {
                int sum = nums[i] + nums[k] + nums[j];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[k], nums[j]});

                    // Skip duplicate values for k and j
                    while (k < j && nums[k] == nums[k + 1])
                        ++k;
                    while (k < j && nums[j - 1] == nums[j])
                        --j;

                    ++k;
                    --j;
                }
                else if (sum > 0)
                {
                    --j;
                }
                else
                {
                    ++k;
                }
            }
        }

        return res;
    }
};