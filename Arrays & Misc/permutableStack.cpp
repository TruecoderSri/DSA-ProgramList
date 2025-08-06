//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {

        int i;
        queue<int> input;
        for (i = 0; i < N; i++)
        {
            input.push(A[i]);
        }
        queue<int> output;
        for (i = 0; i < N; i++)
        {
            output.push(B[i]);
        }

        stack<int> st;
        while (!input.empty())
        {
            int ele = input.front();
            input.pop();
            if (ele == output.front())
            {
                output.pop();
                while (!st.empty())
                {
                    if (st.top() == output.front())
                    {
                        st.pop();
                        output.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                st.push(ele);
            }
        }
        return (input.empty() && output.empty());
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends