//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> arr)
    {
        // Your code goes here

        vector<int> ans;
        int i = 0, j = 0;

        // 		similarily to traverse up from down replace i with j

        for (j = 0; j < N; j++)
        {
            ans.push_back(arr[i][j]);
            int l = i;
            int m = j;
            while (m != 0)
            {
                l++;
                m--;
                ans.push_back(arr[l][m]);
            }
        }
        j = N - 1;
        for (int i = 1; i < N; i++)
        {
            ans.push_back(arr[i][j]);
            int x = i;
            int y = j;
            while (x != N - 1)
            {
                x++;
                y--;
                ans.push_back(arr[x][y]);
            }
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
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends