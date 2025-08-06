#include <bits/stdc++.h>

class Solution
{
public:
    // Time COMPLEXITY:O(N)
    // space Complexity:O(N)
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // map to store the count of each unique element
        unordered_map<int, int> mp;
        // vector of vectors which have indexes of the various possible counts of elements in the array
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> ans;
        // keep track of the most frequent asked
        int count = 0;
        // counting the elements
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        // pushing the ele in vector
        for (auto it : mp)
        {
            freq[it.second].push_back(it.first);
        }
        // checking each block of the vector and pushing if not NUll
        for (int i = nums.size(); i > 0; i--)
        {
            if (freq[i].size() != 0)
            {
                for (int j = 0; j < freq[i].size(); j++)
                {
                    ans.push_back(freq[i][j]);
                    count++;
                }
            }
            if (count == k)
                break;
        }
        return ans;
    }
};