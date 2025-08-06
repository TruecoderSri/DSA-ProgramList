//{ Driver Code Starts
// Initial Template for C++

// for the problem of find the largest submatrix with equal 1's and 0's replace all the 0's in the matrix with 1's and create a temp matrix

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    pair<int, int> longestSumZeroIndex(vector<int> &arr)
    {
        unordered_map<long long, int> mp;
        mp[0] = -1;
        int l = 0, r = 0;
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (mp.count(sum))
            {
                if (i - mp[sum] > (r - l))
                {
                    l = mp[sum] + 1;
                    r = i + 1;
                }
            }
            else
            {
                mp[sum] = i;
            }
        }
        return {l, r};
    }
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> mat)
    {
        int R = mat.size();
        int C = mat[0].size();
        vector<vector<int>> ans;
        int left = 0, right = 0, up = 0, down = 0;
        for (int startc = 0; startc < C; startc++)
        {
            vector<int> sum(R, 0);

            for (int endc = startc; endc < C; endc++)
            {

                for (int r = 0; r < R; r++)
                {
                    sum[r] += mat[r][endc];
                }

                auto it = longestSumZeroIndex(sum);
                int l = it.first;
                int r = it.second;

                if ((endc - startc + 1) * (r - l) > (right - left) * (down - up))
                {
                    up = l;
                    down = r;
                    left = startc;
                    right = endc + 1;
                }
            }
        }
        for (int i = up; i < down; i++)
        {
            vector<int> temp;
            for (int j = left; j < right; j++)
            {
                temp.push_back(mat[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if (ans.size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[0].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends