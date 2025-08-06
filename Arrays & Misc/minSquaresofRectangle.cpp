//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// program to find min squares to cut the rectangles

class Solution
{
public:
    long long int gcd(long long int a, long long int b)
    {
        if (a == 0)
            return b;

        return gcd(b % a, a);
    }
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        vector<long long int> ans;
        long long int k = gcd(L, B);

        long long int n = (L * B) / (k * k);
        ans.push_back(n);
        ans.push_back(k);

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
        long long int L, B;
        cin >> L >> B;

        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends