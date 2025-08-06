//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // TC:O(N*LogN)
    // SC:O(N)
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {

        // Your code here
        // declaring a min heap for the elements in the array
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);

        long long ans = 0;

        while (pq.size() != 1)
        {

            // selecting the 2 most smallest eleemtns int he list
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long sum = a + b;
            // updating the ans
            ans += sum;
            // pushing the sum of 2 smallest in the queue for the next sum

            pq.push(sum);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends