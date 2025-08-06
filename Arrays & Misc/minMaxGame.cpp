#include <bits/stdc++.h>
#include <vector>

// Time complexity:O(n)
// In this problem we find the min of the first 2 nos and max of the next 2 after 1 iteration we fing he max of the remaining digits and then min of the remaining digits & so on.
using namespace std;
int minMaxGame(vector<int> &nums)
{
    int n = nums.size();
    vector<int> newNums(pow(2, n - 1));
    int j, l = n;
    for (j = 0; j < l / 2; j++)
    {
        if (l == 1)
            break;
        if (j % 2 == 0)
        {
            newNums[j] = min(nums[2 * j], nums[2 * j + 1]);
        }
        else
        {
            newNums[j] = max(nums[2 * j], nums[2 * j + 1]);
        }
        nums[j] = newNums[j];
        if (j == ((l / 2) - 1))
            l = j + 1;
    }
    return nums[0];
}
int main()
{
    vector<int> nums(4);
    int a[] = {1, 3, 5, 2, 4, 8, 2, 2};
    nums.assign(a, a + 3);
    cout << minMaxGame(nums);
    return 0;
}