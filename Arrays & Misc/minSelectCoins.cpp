//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> deno = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> res;

        for (int i = 0; i < 10; i++)
        {
            while (N > 0 && deno[i] <= N) // to find the closest denomination to the Value
            {
                res.push_back(deno[i]);
                N -= deno[i]; // updating the value for the next count
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends