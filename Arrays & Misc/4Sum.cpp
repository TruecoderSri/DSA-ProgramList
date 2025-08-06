#include <iostream>
using namespace std;
int 4Sum(int *arr[], int n, int s)
{
    int i, temp[n];
    for (i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j < n - 2)
        {
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                if ((arr[i] + arr[j] + arr[left] + arr[right]) == s)
                {
                    temp[0] = arr[i];
                    temp[1] = arr[j];
                    temp[2] = arr[left];
                    temp[3] = arr[right];
                }
                else if ((arr[i] + arr[j] + arr[left] + arr[right]) > sum)
                    right--;
                else
                    left++;
            }
            j++;
        }
    }
    return temp;
}

// with duplicate elements

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int targ)
    {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                int sum = 0;
                while (k < l)
                {
                    sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == targ)
                    {
                        ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                        while (arr[k] == arr[k + 1] && k < l)
                            k++;
                        while (arr[l] == arr[l - 1] && l > k)
                            l--;

                        k++;
                        l--;
                    }
                    else if (sum > targ)
                        l--;
                    else
                        k++;
                }
            }
        }
        return ans;
    }