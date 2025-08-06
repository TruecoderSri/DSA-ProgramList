//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        // as we need to sort both start and end array according to end time
        // we will store each work start and end time in a pair and put all these pairs in a vector
        //  note the change I changed start array as 'a' and end array as 'b'
        vector<pair<int, int>> vi;
        for (int i = 0; i < n; i++)
        {
            vi.push_back({end[i], start[i]});
        }
        int c = 1;
        sort(vi.begin(), vi.end());
        int prev = vi[0].first;
        for (int j = 1; j < n; j++)
        {
            if (vi[j].second > prev)
            {
                c++;
                prev = vi[j].first;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;

    // testcases
    cin >> t;
    while (t--)
    {
        // size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        // adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        // function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends