#include <iostream>
#include <vector>
usig namespace std;
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
    vector<int> nums(4) = {70, 38, 22, 21};
    cout << minMaxGame(nums);
    return 0;
}