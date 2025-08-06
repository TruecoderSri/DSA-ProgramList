//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int transform(string A, string B)
    {
        // code here.

        int n = A.size();
        int m = B.size();
        int i = n - 1, j = m - 1;
        int c = 0; // stores the count of swaps or ops to be done
        if (n != m)
            return -1;

        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[A[i]]++;
            mp[B[i]]--;
        }
        for (int i = 0; i < n; i++)
        {

            if (mp[A[i]] != 0)
                return -1;
        }

        while (i >= 0)
        {
            if (A[i] == B[j])
            {
                i--;
                j--;
            }
            else
            {
                i--;
                c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.transform(A, B) << endl;
    }
}
// } Driver Code Ends