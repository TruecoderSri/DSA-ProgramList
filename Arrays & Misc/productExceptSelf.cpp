#include <iostream>
#include <vector>
using namespace std;
// Time Complexity O(2N)~O(N)::Space complexity O(N)
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans;
    int countzero = 0;
    long long int product = 1, i;
    for (i = 0; i < n; i++)
    {
        if (nums[i] == 0) // if any element is zero store its count
            countzero++;
        else
            product *= nums[i];
    }
    for (i = 0; i < n; i++)
    {
        if (countzero > 1) // anyways the product would be zero
        {
            ans.push_back(0);
        }
        else if (countzero == 1) // 2 subcases as mentioned
        {
            if (nums[i] != 0)
                ans.push_back(0);
            else
                ans.push_back(product);
        }
        else if (countzero == 0) // simply calc. by div by the current element
        {
            ans.push_back(product / nums[i]);
        }
    }
    return ans;
}
int main()
{
    int i, ele;
    int n;
    cin >> n;
    vector<long long int> nums;
    for (i = 0; i < n; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    vector<long long int> ans = productExceptSelf(nums, n);
    vector<long long int>::iterator itr;
    for (itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}
// optimised soln.

typedef long long int ll;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        //  ll *prod_left=new  ll(n);
        //  ll *prod_right=new ll(n);

        vector<int> prod(n);
        prod[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prod[i] = prod[i - 1] * nums[i - 1];
        }
        int p = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            prod[i] = prod[i] * p;
            p *= nums[i];
        }
        return prod;
    }
};
