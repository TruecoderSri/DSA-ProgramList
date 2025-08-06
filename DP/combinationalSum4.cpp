class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<long long int>ans(target+1,0);
        ans[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++)
        {
            if(nums[j]<=i)
            ans[i]+=ans[i-nums[j]];
        }
        }
        return ans[target];
    }
};